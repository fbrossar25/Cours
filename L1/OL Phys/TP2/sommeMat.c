#include <stdio.h>
#include <gsl/gsl_matrix.h>
#define M 3
#define N 4

char menu(){
  int i;
  char c;
  char *operation[]={"Choisissez une opération\n",
                    "addition :       +\n",
		    "soustraction :   -\n",
                    "quitter :        q\n"};
  for (i=0; i<4; i++)
    printf("%s",operation[i]);
  scanf("%c",&c);
  getchar();
  return c;
}

void affiche(gsl_matrix * A, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%f ",gsl_matrix_get(A,i,j));
		}
		printf("\n");
	}

}

int main(){

	int i,j;
	char c;
	gsl_matrix * M1=gsl_matrix_alloc(M,N);
	gsl_matrix * M2=gsl_matrix_alloc(M,N);
	gsl_matrix * result=gsl_matrix_alloc(M,N);

	for(i=0;i<M;i++){
                for(j=0;j<N;j++){
			gsl_matrix_set(M1,i,j,i);	
			gsl_matrix_set(M2,i,j,i+j);	
		}
	}
	
	printf("Nos matrices de départ sont M1:\n");
	affiche(M1,M,N);
	printf("et M2 :\n");
	affiche(M2,M,N);

	while((c=menu())!='q'){
      		switch (c){
        		case '+':
			printf("la somme de M1 et M2 est égale à :\n");
			gsl_matrix_memcpy(result,M1);
			gsl_matrix_add(result,M2);
			affiche(result,M,N);
			break;
			case '-':
			printf("la différence de M1 et M2 est égale à :\n");
			gsl_matrix_memcpy(result,M1);
			gsl_matrix_sub(result,M2);
			affiche(result,M,N);
			break;
		}
	}

return 0;
}
