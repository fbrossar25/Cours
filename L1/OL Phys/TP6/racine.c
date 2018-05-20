 #define N 10000 //nombre de calcul à effectuer pour arriver une précision epsilon de 1/N
 #define EPS 1.0/N
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 
double f(double x,double a){ //fonction f(x)
	return x*x-a;
} 

double fp(double x){ //fonction f'(x)
	return 2*x;
} 

int main(int argc, char **argv){ 
	double x=1,a;
	if((argc != 2)||(atof(argv[1])<1)){
		printf("Utilisation : ./racine a \n"
				"Calcul la valeur approché de la racine de a (nombre positif > 1)\n");
		exit(0);
	}
	a=atof(argv[1]);
	do{
		x=x-(f(x,a)/fp(x));
	}while(fabs(f(x,a))>=EPS);
	//EPS est la condition d'arrêt si on trouve f(x) valeur proche de 0 à EPS près 
	printf("\nf( %lf ) = %lf \n",x,f(x,a)); //on affiche le résultats
	return(0);
}
