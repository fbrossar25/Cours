#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Un seul argument entier > 0 nécessaire\n");
		return 1;
	}
	else{
		int n = atoi(argv[1]);
		if(n < 0){
			printf("Un seul argument entier > 0 nécessaire\n");
			return 1;
		};
		for(int i=1;i<=n;i++){
			 for(int j=0;j<i;j++){
			 	printf("#");
			 }
			 printf("\n");
		}
	}
	return 0;
}