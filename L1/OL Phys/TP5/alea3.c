#include <stdio.h>
#include <gsl/gsl_rng.h>

int main (void)
{
  FILE *data;
  const gsl_rng_type * T;
  gsl_rng * r;
  gsl_rng_env_setup();
  T = gsl_rng_default;
  r = gsl_rng_alloc (T);
  float x;
  unsigned i,n= 200000;
  data = fopen("alea3.dat", "w");

  for (i = 0; i < n; i++) 
    {
      x=gsl_rng_uniform (r);
      fprintf(data,"%f\n",x);
    }
  fclose(data);
  gsl_rng_free (r);
  return 0;
}
