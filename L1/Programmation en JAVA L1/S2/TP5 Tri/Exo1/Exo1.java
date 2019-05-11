public class Exo1{
static final int N=10;
static final int M=3;

static boolean [] generationAleatoire(int n) { //on génere un tableau aléatoirement
  int i;
  boolean [] t = new boolean[n];
  for ( i = 0 ; i < n ; i++ ) {
    t[i] = ( Math.random() < 0.5); 
  }
  return t;
  }


static void afficher(boolean [] t) { //on affiche le tableau
  int i;
  for (i = 0 ; i < t.length ; i++) {
    if (t[i]) Ecran.afficher('1');
    else Ecran.afficher('0');
  }
}

static int nbVrai(boolean [] t){ //on compte le nombre de vrai dans le tableau
  int res=0;
  int i;
  for(i=0;i<t.length;i++){
    if(t[i])res++;
  }
  return res;
}

static int nbSerieBool(boolean [] t){ //on compte le nombre de série (changement) dans le tableau
  int res=1,i;
  for(i=0;i<t.length-1;i++){
    if(t[i]!=t[i+1])res++;
  }
  return res;
}


static int longueurMaxSeriesVrais(boolean [] t) {
  int i,lMax,cpt;
  boolean enCours;
  lMax = 0;
  cpt = 0; //compteur
  enCours = false;
  for ( i = 0 ; i < t.length ; i++ ) {
    if ( t[i] ) { //t[i] vraie
      if ( !enCours ) { //t[i]= non(enCours)
        cpt = 0;
        enCours = true; 
      }
      cpt = cpt+1; 
    }
      else {
        if (enCours) {
          if (cpt>lMax){
            lMax = cpt; 
          }
          enCours = false; 
        } 
      } 
  }
  if (enCours) {
    if (cpt>lMax){
      lMax = cpt;
    } 
  }
  return lMax;
}

static int occurenceMotif(boolean [] t, boolean [] m){ //on cherche le motif dans le tableau en se déplacant d'un cran a chaque fois
  int res=-1;
  int i=0;
  while((i<(N-M+1))&&(res==-1)){
    res=test(t,m,i);
    i++;
  }
  return res;
}

static int test(boolean [] t, boolean [] m,int i){ //on recherche le motif à partir d'un indice donné i
  int j =0,res=i;
  while((res==i)&&(j<M)){
    if(m[j]!=t[j+i])res=-1;
    j++;
  }
  return res;      
}

public static void main (String [] args){
  boolean [] t = new boolean [N];
  boolean [] m = new boolean [M];
  t=generationAleatoire(N);
  m=generationAleatoire(M);
  Ecran.afficherln("\ntableau tiré aléatoirement : ");
  afficher(t);
  Ecran.sautDeLigne();
  Ecran.afficherln("\nMotif aléatoire à rechercher : ");
  afficher(m);
  Ecran.sautDeLigne();
  Ecran.afficherln("\nIl y as ",nbVrai(t)," booléen vrai dans le tableau");
  Ecran.afficherln("\nIl y as ",nbSerieBool(t)," série(s) différente(s) dans le tableau");
  Ecran.afficherln("\nLa plus grande série de vrai est de ",longueurMaxSeriesVrais(t)," Vrai consécutif(s) dans le tableau");
  if(occurenceMotif(t,m)==-1)Ecran.afficherln("\nLe motif à rechercher n'apparait pas dans le tableau"); //le motif n'apparait pas
  else Ecran.afficherln("\nLe motif à rechercher apparait en premier à l'indice ",occurenceMotif(t,m)," dans le tableau");
}
}