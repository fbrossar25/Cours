#include <stdio.h>
#include <unistd.h>
#include <math.h>
#define N 200
int main()
{
    FILE  * f,* data;
    int i;
    float x=0,y=0;
    // Création d'un fichier contenant les valeurs de sin(x)
    data = fopen("toto.dat", "w");
    for (i=0;i<N ; i++) {
		y=sin(x);
		x+=M_PI/N;
		fprintf(data,"%f %f\n",x,y);
    }
    fclose(data);
      // Ouverture du shell et lancement d'octave
    f = popen("octave -i", "w");
      // exécution des commandes d'octave pour tracer le graphe
    fprintf(f," load toto.dat \n ");
    fprintf(f, " plot(toto(:,1),toto(:,2))\n ");
    fprintf(f, " print -dpng sinus.png \n");
   fflush(f);
    // fermeture d'octave après 5 secondes
    sleep(5);
    pclose(f);
    return 1;
}
