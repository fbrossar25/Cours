#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

#define SIGMA_PERCENT 0.05

char find_E_substitute(const char *cipherText, size_t txtSize)
{
	size_t occurences[26];
	for(size_t i=0; i<26; i++)
	{
		occurences[i] = 0;
	}

	for(size_t i=0; i<txtSize; i++)
	{
		occurences[cipherText[i] - 'A']++;
	}
	size_t maxIndex = 0;
	for(size_t i=1; i<26; i++)
	{
		if(occurences[i] > occurences[maxIndex]) maxIndex = i;
	}
	return maxIndex + 'A';
}

void replace_key_char(char key[26], char target, char substitute)
{
	assert(target >= 'A' && target <= 'Z');
	assert(substitute >= 'A' && substitute <= 'Z');
	if(target != substitute)
	{
		key[target - 'A'] = substitute;
	}
}

char *compute_key(const char key[26])
{
	bool computed[26];
	char *computed_key = calloc(26, sizeof(char));
	for(size_t i=0; i<26; i++)
	{
		computed[i] = false;
	}
	for(size_t i=0; i<26; i++)
	{
		if(key[i] != '*')
		{
			computed[key[i] - 'A'] = true;
		}
	}
	for(size_t i=0; i<26; i++)
	{
		if(key[i] == '*')
		{
			size_t j=0;
			while(j<26 && computed[j])
			{
				j++;
			}
			if(j < 26)
			{
				computed_key[i] = 'A' + j;
				computed[j] = true;
			}
		}
		else
		{
			computed_key[i] = key[i];
		}
	}
	return computed_key;
}

void call_substr_decrypt(const char key[26])
{
	//substr_decrypt ABCDEFGHIJKLMNOPQRSTUVWXYZ < ciphertext
	char cmd[54];
	char * key_str = calloc(27, sizeof(char));
	for(size_t i=0; i<26; i++)
	{
		key_str[i] = key[i];
	}
	key_str[26] = '\0';
	sprintf(cmd,"./substr_decrypt %s < ciphertext",key_str);
	free(key_str);
	system(cmd);
	printf("\n");
}

void print_key(const char key[26])
{
	for(size_t i=0; i<26; i++)
	{
		printf("%c",key[i]);
	}
	printf("\n");
}

void find_one_letter_word(const char *cipherTextFull, size_t size, char key[26])
{
	char word1 = '\0', word2 = '\0';
	size_t i = 0;
	if(isupper(cipherTextFull[0]) && cipherTextFull[1] == ' ') word1 = cipherTextFull[0];
	while(i < size && (word1 == '\0' || word2 == '\0'))
	{
		if(isupper(cipherTextFull[i]) && cipherTextFull[i - 1] == ' ' && cipherTextFull[i + 1] == ' ')//Mot de une lettre entoure de deux espace
		{
			if(word1 == '\0' && cipherTextFull[i] != word2)
			{
				word1 = cipherTextFull[i];
			}
			else if(word2 == '\0' && cipherTextFull[i] != word1)
			{
				word2 = cipherTextFull[i];
			}
		}
		i++;
	}
	if(word1 != '\0' && word2 != '\0')
	{
		size_t word1Count = 0, word2Count = 0;
		for(i=0; i<size; i++)
		{
			if(cipherTextFull[i] == word1) word1Count++;
			if(cipherTextFull[i] == word2) word2Count++;
		}
		if(word1Count != word2Count)
		{
			printf("find_one_letter_word() found that '%c' replace 'A' and '%c' replace 'Z'\n",(word1Count > word2Count) ? word1 : word2, (word1Count > word2Count) ? word2 : word1);
			replace_key_char(key,'A',(word1Count > word2Count) ? word1 : word2);//la lettre apparaissant le plus remplace 'A'
			replace_key_char(key,'Y',(word1Count > word2Count) ? word2 : word1);//la lettre apparaissant le moins remplace 'Y'
			return;
		}
	}
	else if (word1 != '\0')
	{
		size_t word1Count = 0;
		for(i=0; i<size; i++)
		{
			if(cipherTextFull[i] == word1) word1Count++;
		}
		double word1Freq = ((double)word1Count / size);
		if(word1Freq < 0.01)//word1 est surement Y
		{
			printf("find_one_letter_word() found that '%c' replace 'Y'\n",word1);
			replace_key_char(key,'Y',word1);
			return;
		}
		else//word1 est surement A
		{
			printf("find_one_letter_word() found that '%c' replace 'A'\n",word1);
			replace_key_char(key,'A',word1);
			return;
		}
	}
	printf("find_one_letter_word() cannot find substitute for A and Z\n");
}

