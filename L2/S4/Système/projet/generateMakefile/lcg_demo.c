#include <stdio.h>
#include <stdlib.h>
#include "lcg.h"
//#include "toto.h"

int main(int argc, char const *argv[])
{
	size_t n = 100;
	size_t seed = 42;
	if(argc > 1){
		n = (atoi(argv[1]) > 0) ? atoi(argv[1]) : 100;
	}
	if(argc > 2){
		seed = atoi(argv[2]);
	}
	struct lcg *toto = calloc(1,sizeof(struct lcg));
	lcg_param(toto,137,187,256);
	lcg_seed(toto,seed);
	printf("RAND_MAX_LCG = %zu\n",lcg_max(toto));
	for(size_t i=0; i<n; i++){
		printf("%zu\n",lcg_next(toto));
	}
	return 0;
}