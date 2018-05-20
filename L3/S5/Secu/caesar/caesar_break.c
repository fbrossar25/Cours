#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MOST_FREQUENT_LETTER 'E' //Lettre la plus fréquente de la langue cible (E en français et anglais)

//afficher les frequences et le nombres d'occurences pour chaque lettre ainsi que le nombre de lettre majuscule
//utilisée seulement avec le parametre -stuff
void displayStuff(size_t occurences[], size_t upperCount, size_t key){
	printf("\n\n==========STUFF==========\n\n");
	for(size_t i=0; i<26; i++){
		printf("%c : %zu times -> %lf percent\n",(unsigned char) ('A' + i), occurences[i],
													((double) occurences[i] / (double) upperCount) * 100.0);
	}
	printf("\nuppercase count : %zu",upperCount);
	printf("\n%c is replacing the letter E",(unsigned char) ('A' + key));
	printf("\n\n=========================\n\n\n");
}

int main (int argc, char *argv[]){
	//Initialisation
	size_t upperCount = 0, i;
	size_t occurences[26];
	for(i=0; i<26; i++){
		occurences[i] = 0;
	}

	//Lecture du texte chiffré et comptage des occurences de chaques lettres
	while((i = fgetc(stdin)) != EOF){
		unsigned char c = (unsigned char) i;
		occurences[c - 'A']++;
		upperCount++;
	}

	//Recherche de la lettre apparaissant le plus dans le texte, on suppose qu'elle remplace la lettre MOST_FREQUENT_LETTER
	size_t key = 0;
	for(i=1; i<26; i++){
		if(occurences[i] > occurences[key]) key = i;
	}

	//Affichage optionnel d'informations
	if(argc > 1 && (strcmp(argv[1],"-stuff") == 0)){
		displayStuff(occurences, upperCount, key);
	}

	//Deduction et affichage de la clé
	if(key < (MOST_FREQUENT_LETTER - 'A')){//cas ou l'indice de la cle se trouve avant l'indice de la lettre MOST_FREQUENT_LETTER
		key = key + ('Z' - MOST_FREQUENT_LETTER) + 1;
	}
	else {//autres cas
		key = key - (MOST_FREQUENT_LETTER - 'A');
	}

	printf("Key = %zu\n",key);

	return 0;
} 
