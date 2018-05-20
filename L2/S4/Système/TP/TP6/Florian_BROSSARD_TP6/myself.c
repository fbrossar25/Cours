#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *fileName = "myself.pid";
	pid_t PID = getpid();
	FILE *file = fopen(fileName,"w");
	if(file == NULL){
		fprintf(stderr, "Error : unable to open file '%s'\n", fileName);
		return EXIT_FAILURE;
	}
	fprintf(file,"%d\n",PID);
	fclose(file);
	return EXIT_SUCCESS;
}