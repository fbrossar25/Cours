#ifndef STRING_OP_H
#define STRING_OP_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//fonction renvoyant true si str1 est un anagramme de str2
//renvoi true si les memes lettres sont utilisées le meme nombre de fois, false sinon
bool string_are_anagrams(const char *str1, const char *str2);

//fonction permettant de dupliquer la chaine str
char *string_duplicate(const char *str);

//fonction triant la chaine char par ordre alphabétique
//tri par insertion adapté pour des chaines de caractères
void string_sort_letters(char *str);

#endif