#include <stdio.h>
int main(){
	int age;
	printf("\n Bonjour! \n");
	printf(" Quel est votre âge : \n");
	do{
		scanf("%d",&age);
		if(age<0)printf("\n Erreur : vous ne pouvez pas avoir un âge <0\n");
	}while(age<0);
	printf("\n Vous avez %d ans\n",age);
	return (0);
}
