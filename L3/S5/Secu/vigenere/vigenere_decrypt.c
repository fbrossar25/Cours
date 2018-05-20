#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage(){
	printf("Usage : vigenere_decrypt key\n");
	printf("\tkey : decrypt key\n");
	printf("\tplain text and decrpyt key must be in capitals\n");
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
	size_t i = 0, j = 0;
	while((i = fgetc(stdin)) != EOF)
	{
		unsigned char c = (unsigned char) i;
		if(isupper(c))
		{
			c = (unsigned char) ((((c  - 'A') - (argv[1][j % keySize] - 'A')) % 26) + 'A');
			if(c - 'A' < 0) c += 26;
			j++;
		}
		printf("%c", c);
	}
	return 0;
}