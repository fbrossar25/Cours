#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "shared_memory.h"

#define N 10

static int shmid;

pthread_t thread1, thread2;

static pthread_mutex_t verrou1, verrou2;

void *lire(void *nom_du_thread)
{
	pthread_mutex_lock(&verrou1);
	size_t *shared_var = (size_t *) shmat(shmid, 0, 0);
	printf("\tLecture : %zu\n",*shared_var);
	for(size_t i=0; i<N; i++)
	{
		pthread_mutex_unlock(&verrou2);
		pthread_mutex_lock(&verrou1);
		printf("\tLecture : %zu\n",*shared_var);
	}
	pthread_exit(0);
}
void *ecrire(void *nom_du_thread)
{
	pthread_mutex_lock(&verrou2);
	printf("%x\n",shmid);
	size_t *shared_var = (size_t *) shmat(shmid, 0, 0);
	for(size_t i=0; i<N; i++)
	{
		*shared_var = i;
		printf("ecriture : %zu\n",*shared_var);
		pthread_mutex_unlock(&verrou1);
		sleep(1);
		pthread_mutex_lock(&verrou2);
	}
	printf("ecriture : %zu\n",*shared_var);
	pthread_mutex_unlock(&verrou1);
	pthread_exit(0);
}

int main()
{
	shmid = shmget(SHARED_ADDRESS, sizeof(size_t), 0777|IPC_CREAT);
	shmctl(shmid, IPC_RMID, NULL);//Cleaning shared memory at shmid
	pthread_mutex_init(&verrou1,NULL);
	pthread_mutex_init(&verrou2,NULL);
	pthread_mutex_lock(&verrou1);
	pthread_mutex_lock(&verrou2);
	pthread_create(&thread1,NULL,lire,NULL);
	pthread_create(&thread2,NULL,ecrire,NULL);
	pthread_mutex_unlock(&verrou2);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	shmctl(shmid, IPC_RMID, NULL);//Cleaning shared memory at shmid
	return 0;
}