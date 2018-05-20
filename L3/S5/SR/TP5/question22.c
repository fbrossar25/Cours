#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
/* programme mutexL3.c - mise en evidence de la synchronisation  */

pthread_t pthread_id[2];

pthread_mutex_t mutex1, mutex2;
int status;

void *f_thread_1(void *ptr)
{
	pthread_mutex_lock(&mutex1);
	printf("je suis le pthread 1 \n");
	pthread_exit(0);
}

void *f_thread_2(void *ptr)
{
	pthread_mutex_lock(&mutex2);
	sleep(2);
	printf("je suis le pthread 2 \n");
	pthread_exit(0);
}

int main()
{
	pthread_mutex_init(&mutex1,NULL);
	pthread_mutex_init(&mutex2,NULL);
	pthread_mutex_lock(&mutex1);
	pthread_mutex_lock(&mutex2);

	// création des 2 threads
	pthread_create(&pthread_id[0],NULL,f_thread_1,NULL);
	pthread_create(&pthread_id[1],NULL,f_thread_2,NULL);
	printf("les pthread 1 et 2 sont creees \n");
	// on exécute le thread 2
	pthread_mutex_unlock(&mutex2);
	pthread_join(pthread_id[1],NULL);
	printf("Le thread 2 est termine\n");
	// on exécute le thread 1
	pthread_mutex_unlock(&mutex1);	
	pthread_join(pthread_id[0],NULL);
	printf("Le thread 1 est termine\n");
	return 0;
}