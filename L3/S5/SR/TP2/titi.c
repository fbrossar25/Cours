#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("processus numero %d\n",getpid());
	printf("processus pere %d\n",getppid());
	return 0;
}