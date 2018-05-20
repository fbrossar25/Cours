/*
A compiler avec -D_POSIX_C_SOURCE=200809L
ou 
#define _POSIX_C_SOURCE 200809L
*/

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

static size_t SIGINT_max;

void SIGINT_handler(int sig)
{
	static size_t sigint_count = 0;
	sigint_count++;
	if(sigint_count < SIGINT_max){
		printf("boom!\n");
		alarm(5);
	}
	else{
		printf("KABOOM!!\n");
		exit(EXIT_SUCCESS);
	}
}

void SIGALRM_handler(int sig)
{
	static size_t sheep = 0;
	sheep++;
	printf("%zu\n",sheep);
}

int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Error : not enough arguments\n");
		return EXIT_FAILURE;
	}

	SIGINT_max = atoi(argv[1]);

	struct sigaction action;

	sigemptyset(&action.sa_mask);
	action.sa_handler = SIGINT_handler;
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL);

	action.sa_handler = SIGALRM_handler;
	sigaction(SIGALRM, &action, NULL);

	//printf("pid = %d",getpid());

	while(1){
		alarm(1);
		pause();
	}


	return EXIT_SUCCESS;
}