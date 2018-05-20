#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define PATH_MAX 128

int main(int argc, char *argv[])
{
	//on choisis execl car on a le chemin de /bin/sh
	//et que l'on sait créer un chaine de caractere avec tout les arguments

	if(argc < 2)
	{
		fprintf(stderr, "Error : not enough arguments\n");
		return EXIT_FAILURE;
	}

	char args[PATH_MAX];
	for(size_t i=1; i<argc; i++)
	{
		strcat(args,argv[i]);
		strcat(args," ");
	}
	
	printf("%s\n",args);
	pid_t child = fork();

	if(child < 0)
	{
		perror("fork");
		fprintf(stderr, "Error : cannot fork\n");
	}

	if(child == 0)
	{
		execl("/bin/sh","sh","-c",args);
		exit(EXIT_FAILURE);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}

	int status;
	int ret = wait(&status);

	if(ret == -1){
		perror("wait");
	}

	if(WIFEXITED(status)){
		fprintf(stdout,"Le fils s'est terminé normalement avec le code de retour %d.\n",WEXITSTATUS(status));
	}
	return WIFEXITED(status);
}