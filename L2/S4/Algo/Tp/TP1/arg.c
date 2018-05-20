#include "stdio.h"
#include "stdlib.h"

int main (int argc, char *argv[]){
	if (argc != 2){
		printf("Un argument est nécessaire !");
		return 1;
	}

	int arg = atoi(argv[1]);
	/*
	la fonction atoi permet de convertir une chaine de
	caractere en entier à condition qu'il y ai un entier dedans sinon retourne 0
	*/
	printf("L'argument est %d \n",arg);
	return 0;
}