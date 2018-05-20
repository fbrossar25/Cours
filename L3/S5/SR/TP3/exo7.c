#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 1)
	{
		fprintf(stderr, "Error : only one argument needed\n");
		exit(EXIT_FAILURE);
	}

	pid_t child = fork();

	if(child < 0)
	{
		perror("fork");
		fprintf(stderr, "Error : can't create child process\n");
		exit(EXIT_FAILURE);
	}

	if(child == 0)//PWD
	{
		execlp("pwd","pwd",NULL);
		exit(EXIT_FAILURE);
	}

	int status,ret;
	ret = wait(&status);
	if(ret == -1)
	{
		perror("wait");
		fprintf(stderr, "Error during wait\n");
		exit(EXIT_FAILURE);
	}
	/*
	if(WIFEXITED(status))
	{
		fprintf(stdout,"Le fils s'est terminé normalement avec le code de retour %x.\n",status);
	}
	*/

	child = fork();

	if(child < 0)
	{
		perror("fork");
		fprintf(stderr, "Error : can't create child process\n");
		exit(EXIT_FAILURE);
	}

	if(child == 0)//LS
	{
		execlp("ls","ls","-li",NULL);
		exit(EXIT_FAILURE);
	}

	ret = wait(&status);
	if(ret == -1)
	{
		perror("wait");
		fprintf(stderr, "Error during wait\n");
		exit(EXIT_FAILURE);
	}
	/*
	if(WIFEXITED(status))
	{
		fprintf(stdout,"Le fils s'est terminé normalement avec le code de retour %x.\n",status);
	}
	*/
	return 0;
}