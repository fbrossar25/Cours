#include <stdio.h>
#include <stdlib.h>
#include "lcg.h"

int main(int argc, char const *argv[])
{
	struct lcg *toto = calloc(1,sizeof(struct lcg));
	lcg_param(toto,137,187,256);
	lcg_seed(toto,42);
	printf("RAND_MAX_LCG = %zu\n",lcg_max(toto));
	for(size_t i=0; i<10; i++){
		printf("%zu\n",lcg_next(toto));
	}
	return 0;
}