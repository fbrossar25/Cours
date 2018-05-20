#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage(){
	printf("Usage : vigenere_encrypt key\n");
	printf("\tkey : encrypt key\n");
	printf("\tplain text and encrypt key must be in capitals\n");
}

int main(int argc, char *argv[])
{
	//Erreur paramètre
	if (argc != 2)
	{
		usage();
		return 1;
	}
	size_t keySize = strlen(argv[1]);//taille de la clé
	//printf("Key '%s' is %zu long",argv[1],keySize);
	size_t i = 0, j = 0;
	while((i = fgetc(stdin)) != EOF)
	{
		unsigned char c = (unsigned char) i;
		if(isupper(c))
		{
			c = (unsigned char) ((((c  - 'A') + (argv[1][j % keySize] - 'A')) % 26) + 'A');
			j++;
		}
		printf("%c", c);
	}
	return 0;
}