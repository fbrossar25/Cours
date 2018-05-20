#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <string.h>

//SIGTERM  = 15

int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		fprintf(stderr, "Error : not enough arguments\n");
		printf("Usage : ./kill -s SIGNAL <pid> ...");
		exit(EXIT_FAILURE);
	}

	if(strcmp(argv[1],"-s") != 0)
	{
		fprintf(stderr, "Error : -s must be the first arguments\n");
		printf("Usage : ./kill -s SIGNAL <pid> ...");
	}

	execvp("kill", &argv[0]);

	return EXIT_FAILURE;
}