#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

int string_length(char *chaine);
int string_number_of_space(char *chaine);
void string_voyelle_remover(char *chaine);
bool isVoyelle(char c);
bool check_parenthesage(char *chaine);
bool isBinaryNumber(char *chaine);
int stringToBinary(char *chaine);


int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Il faut un parametre de type chaine.\n");
		return 1;
	}
	char *chaine = argv[1];
	printf("La chaine passee en argument est : \"%s\"\n",chaine);
	printf("Taille strlen : %zu\n",strlen(chaine));
	printf("Taille algo perso : %d\n",string_length(chaine));
	printf("Nombre d'espace dans la chaine : %d\n",string_number_of_space(chaine));
	printf("Chaine sans voyelle : \"");
	string_voyelle_remover(chaine);
	printf("\"\n");
	if(check_parenthesage(chaine)) printf("La chaine est bien parenthesee\n");
	else printf("La chaine n'est pas bien parenthesee\n");
	if(isBinaryNumber(chaine))printf("0b%s = %d\n",chaine,stringToBinary(chaine));
	return 0;
}

int string_length(char *chaine){
	int res = 0;
	while(chaine[res] != 0)res++;
	return res;
}

int string_number_of_space(char *chaine){
	int res = 0;
	int i = 0;
	while(chaine[i] != 0){
		if(isspace(chaine[i]))res++;
		i++;
	}
	return res;
}

void string_voyelle_remover(char *chaine){
	for(int i=0; i<string_length(chaine); i++){
		if(!isVoyelle(chaine[i]))printf("%c",chaine[i]);
	}
}

bool isVoyelle(char c){
	bool res = false;
	int i = 0;
	char voyelle[] = {'a','e','i','o','u','y'};
	do{
		if(c == voyelle[i]) res = true;
		i++;
	}while(!res && i<6);
	return res;
}

bool check_parenthesage(char *chaine){
	int nOuvrante = 0;
	int nFermante = 0;
	for(int i=0; i<string_length(chaine); i++){
		if(chaine[i] == '(') nOuvrante++;
		if(chaine[i] == ')') nFermante++;
	}
	return (nOuvrante == nFermante);
}

bool isBinaryNumber(char *chaine){
	bool res = true;
	int i = 0;
	do{
		if(chaine[i] != '0' && chaine[i] != '1') res = false;
		i++;
	}while(res && i < string_length(chaine));
	return res;
}

int stringToBinary(char *chaine){
	int res = 0;
	assert(string_length(chaine) <= sizeof(int));
	for(int i=0; i<string_length(chaine); i++){
		res = res << 1;
		if(chaine[i] == '1') res++;
	}
	return res;
}