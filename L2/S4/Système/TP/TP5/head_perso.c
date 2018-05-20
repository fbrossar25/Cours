#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFSIZE 1024

int main(int argc, char **argv){
	if(argc > 4){
		fprintf(stderr,"Error : too much arguments (0 or 1 file only)\nUsage : ./head_perso [-n N] [file]\n");
		return EXIT_FAILURE;
	}
	int nbLignes = 10;
	bool argN = false;
	int i;
	FILE *file = stdin;
	for(i=1; i<argc; i++){
		if(strcmp(argv[i],"-n") == 0){//argument [-n N]
			if(!argN){
				argN = true;
				i++;
				nbLignes = atoi(argv[i]);
			}
			else{
				fprintf(stderr,"Error : multiple -n arguments forbidden\n");
				return EXIT_FAILURE;
			}
		}
		else{
			file = fopen(argv[i],"r");
		}
	}
	if(file == NULL){
		fprintf(stderr,"Error : unable to open file\n");
		return EXIT_FAILURE;
	}
	i = 0;
	int size;
	static char buf[BUFSIZE];
	while((fgets(buf,BUFSIZE,file) != NULL) && (i < nbLignes)){
		size = strlen(buf);
		fwrite(buf,sizeof(char),size,stdout);
		i++;
	}
	if(file != stdin) fclose(file);
	return EXIT_SUCCESS;
}