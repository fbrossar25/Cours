#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NMAX 64

void erreur(int type);
void help();
bool verifArgO(char *param);
void display(int c, int f, char *inputs[], char *output);

int main(int argc, char *argv[]){
	int c=0,o=0,f=0;
	//c et o représentent le nombre d'argument -c et -o passés sachant qu'on n'autorisent qu'un seul de chaque
	//f représente le nombre de fichier d'entrés, ceux-ci sont stockés dans le tableau tabFile
	char *tabFile[NMAX];
	char *output = "a.out";
	for(int i=1; i<argc; i++){
		if(strcmp(argv[i],"-h") == 0){//argument -h
			help();
			return 0;
		}
		else if(strcmp(argv[i],"-c") == 0){//argument -c
			if(c == 0) c++;
			else{
				erreur(1);
				return 1;
			}
		}
		else if(strcmp(argv[i],"-o") == 0){//argument -o
			if(o == 0){
				if(verifArgO(argv[i+1])){
					output = argv[i+1];
					i++;
					o++;
				}
				else{
					erreur(3);
					return 1;
				}
			}
			else{
				erreur(2);
				return 1;
			}
		}
		else if(f>NMAX){//si plus de 64 fichiers en arguments
			erreur(0);
			return 1;
		}
		else{//fichier
			tabFile[f] = argv[i];
			f++;
		}
	}
	display(c, f, tabFile, output);
	return 0;
}

void erreur(int type){//on récupère un code d'erreur, on affiche sa signification puis l'aide
	switch(type){
		case 0: fprintf(stderr,"Error: max file number (%d) reached\n",NMAX);//on donne plus de NMAX arguments
		break;
		case 1: fprintf(stderr,"Error: Multiple -c arguments forbidden\n");//on donne l'argument -c plus d'une fois
		break;
		case 2: fprintf(stderr,"Error: Multiple -o arguments forbidden\n");//on donne l'argument -o plus d'une fois
		break;
		case 3: fprintf(stderr,"Error: No output given after -o\n");//on donne l'argument -o sans le faire suivre par un nom de fichier
		break;
		default:;
	}
	help();
}

void help(){//affichage de l'aide
	printf("Usage: mycc [-h] [-c] [-o output] [files...]\n");
}

bool verifArgO(char *arg){//on vérifie que arg est un nom de fichier donc différent de -o, -h et -c
	return ((arg != NULL) && (strcmp(arg,"-h") != 0) && (strcmp(arg,"-o") != 0) && (strcmp(arg,"-c") != 0));
}

void display(int c, int f, char *inputs[], char *output){//on affiche le résultat de la commande
	if(c == 1)printf("	compile: yes\n");
	else printf("	compile: no\n");
	printf("	output: %s\n",output);
	printf("	inputs:\n");
	if(f == 0) printf("		standard input\n");
	else{
		for(int i=0; i<f; i++){
			if(inputs[i] != NULL)printf("		file: %s\n",inputs[i]);
		}
	}
}