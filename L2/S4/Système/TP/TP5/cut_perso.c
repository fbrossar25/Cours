#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFSIZE 1024

void error(size_t type);
void process(FILE *file, char separator, size_t field);
void displayField(char *s, char separator, size_t field);

int main(int argc, char **argv){
	//////////////////////////////////////
	//arguments number check
	if(argc < 3){
		error(0);
		return EXIT_FAILURE;
	}
	if(argc > 4){
		error(1);
		return EXIT_FAILURE;
	}
	//////////////////////////////////////
	//separator check
	char separator;
	if(strlen(argv[1]) == 1){
		separator = argv[1][0];
	}
	else{
		error(2);
		return EXIT_FAILURE;
	}
	//////////////////////////////////////
	//field check
	size_t field = atoi(argv[2]);
	if(field < 1){
		error(3);
		return EXIT_FAILURE;
	}
	//////////////////////////////////////
	//file check
	FILE *file = stdin;
	if(argc == 4){
		file = fopen(argv[3],"r");
	}
	if(file == NULL){
		error(4);
		return EXIT_FAILURE;
	}
	//////////////////////////////////////

	process(file,separator,field);

	if(file != stdin){
		fclose(file);
	}
	return EXIT_SUCCESS;
}

void error(size_t type){
	switch(type){
		case 0:{
			fprintf(stderr,"Error : not enough arguments.\n");
		}
		break;
		case 1:{
			fprintf(stderr,"Error : too much arguments.\n");
		}
		break;
		case 2:{
			fprintf(stderr,"Error : separator must be a character.\n");
		}
		break;
		case 3:{
			fprintf(stderr,"Error : field must be an integer > 0.\n");
		}
		break;
		case 4:{
			fprintf(stderr,"Error : Unable to open file.\n");
		}
		break;
	}
	fprintf(stderr,"Usage : ./cut_perso separator field [FILE]\n");
}

void process(FILE *file, char separator, size_t field){
	char *buf = calloc(BUFSIZE,sizeof(char));
	while(fgets(buf,BUFSIZE,file) != NULL){
		displayField(buf,separator,field);
	}
}

void displayField(char *s, char separator, size_t field){
	size_t currField = 1;
	size_t currChar = 0;
	while(currField != field && s[currChar] != '\0'){
		if(s[currChar] == separator){
			currField++;
		}
		currChar++;
	}
	while(s[currChar] != separator && s[currChar] != '\0'){
		fwrite(&s[currChar],sizeof(char),1,stdout);
		currChar++;
	}
	if(s[currChar] != '\0')printf("\n");
}