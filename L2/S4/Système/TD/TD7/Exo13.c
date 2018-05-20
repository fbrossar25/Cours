#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#define PATH_MAX 128

int main(int argc, char *argv[])
{
	int fd = open("nohup.out",O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if(fd == -1){
		char path[PATH_MAX];
		snprintf(path,PATH_MAX,"%s/nohupe.out",getenv("HOME"));
		fd = open(path,O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	}

	dup2(fd,1);
	dup2(1,2);
	
	signal(SIGHUP, SIG_IGN);

	execvp(argv[1],&argv[1]);
	
	return EXIT_SUCCESS;
}