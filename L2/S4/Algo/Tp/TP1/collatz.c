#include "stdio.h"
#include "stdlib.h"



int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Un seul argument entier > 1 nécessaire\n");
		return 1;
	}
	else{
		int n = atoi(argv[1]);
		if(n < 1){
			printf("Un seul argument entier > 1 nécessaire\n");
			return 1;
		}
		printf("%d",n);
		do{
			printf(", ");
			if(n%2 == 0)n /= 2;
			else n = (n*3) + 1;
			printf("%d",n);
		}while(n > 1);
		printf("\n");
	}
	return 0;
}