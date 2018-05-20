/*
A compiler avec -D_POSIX_C_SOURCE=200809L
ou 
#define _POSIX_C_SOURCE 200809L
*/

#define _POSIX_C_SOURCE 200809L

#define PATH_MAX 64

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		fprintf(stderr, "Error : not enough arguments\n");
		fprintf(stderr, "Usage : ./cp source destination\n");
		return EXIT_FAILURE;
	}

	char *source = argv[1];
	char *dest = argv[2];
	int devNull = open("/dev/null", O_WRONLY);
	int pA[2];
	pipe(pA);
	if(fork() == 0)//cat
	{
		close(pA[0]);
		dup2(pA[1],1);
		execlp("cat","cat",source,NULL);
		exit(EXIT_FAILURE);
	}
	close(pA[1]);
	if(fork() == 0)//tee
	{
		dup2(0,pA[0]);
		dup2(devNull,1);
		execlp("tee","tee",dest,NULL); 
		exit(EXIT_FAILURE);
	}
	close(pA[0]);
	wait(NULL);
	wait(NULL);
	return EXIT_SUCCESS;
}