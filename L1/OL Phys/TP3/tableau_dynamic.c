#include <stdio.h>
#include <stdlib.h>

int main(){
	int taille=0,i;
	int * tablo=NULL;

	printf("Quelle taille?\n");
	scanf("%d",&taille);
	
	if((tablo=malloc(taille*sizeof(int)))==NULL){
		fprintf(stderr,"Allocation Impossible");
		exit(EXIT_FAILURE);
	}
	
	for(i=0;i<taille;i++){
		tablo[i]=i;
	}

	printf("les valeurs de notre tableau sont :\n");

	for(i=0;i<taille;i++){
		printf("%d ",tablo[i]);
	}
	printf("\n");

	free(tablo);

return(0);
}
