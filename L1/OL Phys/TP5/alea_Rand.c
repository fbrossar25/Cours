#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  FILE *data;

  float x;
  unsigned i,n= 200000;
  data = fopen("alea2.dat", "w");

  for (i = 0; i < n; i++) 
    {
      x=(float)rand()/RAND_MAX;
      fprintf(data,"%f\n",x);
    }
  fclose(data);
  return 0;
}
