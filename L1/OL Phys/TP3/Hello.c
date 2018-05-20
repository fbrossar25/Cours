#include<stdio.h>
#include<math.h>
#define PI 3.14159

int main (){
	float a=0, b=0; //a partie reel b partie complexe
	float theta=0.0, H=0.0; //H (Ro) module du nombre complexe, AB distance entre l'origine (A) et B
	printf("SVP, saisir partie réel du nombre complexe : \n");
	scanf("%f",&a);
	printf("SVP, saisir partie imaginaire du nombre complexe : \n");
	scanf("%f",&b);
	H=sqrt(a*a+b*b);
	if (a!=0)theta=atan(b/a);
	else if(b<0)theta=-PI/2;
	else if(b>0)theta=PI/2;
	else theta=0.0;
	printf("Nombre complexe %f+i%f = %f e(i%f)\n",a,b,H,theta);
	return 0;
	
}
