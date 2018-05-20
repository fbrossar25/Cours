#include<stdio.h>

int main (){
	int tab[50],a=0,i,res=0; //a taille du tableau
	do{
		printf("SVP, saisir la taille du tableau (entier entre 1 et 50 attendu) : \n");
		scanf("%d",&a);
	}while(a<1||a>50);
	for(i=0;i<=a-1;i++){ //remplissage
		printf("\nSVP, saisir la valeur %d du tableau (entier attendu) : \n",i+1);
		scanf("%d",&res);
		tab[i]=res;
	}
	res=0;
	for(i=0;i<=a-1;i++){ //somme
		res+=tab[i];
	}
	printf("La somme des %d elements du tableau est egale a %d\n",a,res);
	printf("\nAffichage des valeurs du tableau dans l'ordre inverse :\n");
	for(i=a-1;i>=0;i--){
		if(i>0)printf("%d , ",tab[i]);
		else printf("%d .",tab[i]);
	}
	printf("\n");
	return 0;
	
}
