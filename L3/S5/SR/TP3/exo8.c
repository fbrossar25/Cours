#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int a = 5, b = 10;
	pid_t child = fork();
	if(child < 0)
	{
		perror("fork");
		fprintf(stderr,"Canot create child process\n");
		exit(EXIT_FAILURE);
	}
	else if(child == 0)
	{
		int y = b * b;
		printf("child y = %d\n",y);
		int d2 = creat("fifi", 0666);
		write(d2, &y, sizeof(y));
		close(d2);
	}
	else
	{
		wait(NULL);
		int d1 = open("fifi",0);
		int x = a * a,y;
		read(d1,&y,sizeof(y));
		close(d1);
		int z = x + y;
		printf("father z = %d + %d = %d\n",x,y,z);
	}
	return 0;
}