#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
	size_t n = 4;//nombre de caracteres à lire
	if(argc < 2)
	{
		fprintf(stderr,"Error : no file given\n");
		return EXIT_FAILURE;
	}
	else if(argc > 4)
	{
		fprintf(stderr,"Error : too much arguments\n");
		return EXIT_FAILURE;
	}
	FILE *file;
	size_t idx;
	if(strcmp(argv[1],"-n") == 0)
	{
		n = atoi(argv[2]);
		idx = 3;
	}
	else
	{
		idx = 1;
	}
	if(argv[idx] == NULL)
	{
		fprintf(stderr,"Error : no file given\n");
		return EXIT_FAILURE;
	}
	file = fopen(argv[idx],"r");
	if(file == NULL)
	{
		fprintf(stderr,"Error : unable to open file \"%s\"\n",argv[idx]);
		return EXIT_FAILURE;
	}

	char buf[BUFSIZE];
	char *str = calloc(BUFSIZE,sizeof(char));
	size_t count = 0;
	size_t nbR;
	while(!feof(file))
	{
		nbR = fread(&buf,sizeof(char),BUFSIZE,file);
		for(size_t i=0; i<nbR; i++)
		{
			if(isprint(buf[i]))
			{
				if(count < n)
				{
					str[count] = buf[i];
					count++;
					if(count == n)
					{
						fwrite(str,sizeof(char),count,stdout);
					}
				}
				else
				{
					count++;
					fwrite(&buf[i],sizeof(char),1,stdout);
				}
			}
			else
			{
				if(count >= n)
				{
					fprintf(stdout,"\n");
				}
				count = 0;
			}
		}
	}
	free(str);
	fclose(file);
	return EXIT_SUCCESS;
}