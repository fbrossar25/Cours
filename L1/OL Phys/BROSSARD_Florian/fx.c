#include <stdio.h>
#include <math.h>

int factorielle(int n){//retourne n!
	int res;
	if(n==1 || n==0) res=1;
	else res=n*factorielle(n-1);
	return res;
	}
	
double f(double x){//retourne f(x)
	double res;
	res=x-((1/factorielle(3))*pow(x,3))+((1/factorielle(5))*pow(x,5))-((1/factorielle(7))*pow(x,7));
	return res;
}


int main(){
	FILE *data = fopen("fx.dat","w");
	FILE *dataSin = fopen("sin.dat","r");
	double xSin,sinx,diff,fctx,x;
	int i;
	fprintf(data,"%c            %s         %s\n",'x',"f(x)","f(x)-sin(x)");
	for(i=0;i<50;i++){
		x=(i*M_PI)/100;  //(i/50)*(PI/2)
		fctx=f(x);
		fscanf(dataSin,"%lf %lf",&xSin,&sinx);
		diff=fctx-sinx;								//calcul de la différence f(x)-sin(x)
		fprintf(data,"%.10f %.10f %.10f \n",x,fctx,diff);
	}
	fclose(data);
	fclose(dataSin);
	return 0;
}

