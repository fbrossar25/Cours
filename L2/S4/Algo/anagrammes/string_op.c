#include "string_op.h"

//fonction renvoyant true si str1 est un anagramme de str2
//renvoi true si les memes lettres sont utilisées le meme nombre de fois, false sinon
bool string_are_anagrams(const char *str1, const char *str2){
	char *s1 = string_duplicate(str1);
	char *s2 = string_duplicate(str2);
	string_sort_letters(s1);
	string_sort_letters(s2);

	bool res = (strcmp(s1,s2) == 0);
	free(s1);
	free(s2);
	return res;
}

//fonction permettant de dupliquer la chaine str
char *string_duplicate(const char *str){
	size_t sz = strlen(str) + 1;
	char *res = calloc(sz,sizeof(char));
	for(size_t i=0; i<sz; i++){
		res[i] = str[i];
	}
	return res;
}

//fonction triant la chaine char par ordre alphabétique
//tri par insertion adapté pour des chaines de caractères
void string_sort_letters(char *str){
	
	size_t length = strlen(str);
	char res[length];
	//on affecte le tableau res avec la chaines str afin d'éviter les problèmes de segmentations
	for(size_t i=0; i<length; i++){
		res[i] = str[i];
	}
	char c;
	size_t j;
	//tri par insertion
	for(size_t i=1; i<length; i++){
		c = res[i];
		j = i;
		while (j > 0 && res[j - 1] > c) {
			res[j] = res[j - 1];
			j--;
		}
		res[j] = c;
	}
	//on réaffecte la chaine str avec le tableau res qui est maintenant trié
	for(size_t i=0; i<length; i++){
		str[i] = res[i];
	}
	
}