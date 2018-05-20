#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[]){
	long sum=0,prod=1;
	for(int i=1; i<argc; i++){//calcul la somme et le produits des conversions en entiers de touts les arguments
		sum += atoi(argv[i]);
		prod *= atoi(argv[i]);
	}
	printf("\nSum = %ld  Product = %ld\n",sum,prod);
	return 0;
}