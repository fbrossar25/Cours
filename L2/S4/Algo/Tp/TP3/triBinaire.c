#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int *array_new(int size);
void displayArray(int *data,int size);
int numberOfOne(int *data, int size);
void sortBinaryArray(int *data, int size);

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Il faut un argument entier > 0\n");
		return 1;
	}
	int n = atoi(argv[1]);
	if(n < 1){
		printf("Il faut un argument entier > 0\n");
		return 1;
	}
	srand(time(NULL));
	int *data = array_new(n);
	if(n<=500){
		printf("Tableau binaire avant tri :\n");
		displayArray(data,n);
	}
	printf("\nNombre de 1 avant tri : %d\n",numberOfOne(data,n));
	sortBinaryArray(data,n);
	if(n<=500){
		printf("Tableau binaire apres tri :\n");
		displayArray(data,n);
	}
	printf("\nNombre de 1 apres tri : %d\n",numberOfOne(data,n));
	return 0;
}

int *array_new(int size){
	int *data = calloc(size,sizeof(int));
	for(int i=0; i<size; i++){
		data[i] = rand()%2;
	}
	return data;
}

int numberOfOne(int *data, int size){
	int res = 0;
	for(int i=0; i<size; i++){
		if(data[i] == 1) res++;
	}
	return res;
}

void displayArray(int *data, int size){
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

void sortBinaryArray(int *data, int size){
	int begin=0, end=size-1;
	while((end - begin) != 0){
		if(data[begin] == 1){
			data[begin] = data[end];//on échange
			data[end] = 1;
			end--;
		}
		else begin++;
	}
}
/*
l'operation elementaire est la comparaison
Le cas moyen suppose qu'il y ai autant de 1 que de 0 donc
C(n) =  n/2 = O(n)
*/