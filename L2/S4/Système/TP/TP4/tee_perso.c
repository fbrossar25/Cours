#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NMAX 1024

int main(int argc, char **argv){
	if(argc < 2)
	{
		fprintf(stderr, "Error : no file given\n");
		return EXIT_FAILURE;
	}
	static char buf[NMAX];
	int nbR = 0;
	FILE *pFile;
	bool firstPass = true;
	while(fgets(buf,NMAX,stdin) != NULL)
	{
		nbR = strlen(buf);
		for(int i=1;i<argc;i++)
		{
			if(firstPass)pFile = fopen(argv[i],"w");
			else pFile = fopen(argv[i],"a");
			if(pFile != NULL)
			{
				fwrite(buf,sizeof(char),nbR,pFile);
				fclose(pFile);
			}
			else
			{
				fprintf(stderr,"Error : unable to open file \"%s\"\n",argv[i]);
				return EXIT_FAILURE;
			}
		}
		firstPass = false;
		fwrite(buf,sizeof(char),nbR,stdout);
		nbR = 0;
	}
	return EXIT_SUCCESS;
}