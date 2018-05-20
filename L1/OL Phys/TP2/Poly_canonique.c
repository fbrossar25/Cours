 #define N 100 //nombre de calcul à effectuer pour arriver une précision epsilon de 1/N
 #include <stdio.h>
 #include <math.h>
 
float f(float x){ //fonction f(x)=x-e(sin(x))
	float f;
	if(x>=1.5 && x <=5){
		f=x-pow(M_E,sin(x));
	}
	return f;
} 

float fp(float x){ //fonction f'(x)=1-cos(x)*e(sin(x))
	float fp;
	if(x>=1.5 && x <=5){
		f=1-(cos(x)*pow(M_E,sin(x)));
	}
	return fp;
} 

int main(){
	int i; 
	float x=0.0, deltax=1.0/N;
	float fx=0.0,fpx=0.0;
	//for (i=0; i<=N; i++){
		printf("\nf(%f) = %f\n",x ,f(x));
		printf("\nf'(%f) = %f\n",x ,fp(x));
		//x=x+deltax;
	//}
	return(0);
}
