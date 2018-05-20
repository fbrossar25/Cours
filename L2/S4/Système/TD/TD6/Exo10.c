#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
	if(argc > 2)
	{
		fprintf(stderr,"Error : too much arguments\n");
		return EXIT_FAILURE;
	}
	FILE *file = stdin;
	if(strcmp(argv[1],"-") != 0)
	{
		file = fopen(argv[1],"r");
		if(file == NULL)
		{
			fprintf(stderr,"Error : unable to open file \"%s\"\n",argv[1]);
			return EXIT_FAILURE;
		}
	}
	char buf[BUFSIZE];
	size_t nbR;
	while(!feof(file))
	{
		nbR = fread(buf,sizeof(char),BUFSIZE,file);
		for(size_t i=0; i<nbR; i++)
		{
			if(buf[i] == '\t')
			{
				fwrite("    ",sizeof(char),4,stdout);
			}
			else
			{
				fwrite(&buf[i],sizeof(char),1,stdout);
			}
		}
	}
	if(file != stdin)
	{
		fclose(file);
	}
	return EXIT_SUCCESS;
}