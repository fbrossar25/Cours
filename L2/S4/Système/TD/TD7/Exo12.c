#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc > 1){
		fprintf(stderr, "Error : not enough arguments\n");
		return EXIT_FAILURE;
	}
	struct timeval t1;
	if(gettimeofday(&t1,NULL) == -1){
		fprintf(stderr, "Error while getting time of day\n");
		return EXIT_FAILURE;
	}

	pid_t child = fork();

	if(child < 0){//la ça marche pas
		fprintf(stderr, "Error : can't create child process\n");
		return EXIT_FAILURE;
	}

	if(child == 0){//traitement du fils
		execvp(argv[1],&argv[1]);
		exit(EXIT_FAILURE);//si on arrive la, c pas bien
	}

	//on attend le fils
	wait(NULL);

	//traitement du père
	struct timeval t2;
	if(gettimeofday(&t2,NULL) == -1){
		fprintf(stderr, "Error while getting time of day\n");
		return EXIT_FAILURE;
	}

	long t = ((t2.tv_sec - t1.tv_sec) * 1000000) + (t2.tv_usec - t1.tv_usec);

	printf("duration of child process : %ld µs\n",t);
	return EXIT_SUCCESS;
}

