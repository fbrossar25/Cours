/*
 * Calcul du polynôme en utilsant la fonction de gsl
 */
#include <stdio.h>
#include <gsl/gsl_poly.h>
#define N 10
#define M 10


int main(){
  int i=1;
  const double A[N]={-3,1,2,-5,0.4,0.2,-0.3,0.1,-0.03,0.01};
  float x,h,a,b;
  a=0;b=1;
  h=(b-a)/M;
  x=0;
  for(i=0;i<=M;i++){
        printf("x=%f P(x)=%f\n",x,gsl_poly_eval(A,N,x));
    x+=h;
  } 
  return (0);
}
