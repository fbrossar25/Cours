#define _POSIX_C_SOURCE 200809L

#define PARAMLEN_MAX 64

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int xargs(int argc, char *argv[]);

//////////////////////////////////////
int main(int argc, char *argv[])
{
	return xargs(argc,argv);
}
//////////////////////////////////////
//Question 16.1 : SIGALRM
//Question 16.2
void SIGALRM_handler(int sig)
{
	return ;
}

unsigned int sleep(unsigned int nb_sec)
{
	struct sigaction action;

	sigemptyset(&action.sa_mask);
	action.sa_handler = SIGALRM_handler;
	action.sa_flags = 0;
	sigaction(SIGALRM, &action, NULL);
	pause();
	return 0;
}
//////////////////////////////////////
//Question 17 : xargs
int xargs(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "Not enough arguments\n");
		return EXIT_FAILURE;
	}
	char **args = calloc(argc+1, sizeof(char*));
	for(size_t k=1; k<argc; ++k)
	{
		args[k-1] = argv[k];
	}
	char buf[PARAMLEN_MAX];
	size_t i = 0;
	while(!feof(stdin))
	{
		fread(&buf,sizeof(char),1,stdin);
		if(buf[i] == ' ' || feof(stdin))//fin  de paramètre
		{
			buf[i] = '\0';
			args[argc-1] = buf;
			args[argc] = NULL;
			pid_t child = fork();
			if(child < 0)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			if(child == 0)
			{
				execvp(args[0],args);
				exit(EXIT_FAILURE);
			}
			wait(NULL);
			i = 0;
		}
		else
		{
			i++;
		}
	}
	free(args);
	return EXIT_SUCCESS;
}
//////////////////////////////////////
//Question 18
int sleep_sort(int argc, char *argv[])
{
	for(int i=1; i<argc; i++)
	{
		int val = atoi(argv[i]);
		if(fork() == 0)
		{
			sleep(val);
			printf("%d\n",val);
			return EXIT_SUCCESS;
		}
	}
	for(int i=1; i<argc; i++)
	{
		wait(NULL);
	}
	return EXIT_SUCCESS;
}
/*
Question 18.3)
Problème de concurrence : l'OS ne garantie pas que ceux qui dorment moins longtemps finissent avant ceux qui dorment plus longtemps
*/