size_t match_index_char(char c, const char array[], size_t size)
{
	for(size_t i=0; i<size; i++)
	{
		if(c == array[i]) return i;
	}
	return size;
}

//Retourne si x est compris dans [target , target+errorMargin]
bool isInErrorMargin(double x, double target, double errorMargin)
{
	//return(x >= (target - errorMargin) && x <= (target + errorMargin));
	return (x > (target - errorMargin) && x < (target + errorMargin));
}

/*
//Un mot d’une lettre devant une apostrophe est, dans l'ordre : S, N, T, L, D, C, M, J
void find_letter_before_apostrophe(const char *cipherTextFull, size_t size, char key[26])
{
	double knownLettersFreqs[8] = {0.0808, 0.0713, 0.0707, 0.0601, 0.0418, 0.0303, 0.0296, 0.0031};
	char knownLetters[8] = {'S', 'N', 'T', 'L', 'D', 'C', 'M', 'J'};
	char possibleLetters[8] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
	size_t occurences[8] = {0,0,0,0,0,0,0,0};
	size_t possibleLettersEncounter = 0;
	if(isupper(cipherTextFull[0]) && cipherTextFull[1] == '\'')
	{
		possibleLetters[0] = cipherTextFull[0];
		if(match_index_char(cipherTextFull[0],possibleLetters,8) >= 8)
		{
			possibleLetters[possibleLettersEncounter] = cipherTextFull[0];
			possibleLettersEncounter++;
		}
	}
	for(size_t i=1; i<size; i++)
	{
		if(isupper(cipherTextFull[i]) && cipherTextFull[i-1] == ' ' && cipherTextFull[i+1] == '\'')//Mot a ue seule lettre devant une apostrophe
		{
			if(match_index_char(cipherTextFull[0],possibleLetters,8) >= 8)//Si le mot n'a pas encore ete rencontre
			{
				possibleLetters[possibleLettersEncounter] = cipherTextFull[i];
				possibleLettersEncounter++;
			}
		}
		if(possibleLettersEncounter >= 8)break;
	}

	for(size_t i=0; i<size; i++)
	{
		if(cipherTextFull[i] == possibleLetters[0]) occurences[0]++;
		else if(cipherTextFull[i] == possibleLetters[1]) occurences[1]++;
		else if(cipherTextFull[i] == possibleLetters[2]) occurences[2]++;
		else if(cipherTextFull[i] == possibleLetters[3]) occurences[3]++;
		else if(cipherTextFull[i] == possibleLetters[4]) occurences[4]++;
		else if(cipherTextFull[i] == possibleLetters[5]) occurences[5]++;
		else if(cipherTextFull[i] == possibleLetters[6]) occurences[6]++;
		else if(cipherTextFull[i] == possibleLetters[7]) occurences[7]++;
	}
	bool substitueFound = false;
	if(possibleLettersEncounter > 0)
	{
		char possibleSubstitute[possibleLettersEncounter];
		for(size_t j=0; j<possibleLettersEncounter; j++)
		{
			possibleSubstitute[j] = '\0';
		}
		for(size_t i=0; i<possibleLettersEncounter; i++)
		{
			if(possibleLetters[i] == '\0') break;
			for(size_t j=0; j<8; j++)
			{
				double freq = (double)occurences[i] / size;
				if(isInErrorMargin(freq, knownLettersFreqs[j], knownLettersFreqs[j] * SIGMA_PERCENT))
				{
					printf("'%c' (%lf) is near '%c'(%lf)!\n",possibleLetters[i],freq,knownLetters[j],knownLettersFreqs[j]);
					size_t index = match_index_char(possibleLetters[i], possibleSubstitute, 8);
					if(index < 8)//deja suppose
					{
						printf("'%c' was already supposed for '%c', skipping\n",possibleLetters[i],knownLetters[j]);
						possibleSubstitute[index] = '\0';
						break;
					}
					else
					{
						possibleSubstitute[j] = possibleLetters[i];
						printf("'%c' was placed in %zu\n",possibleLetters[i],j);
					}
				}
			}
		}
		for(size_t i=0; i<8; i++)
		{
			if(possibleSubstitute[i] != '\0')
			{
				substitueFound = true;
				printf("find_letter_before_apostrophe() found that '%c' replace '%c'\n",possibleSubstitute[i],knownLetters[i]);
				replace_key_char(key,knownLetters[i],possibleSubstitute[i]);
			}
		}
	}
	if(!substitueFound)printf("find_letter_before_apostrophe() cannot find any substitue\n");	
}
*/

