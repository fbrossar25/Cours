#include <stdio.h>
#include <math.h>
int main(){
	FILE *data = fopen("sin.dat","w");
	double sinus,x;
	int i;
	for(i=0;i<50;i++){
		x=(i*M_PI)/100;
		sinus=sin(x);
		fprintf(data,"%.10f %.10f \n",x,sinus);
	}
	fclose(data);
	return 0;
}

