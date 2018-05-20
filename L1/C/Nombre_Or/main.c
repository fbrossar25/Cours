#include <stdio.h>
#include <stdlib.h>

int main()
{
    double Or=0.0; //F2 = Fn-2; F1 = Fn-1;
    //Or est le nombre d'or, Or1 et le nb d'or a l'instant t1 afin de faire sa différence avec Or2 à l'instant suivant
    unsigned long F2=1,F1=1,F=0; //n est le degré du terme Or
    int autreCalcul=0,i=0,n=1; //0 vraie 1 faux
    do{
        printf("Choisissez le degre du terme de la suite de fibonacci que vous voulez calculer (nombre entier entre 3 et 40 compris attendu): ");
        do
        {
            scanf("%d",&i);
            printf("\n");
        }while(i<3||i>40);
        do
        {
            n++;
            F=F1+F2;
            Or=F*1.0/F1*1.0;
            F2=F1; //On affecte Fn-1 et Fn-2
            F1=F;
        }while(n<i);
        printf("F%d = %ld\nF1= %ld F2= %ld\n",n,F,F1,F2);
        printf("Le nombre d'Or obtenu est : %lf\n",Or);
        F1=1;
        F2=1;
        n=2;
        printf("Voulez-vous calculez un autre nombre (0 pour oui 1 pour non)? ");
        scanf("%d",&autreCalcul);
        if(autreCalcul==0||autreCalcul==1) //on recommence si 0 arret si 1
        {
            printf("\n");
        }
        else  //on arrete le programme (mauvaise saisie)
        {
            printf("Erreur de saisie arret du programme...\n");
            autreCalcul=1;
        }
    }while(autreCalcul<=0);
    return 0;
}