/*
//Les lettre les doubles les plus frequentes sont E, M, L, N, F, T et C
//on suppose que le E est deja trouve
void find_double_letters(const char *cipherTextFull, size_t size, char key[26])
{
	
}
*/

//Tentative de trouver les 5 lettres les plus frequentes apres E et A
//S, I, N, T, R
void frequency_analysis_top5(char *cipherTextFull, size_t size, char key[26])
{
	size_t occurences[26];
	for(size_t i=0; i<26; i++)
	{
		occurences[i] = 0;
	}

	for(size_t i=0; i<size; i++)
	{
		occurences[cipherTextFull[i] - 'A']++;
	}

	//Elimination de E et A
	size_t index = 0;
	for(size_t i=1; i<26; i++)
	{
		if(occurences[i] > occurences[index]) index = i;
	}
	occurences[index] = 0;
	index = 0;
	for(size_t i=1; i<26; i++)
	{
		if(occurences[i] > occurences[index]) index = i;
	}
	occurences[index] = 0;

	size_t top5Indexs[5] = {0,0,0,0,0};
	for(size_t i=0; i<5; i++)
	{
		for(size_t j=1; j<26; j++)
		{
			if(occurences[j] > occurences[top5Indexs[i]]) top5Indexs[i] = j;
		}
		occurences[top5Indexs[i]] = 0;
	}
	printf("frequency_analysis_top5() found that '%c' replace '%c'\n",(unsigned char)('A'+top5Indexs[0]),'S');
	replace_key_char(key,'S',(unsigned char)('A'+top5Indexs[0]));
	printf("frequency_analysis_top5() found that '%c' replace '%c'\n",(unsigned char)('A'+top5Indexs[1]),'I');
	replace_key_char(key,'I',(unsigned char)('A'+top5Indexs[1]));
	printf("frequency_analysis_top5() found that '%c' replace '%c'\n",(unsigned char)('A'+top5Indexs[2]),'N');
	replace_key_char(key,'N',(unsigned char)('A'+top5Indexs[2]));
	printf("frequency_analysis_top5() found that '%c' replace '%c'\n",(unsigned char)('A'+top5Indexs[3]),'T');
	replace_key_char(key,'T',(unsigned char)('A'+top5Indexs[3]));
	printf("frequency_analysis_top5() found that '%c' replace '%c'\n",(unsigned char)('A'+top5Indexs[4]),'R');
	replace_key_char(key,'R',(unsigned char)('A'+top5Indexs[4]));
}

