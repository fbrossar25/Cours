#include <stdio.h>
#include <stdlib.h>

#define NMAX 1024

int main(int argc, char **argv){
	if(argc < 2)
	{
		fprintf(stderr, "Error : at least 1 file needed\n");
		return EXIT_FAILURE;
	}
	static char buf[NMAX];
	int nbR;
	FILE *pFile;
	for(int i=1; i<argc; i++)
	{
		pFile = fopen(argv[i],"r");
		if(pFile != NULL)
		{
			while(feof(pFile) == 0)
			{
				nbR=fread(buf,sizeof(char),NMAX,pFile);
				fwrite(buf,sizeof(char),nbR,stdout);
			}
			fclose(pFile);
		}
		else
		{
			fprintf(stderr,"Error : file \"%s\" not found\n",argv[i]);
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}