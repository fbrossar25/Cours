#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_histogram.h>
     
int
main (int argc, char **argv)
{
  double a, b;
  size_t n;
     
  if (argc != 4)
    {
      printf ("Usage: gsl-histogram xmin xmax n\n"
	      "Computes a histogram of the data "
	      "on stdin using n bins from xmin "
	      "to xmax\n");
      exit (0);
    }
     
  a = atof (argv[1]); //xmin
  b = atof (argv[2]); //xmax
  n = atoi (argv[3]); //n
     
  {
    double x;
    gsl_histogram * h = gsl_histogram_alloc (n); //Allocation de ressource mémoire
    gsl_histogram_set_ranges_uniform (h, a, b); //Définition des classes de l'histogramme
     
    while (fscanf (stdin, "%lg", &x) == 1) //Saisie des échantillons
      {
	gsl_histogram_increment (h, x); //Ajout d'un échantillon
      }
    gsl_histogram_fprintf (stdout, h, "%g", "%g");//affichage de l'histogramme classe et fréquence
    gsl_histogram_free (h); //Libération des ressources mémoires
  }
  exit (0);
}
