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
		}
		int i;
		for(i=1;i<=n;i++){
			 if ((i%3 == 0) && (i%5 == 0)) printf("FizzBuzz ");
			 else if(i%3 == 0) printf("Fizz ");
			 else if (i%5 == 0) printf("Buzz ");
			 else printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}