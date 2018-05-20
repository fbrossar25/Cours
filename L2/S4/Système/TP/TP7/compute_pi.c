#define _POSIX_C_SOURCE 200809L

#define N 10000000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>


static long p;
static long i;
static pid_t child;
static int pipefd[2];

double get_double()
{
	return (double) rand() / (double) RAND_MAX;
}

void process_actions()
{
	if(child == 0)
	{
		write(pipefd[1], &p, sizeof(p));
		write(pipefd[1], &i, sizeof(i));
	}
	else
	{
		long p2,i2;
		read(pipefd[0], &p2, sizeof(p2));
		read(pipefd[0], &i2, sizeof(i2));
		printf("i = %ld\n",i);
		printf("i2 = %ld\n",i2);
		printf("p = %ld\n",p);
		printf("p2 = %ld\n",p2);
		p += p2;
		long n = i + i2;
		printf("PI = %lf\n",4.0 * ( (double)p / (double)n) );
	}
	close(pipefd[0]);
	close(pipefd[1]);
}

void compute_pi()
{
	srand(getpid());
	for(i = 0; i < N; ++i)
	{
		double x = get_double();
		double y = get_double();
		if(x*x + y*y < 1.0)
		{
			p++;
		}
	}
}

void biprocess_pi()
{
	pipe(pipefd);
	child = fork();

	if(child < 0)
	{
		perror("fork");
		fprintf(stderr, "Error : cannot fork\n");
		exit(EXIT_FAILURE);
	}

	if(child == 0)
	{
		compute_pi();
		process_actions();
	}
	else
	{
		compute_pi();
		process_actions();
	}
	close(pipefd[0]);
	close(pipefd[1]);
}

void SIGINT_handler(int sig)
{
	printf("\n");
	process_actions();
	exit(EXIT_SUCCESS);
}

void interrupted_pi()
{
	struct sigaction action;

	sigemptyset(&action.sa_mask);
	action.sa_handler = SIGINT_handler;
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL);

	biprocess_pi();
}

int main(int argc, char *argv[])
{
	interrupted_pi();
	return EXIT_SUCCESS;
}