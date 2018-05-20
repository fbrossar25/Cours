#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	pid_t n = fork();
	if(n == 0){//FILS
		system("ps");
		printf("chez le fils %d\n",getpid());
		printf("processus pere %d\n",getppid());
	}
	else{//PERE
		wait(NULL);
		printf("chez le pere %d\n",getpid());
		printf("processus grand pere %d\n",getppid());
	}
	return 0;
}