#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void usage(){
	printf("Usage : caesar_encrypt n\n");
	printf("\tn : shift index\n");
	printf("\tplain text must be in capitals\n");
}

int main (int argc, char *argv[]){

	//Erreur paramètre
	if (argc != 2){
		usage();
		return 1;
	}

	size_t index = atoi(argv[1]) % 26;

	if(index < 0) index *= -1;

	//lecture du texte claire sur l'entrée standard, sortie du texte chiffré sur la sortie standard
	size_t i;
	while((i = fgetc(stdin)) != EOF){
		unsigned char c = (unsigned char) i;
		printf("%c", (isupper(c)) ? (unsigned char) (((c - 'A' + index) % 26) + 'A') : c);
	}
	return 0;
}