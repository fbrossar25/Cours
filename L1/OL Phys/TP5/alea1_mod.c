#include <stdio.h>

int main (void)
{
  FILE *data, *data1;

  float x;
  unsigned v,i,n= 200000;
  data = fopen("/dev/urandom", "r");
  data1 = fopen("alea1_mod.dat", "w");

  for (i = 0; i < n; i++) 
    {
      fread(&v,4,1,data);//lecture d'un enregistrement de 4 octets
      x=(float)v/0xFFFFFFFF;// 0<x<1
      fprintf(data1,"%f\n",x);
    }
  fclose(data);  fclose(data1);
  return 0;
}
