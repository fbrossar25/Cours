#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define BUFSIZE 1024
#define MAXFILES 32

void gestionComptage(size_t nFiles,char *files[],bool argC,bool argL);
size_t byteCount(FILE *file);
size_t lineCount(FILE *file);

int main(int argc, char **argv){
	bool argL = false;
	bool argC = false;
	char *files[MAXFILES];
	size_t nFiles = 0;
	for(size_t i=1; i<argc; i++){
		if(strcmp(argv[i],"-l") == 0){
			if(!argL){
				argL = true;
			}
			else{
				fprintf(stderr,"Error : multiple -l argument forbidden\n");
				return EXIT_FAILURE;
			}
		}
		else if(strcmp(argv[i],"-c") == 0){
			if(!argC){
				argC = true;
			}
			else{
				fprintf(stderr,"Error : multiple -c argument forbidden\n");
				return EXIT_FAILURE;
			}
		}
		else if(strcmp(argv[i],"-lc") == 0 || strcmp(argv[i],"-cl") == 0 ){
			if(!argC && !argL){
				argC = true;
				argL = true;
			}
			else{
				if(argC)fprintf(stderr,"Error : multiple -c argument forbidden\n");
				if(argL)fprintf(stderr,"Error : multiple -l argument forbidden\n");
				return EXIT_FAILURE;
			}
		}
		else{
			if(nFiles < MAXFILES){
				files[nFiles] = argv[i];
				nFiles++;
			}
			else{
				fprintf(stderr,"Error : too much file (%d max)\n",MAXFILES);
				return EXIT_FAILURE;
			}
		}
	}
	gestionComptage(nFiles,files,argC,argL);
	return EXIT_SUCCESS;
}

void gestionComptage(size_t nFiles,char *files[],bool argC,bool argL){
	FILE *file = stdin;
	bool both = !argC && !argL; 
	size_t i = 0;
	size_t lines,bytes;
	size_t totalL = 0;
	size_t totalB = 0;
	do{
		if(nFiles > 0){
			file = fopen(files[i],"r");
		}
		if(argL || both){//Comptage ligne
			lines = lineCount(file);
			totalL += lines;
			fprintf(stdout,"%zu ",lines);
		}
		if(argC || both){//Comptage octet
			bytes = byteCount(file);
			totalB += bytes;
			fprintf(stdout,"%zu ",bytes);
		}
		fprintf(stdout,"%s\n",files[i]);
		i++;
		if(file != stdin)fclose(file);
	}while(i < nFiles);
	if(nFiles > 1){
		if (argL || both)fprintf(stdout,"%zu ",totalL);
		else if (argC || both)fprintf(stdout,"%zu ",totalB);
		fprintf(stdout,"total\n");
	}
}

size_t byteCount(FILE *file){
	size_t res = 0, nbR;
	char *buf = calloc(BUFSIZE,1);
	while(!feof(file)){
		nbR = fread(buf,1,BUFSIZE,file);
		res += nbR;
	}
	free(buf);
	rewind(file);//retour au début du fichier
	return res;
}

size_t lineCount(FILE *file){
	size_t res = 0;
	char buf;
	while(!feof(file)){
		fread(&buf,sizeof(char),1,file);
		if(buf == '\n')res++;
	}
	rewind(file);//retour au début du fichier
	if(res > 0){
		res--;
	}
	return res;//res retourne toujours le nombre de ligne +1 sauf s'il est égal à 0 --> on décrémente res si res > 0
}