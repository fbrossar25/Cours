#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[]){
	for(int i=0; i<argc; i++){//on parcours le tableau de chaines argv et on affiches tout les arguments
		printf("%s ",argv[i]);
	}
	printf("\n");
	return 0;
}
