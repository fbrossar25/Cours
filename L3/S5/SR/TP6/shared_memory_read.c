#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shared_memory.h"

int main()
{
	//On ecrit dans 'x' dans la memoire partagee a l'adresse 200
	int shmid;
	shmid = shmget(SHARED_ADDRESS, 1, 0777|IPC_CREAT);
	char *pchar = (char *) shmat(shmid, 0, 0);
	printf("%c\n",*pchar);
	return EXIT_SUCCESS;
}