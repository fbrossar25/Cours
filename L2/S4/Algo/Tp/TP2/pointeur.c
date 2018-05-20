#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int *array_new(size_t size);
void displayArray(int *p,int size);
size_t array_index_max(const int *data, size_t size);
int array_sum(const int *data, size_t size);
size_t array_count(const int *data, size_t size, int value);
void array_shift_left(int *data, size_t size);
size_t array_longest_even_seq(const int *data, size_t size);


int main(int argc, char *argv[]){
	int size;
	if(argc < 2)size = 10000;
	else size = atoi(argv[1]);
	if(size < 1) size = 10000;
	srand(time(NULL)); // initialisation de rand
	int *data = array_new(size);
	displayArray(data,size);
	printf("\n\n");
	array_index_max(data,size);
	array_sum(data,size);
	array_count(data,size,99);
	array_shift_left(data,size);
	array_longest_even_seq(data,size);
	printf("\n\nTableau apres decalage :\n");
	displayArray(data,size);
	printf("\n\n");
	return 0;
}



int *array_new(size_t size){
	int *data = calloc(size,sizeof(size_t));
	for(int i=0; i<size; i++){
		data[i] = rand()%100; // *(p+i) = rand()%100;
	}
	return data;
}

void displayArray(int *data,int size){
	int count = 1;
	for(int i=0; i<size-1; i++){
		printf("%d, ",data[i]);
		if(count == 10){
			printf("\n");
			count = 1;
		}
		else count++;
	}
	printf("%d \n",data[size-1]);
}

size_t array_index_max(const int *data, size_t size){
	size_t res = 0;
	for(size_t i=1; i<size; i++){
		if(data[i] > data[res]){
			res = i;
		}
	}
	printf("Indice du plus grand element : %zu\n",res);
	return res;
}

int array_sum(const int *data, size_t size){
	int res=data[0];
	for(int i=1; i<size; i++){
		res += data[i];
	}
	printf("Somme des elements du tableau = %d\n",res);
	return res;
}

size_t array_count(const int *data, size_t size, int value){
	int res = 0;
	for(int i=0; i<size; i++){
		if(data[i] == value) res++;
	}
	printf("La valeur %d apparait %d fois.\n",value,res);
	return res;
}

void array_shift_left(int *data, size_t size){
	int first = data[0];
	for(int i=0; i<size; i++){
		data[i] = data[i+1];
	}
	data[size-1] = first;
}

size_t array_longest_even_seq(const int *data, size_t size){
	//probleme : donne l'indice de la serie la plus longue - 1
	//resolution : on ajoute 1 au resultat
	size_t best_sequence_length = 0;
	size_t current_sequence_length = 0;
	size_t best_index = 0;
	size_t current_index = 0;
	bool seriePair = false;
	for(int i=0; i<size; i++){
		if(!seriePair && data[i]%2 == 0){//serie de nombre pairs qui commence
			seriePair = true;
			current_index = i;
			current_sequence_length++;
		}
		else if(seriePair && data[i]%2 == 0) current_sequence_length++; //serie de nombres pairs continue
		else if(seriePair && data[i]%2 != 0){//serie de nombres pairs terminee
			seriePair = false;
			if(current_sequence_length > best_sequence_length){//si derniere serie plus grande que l'ancienne
				best_sequence_length = current_sequence_length;
				best_index = current_index;
			}
			current_sequence_length = 0;
		}
	}
	printf("La plus grande serie de nombres pairs est de %zu elements et commence a l'indice %zu.\n",best_sequence_length,best_index + 1);
	return best_index + 1;
}