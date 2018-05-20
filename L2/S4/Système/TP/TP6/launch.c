#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc <= 1){
		fprintf(stderr, "Error : not enough arguments\n");
		exit(EXIT_FAILURE);
	}
	struct timeval t1;
	if(gettimeofday(&t1,NULL) == -1){
		fprintf(stderr, "Error while getting time of day\n");
		exit(EXIT_FAILURE);
	}

	pid_t child = fork();

	if(child < 0){//erreur
		perror("fork");
		fprintf(stderr, "Error : can't create child process\n");
		exit(EXIT_FAILURE);
	}

	if(child == 0){//traitement du fils
		execvp(argv[1],&argv[1]);
		exit(EXIT_FAILURE);//si on arrive la, erreur
	}

	int status;

	//on attend le fils
	int ret = wait(&status);

	if(ret == -1){
		perror("wait");
	}

	if(WIFEXITED(status)){
		fprintf(stdout,"Le fils s'est terminé normalement avec le code de retour %d.\n",WEXITSTATUS(status));
	}

	//traitement du père
	struct timeval t2;
	if(gettimeofday(&t2,NULL) == -1){
		fprintf(stderr, "Error while getting time of day\n");
		exit(EXIT_FAILURE);
	}

	long t = ((t2.tv_sec - t1.tv_sec) * 1000000) + (t2.tv_usec - t1.tv_usec);

	printf("duration of child process : %ld µs\n",t);
	exit(EXIT_SUCCESS);
}