size_t menu()
{
	printf("1) Remplacer une lettre\n");
	printf("2) Entrer une cle\n");
	printf("3) Quitter\n");
	printf("Votre choix ? ");
	char str[2];
	fflush(stdin);
	fgets(&str[0],2,stdin);
	int choix = atoi(&str[0]);
	if(choix < 1 || choix > 3) exit(EXIT_SUCCESS);//Evite de se retrouver avec une boucle infinis
	printf("\n");
	return choix;
}

int main(int argc, char const *argv[])
{
	size_t fullCount, uppersCount = fullCount = 0, i, fullCapacity, uppersCapacity = fullCapacity = 1024;
	char *cipherTextUppers = malloc(uppersCapacity * sizeof(char));
	char *cipherTextFull = malloc(fullCapacity * sizeof(char));
	//Lecture de l'entree standard
	while((i = fgetc(stdin)) != EOF)
	{
		//Reallocation si besoin
		if(uppersCount == uppersCapacity)
		{
			cipherTextUppers = realloc(cipherTextUppers,uppersCapacity * 2);
			uppersCapacity *= 2;
		}
		if(fullCount == fullCapacity)
		{
			cipherTextFull = realloc(cipherTextFull,fullCapacity * 2);
			fullCapacity *= 2;
		}
		unsigned char c = (unsigned char) i;
		cipherTextFull[fullCount] = c;
		fullCount++;
		if(isupper(c))
		{
			cipherTextUppers[uppersCount] = c;
			uppersCount++;
		}
	}
	if(uppersCount == 0)
	{
		fprintf(stderr,"Cannot compute anything with a text of size 0\n");
		free(cipherTextUppers);
		exit(EXIT_FAILURE);
	}
	char key[26];
	for(size_t i=0; i<26; i++)
	{
		key[i] = '*';
	}
	char c = find_E_substitute(cipherTextUppers,uppersCount);
	printf("%c is the substitute of E\n",c);
	if(c != 'E')
	{
		replace_key_char(key,'E',c);
	}
	find_one_letter_word(cipherTextFull, fullCount, key);
	frequency_analysis_top5(cipherTextFull, fullCount, key);
	//Fonctionnel jusque la
	printf("Possible key is : ");
	char *computed_key = compute_key(key);
	print_key(computed_key);
	//printf("\n\n");
	//find_letter_before_apostrophe(cipherTextFull, fullCount, key);
	printf("\n\nPossible key is : ");
	computed_key = compute_key(key);
	print_key(computed_key);
	printf("\n\n");
	call_substr_decrypt(computed_key);
	bool run = true;
	while(run){
		switch(menu())
		{
			case 1:
			{
				char target,substitute;
				printf("Lettre a remplacer : ");
				target = fgetc(stdin);
				if(target < 'A' || target > 'Z')
				{
					printf("Erreur de saisie.\n");
					break;
				}
				printf("\nLettre remplacante : ");
				substitute = fgetc(stdin);
				if(substitute < 'A' || substitute > 'Z')
				{
					printf("Erreur de saisie.\n");
					break;
				}
				replace_key_char(key,target,substitute);
				call_substr_decrypt(computed_key);
				printf("\n\n");
			}
			break;

			case 2:
			{
				char newKey[26];
				printf("Entrez la nouvelle cle (majuscules ou '*' seulement): ");
				fgets(&newKey[0], 26, stdin);
				for(size_t i=0; i<26; i++)
				{
					if(isupper(newKey[i]))
					{
						key[i] = newKey[i];
					}
					else
					{
						key[i] = '*';
					}
				}
			}
			break;

			case 3:
			{
				printf("Arret du programme...\n");
				run = false;
			}

			default:
			{
				printf("Choix non disponible.\n");
			}
		}
	}
	free(computed_key);
	free(cipherTextUppers);
	free(cipherTextFull);
	return 0;
}