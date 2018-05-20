#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MOST_FREQUENT_LETTER 'E' //Lettre la plus fréquente de la langue cible (E en français et anglais)

#define TARGETED_IC 0.074 //IC de la langue cible

#define SIGMA 0.015 //Marge d'erreur

//Decryptage d'un chiffre de cesar sur une sous-chaine str formee des (i + n)-iemes lettres de str avec un index de depart k
size_t caesar_breakN(const char *str, size_t size, size_t n, size_t k)
{
	assert(str != NULL && size != 0);
	//Initialisation
	size_t upperCount = 0, i;
	size_t occurences[26];
	for(i=0; i<26; i++)
	{
		occurences[i] = 0;
	}
	//Lecture du texte chiffré et comptage des occurences de chaques lettres
	for(size_t i=k; i<size; i+=n)
	{
		unsigned char c = (unsigned char) str[i];
		occurences[c - 'A']++;
		upperCount++;
	}
	//Recherche de la lettre apparaissant le plus dans le texte, on suppose qu'elle remplace la lettre MOST_FREQUENT_LETTER
	size_t key = 0;
	for(i=1; i<26; i++)
	{
		if(occurences[i] > occurences[key]) key = i;
	}
	//Deduction de la clé
	if(key < (MOST_FREQUENT_LETTER - 'A'))//cas ou l'indice de la cle se trouve avant l'indice de la lettre MOST_FREQUENT_LETTER
	{
		key += ('Z' - MOST_FREQUENT_LETTER) + 1;
	}
	else//autres cas
	{
		key -= (MOST_FREQUENT_LETTER - 'A');
	}
	return key;
}

//Calcul de l'IC moyen des sous-chaines de str formees des (i + n)-iemes lettres de str
//size la taille de str, n le 'pas'
double computeIC(const char *str, size_t size, size_t n)
{
	assert(str != NULL && n > 0);
	double res = 0.0;
	size_t occurences[26];
	size_t k = size / n;//taille de la chaine a traiter
	for(size_t i=0; i<n; i++)
	{
		for(size_t j=0; j<26; j++)
		{
			occurences[j] = 0;
		}
		for(size_t j=0; j<=size; j+=n)
		{
			unsigned char c = (unsigned char) (str[j+i]);
			occurences[(size_t) (c - 'A')]++;
		}
		//Calcul
		for(size_t j=0; j<26; j++)
		{
			res += ((double) occurences[j] * (occurences[j]-1.0)) / ((double) k * (k - 1.0));
		}
	}
	return res / n;
}

//Retourne si x est compris dans [target , target+errorMargin]
bool isInErrorMargin(double x, double target, double errorMargin)
{
	//return(x >= (target - errorMargin) && x <= (target + errorMargin));
	return (x > (target - errorMargin) && x < (target + errorMargin));
}

//renvoie la taille supposee de la cle
size_t determinizeKeySize(const char *txt, size_t size)
{
	size_t keySize = 0;
	double IC;
	do
	{
		keySize++;
		IC = computeIC(txt,size,keySize);
	}while(!isInErrorMargin(IC, TARGETED_IC, SIGMA) && keySize < size);
	return keySize;
}

//Renvoie la chaine de caractere correspondant a la cle
//Une partie de la cle peu etre incorrext sur des textes de 300-400 caracteres
//ou avec un cle trop longue (par exemple pour la cle de chiffrement ANTICONSTITUTIONNELLEMENT, vigenere_break renvoie ANTICONSTITUTIENNELLEMENT)
//Probleme de precision dans caesar_breakN ?
char *determinizeKey(const char *txt, size_t txtSize, size_t keySize)
{
	assert(txt != NULL && txtSize > 0 && keySize > 0);
	char *key = calloc(keySize+1,sizeof(char));
	for(size_t i=0; i<keySize; i++)
	{
		key[i] = (unsigned char) (caesar_breakN(txt,txtSize,keySize,i) + 'A');
	}
	key[keySize] = '\0';
	return key;
}

int main(int argc, char const *argv[])
{
	size_t txtSize = 0,i,txtCapacity = 1024;
	char *cipherText = malloc(txtCapacity * sizeof(char));
	//Lecture de l'entree standard
	while((i = fgetc(stdin)) != EOF)
	{
		//Reallocation si besoin
		if(txtSize == txtCapacity)
		{
			char *tmp = malloc(txtCapacity * 2 *sizeof(char));
			memcpy(tmp,cipherText,txtSize);
			free(cipherText);
			cipherText = tmp;
			txtCapacity *= 2;
		}
		unsigned char c = (unsigned char) i;
		//Mise en memoire des caractere majuscule uniquement, en supposant que seuls les caracteres [A-Z] sont modifies lors du chiffrement
		if(isupper(c))
		{
			cipherText[txtSize] = c;
			txtSize++;
		}
	}
	if(txtSize == 0)
	{
		fprintf(stderr,"Cannot compute anything with a text of size 0\n");
		free(cipherText);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%s\n",determinizeKey(cipherText,txtSize,determinizeKeySize(cipherText,txtSize)));
	}	
	free(cipherText);
	return 0;
}