#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void usage(){
	printf("Usage : caesar_decrypt n\n");
	printf("\tn : shift index\n");
	printf("\tcypher text must be in capitals\n");
}

int main (int argc, char *argv[]){

	//Erreur paramètre
	if (argc != 2){
		usage();
		return 1;
	}

	size_t index = atoi(argv[1]) % 26;

	if(index < 0) index *= -1;

	//lecture du texte chiffré sur l'entrée standard, sortie du texte clair sur la sortie standard
	size_t i;
	while((i = fgetc(stdin)) != EOF){
		unsigned char c = (unsigned char) i;
		printf("%c", (isupper(c)) ? (unsigned char) (((c - 'A' + 26 - index ) % 26) + 'A') : c);
	}
	return 0;
}