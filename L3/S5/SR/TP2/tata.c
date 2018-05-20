#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j;
	double s = 0.0;
	printf("processus 1: debut\n");
	for(i=0; i<4; i++){
		for(j=0; j<100000000; j++){
			s += 1.0/j;
			if(j == 0) printf("processus 1\n");
		}
	}
	return 0;
}
//