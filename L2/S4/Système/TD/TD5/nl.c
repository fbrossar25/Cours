#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *file = stdin;
	if(argc == 2){
		file = fopen(argv[2],"r");
		if(file == NULL){
			fprintf(stderr, "No file\n");
			return EXIT_FAILURE;
		}
	}
	if(argc > 2){
		fprintf(stderr, "Too many arguments\n");
		return EXIT_FAILURE;
	}
	char buf; //buffer
	printf("1 ");
	int ln = 2;
	while(!feof(file)){
		fread(&buf,sizeof(char),1,file);
		fwrite(&buf,sizeof(char),1,stdout);
		if(buf == '\n'){
			printf("%d ",ln);
			ln++;
		}
	}
	if(file != stdin) fclose(file);
	return EXIT_SUCCESS;
}