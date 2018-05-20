#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int no_fils, status = -1;
	printf("Je suis le processeur PERE %d\n",getpid());
	printf("N° du grand-pere %d\n",getppid());
	if((no_fils = fork()) == -1){
		printf("Je suis le PERE, impossible de cree le fils\n");
		exit(1);
	}
	if(no_fils != 0){
		printf("nous sommes chez le PERE : la creation du fils a resussi\n");
		printf("Je suis le PERE, le N° du fils est %d\n",no_fils);
		printf("Je suis le PERE, j'attends la fin de mon fils\n");
		wait(&status);
		printf("Je suis le PERE : fin du fils avec status %x\n",status);
		printf("Je suis le PERE : fin du processus PERE\n");
	}
	else{
		int no_proc = getpid(), pere_proc = getppid();
		printf("nous sommes chez le fils\n");
		printf("nous sommes chez le fils, mon num est %d\n",no_proc);
		printf("nous sommes chez le fils, num de mon pere est %d\n",pere_proc);
		sleep(5);
		printf("nous sommes chez le fils : fin du processus fils\n");
		exit(no_proc);
	}
}