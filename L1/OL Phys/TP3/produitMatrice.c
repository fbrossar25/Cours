#include<stdio.h>

int main (){
	int A[2][3],B[3][2],C[3][3],i,j;
	
	for(i=0;i<3;i++){ //remplissage de A
		for(j=0;j<2;j++)
		{
			printf("SVP valeur de A i=%d j=%d : ",i,j);
			scanf("%d",&A[i][j]);
			getchar();
		}
	}
	
	for(i=0;i<2;i++){ //remplissage de B
		for(j=0;j<3;j++)
		{
			printf("SVP valeur de B i=%d j=%d : ",i,j);
			scanf("%d",&B[i][j]);
			getchar();
		}
	}
	
	//produit des deux matrices C
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++)
		{
			C[i][j]=A[i][0]*B[0][j]+A[i][1]*B[1][j];
		}
	}
	
	printf("\n\nMatrice A : \n\n");
	for(i=0;i<=2;i++){ //affichage de A
		for(j=0;j<=1;j++)
		{
			printf(" %d ",A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nMatrice B : \n\n");
	for(i=0;i<=1;i++){ //affichage de B
		for(j=0;j<=2;j++)
		{
			printf(" %d ",B[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nMatrice résultat C (produit de A par B) :\n\n"); //affichage de C
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++)
		{
			printf(" %d ",C[i][j]);
		}
		printf("\n");
	}
	
	return 0;
	
}
