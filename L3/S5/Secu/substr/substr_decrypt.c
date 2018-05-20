#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void usage(){
	printf("Usage : vigenere_encrypt key\n");
	printf("\tkey : encrypt key\n");
	printf("\tplain text and encrypt key must be in capitals\n");
}

char *computeKey(const char *baseKey, size_t size)
{
	char *res = calloc(26,sizeof(char));
	size_t resSize = 0;
	bool presence;
	for(size_t i=0; i<size; i++)
	{
		presence = false;
		for(size_t j=0; j<i; j++)
		{
			if(res[j] == baseKey[i])
			{
				presence = true;
			}
		}
		if(!presence)
		{
			res[resSize] = (unsigned char) baseKey[i];
			resSize ++;
		}
	}
	bool presentChar[26];
	for(size_t i=0; i<26; i++)
	{
		presentChar[i] = false;
	}
	for(size_t i=0; i<resSize; i++)
	{
		presentChar[res[i] - 'A'] = true;
	}
	size_t j;
	for(size_t i=resSize; i<26; i++)
	{
		j = (res[i-1] - 'A');
		while(presentChar[j])
		{
			j = (j+1) % 26;
		}
		presentChar[j] = true;
		res[i] = j + 'A';
	}
	return res;
}

size_t indexOfChar(const char *str, size_t size, unsigned char c)
{
	for(size_t i=0; i<size; i++)
	{
		if(str[i] == c) return i;
	}
	return size;
}

int main(int argc, char *argv[])
{
	//Erreur paramètre
	if (argc != 2)
	{
		usage();
		return 1;
	}
	char *computedKey = computeKey(argv[1],strlen(argv[1]));
	size_t i = 0;
	while((i = fgetc(stdin)) != EOF)
	{
		unsigned char c = (unsigned char) i;
		printf("%c", isupper(c) ? (unsigned char)indexOfChar(computedKey,strlen(computedKey),c)+'A' : c);
	}
	free(computedKey);
	return 0;
}