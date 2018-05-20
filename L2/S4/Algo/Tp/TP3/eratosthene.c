#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int *array_new(size_t size);
void displayArray(int *data,int size);
void cribleEratosthene(int *data, int size);
void displayPremiers(int *data,int size);
void cribleEratostheneOpti(int *data,int size);

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Il faut un parametre entier > 2!\n");
		return 1;
	}
	int n = atoi(argv[1]);
	if(n < 3){
		printf("Il faut un parametre entier > 2!\n");
		return 1;
	}
	int *is_prime = array_new(n);
	/*
	printf("Etat avant le crible d'Eratosthene :\n");
	displayArray(is_prime,n);
	*/
	cribleEratostheneOpti(is_prime,n);
	/*
	printf("Etat apres le crible d'Eratosthene :\n");
	displayArray(is_prime,n);
	*/
	printf("Nombres premiers < %d :\n",n);
	displayPremiers(is_prime,n);
	return 0;
}

int *array_new(size_t size){
	assert(size > 2);
	int *data = calloc(size,sizeof(size_t));
	for(int i=0; i<size; i++){
		data[i] = 1;
	}
	return data;
}

void displayArray(int *data,int size){
	assert(size > 2);
	int count = 1;
	for(int i=0; i<size-1; i++){
		printf("%d, ",data[i]);
		if(count == 20){
			printf("\n");
			count = 1;
		}
		else count++;
	}
	printf("%d \n\n",data[size-1]);
}

void cribleEratosthene(int *data,int size){
	assert(size > 2);
	//0 et 1 ne sont pas premier
	data[0] = 0;
	data[1] = 0;
	for(int i=2; i<size; i++){//on parcours les multiples a partir de 2
		if(data[i] == 1){
			for(int j=i+1; j<size; j++){//on parcours les nombres < n
				if(data[j] == 1){
					if(j%i == 0) data[j] = 0;
				}
			}
		}
	}
}

void cribleEratostheneOpti(int *data,int size){
	assert(size > 2);
	//0 et 1 ne sont pas premier
	data[0] = 0;
	data[1] = 0;
	for(int i=4; i<size; i+=2){//on elimine deja tout les pairs après 2
		data[i] = 0;
	}
	for(int i=3; i<size; i+=2){//on parcours les multiples a partir de 3 et on évite tout les pairs
		if(data[i] == 1){
			for(int j=i+i; j<size; j+=i){
				//on parcours les nombres < n en commancant par le prochain multiple de i et en allant de multiple en multiple
				//comme on parcours de multiple en multiple, on ne fait pas de test
				data[j] = 0;
			}
		}
	}
}

void displayPremiers(int *data,int size){
	assert(size > 2);
	int count = 1;
	for(int i=0; i<size; i++){
		if(data[i] == 1){
			printf("%d, ",i);
			if(count == 20){
				printf("\n");
				count = 1;
			}
			else count++;
		}
	}
	printf("\n\n");
}