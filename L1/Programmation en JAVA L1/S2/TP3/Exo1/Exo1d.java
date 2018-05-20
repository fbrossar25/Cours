public class Exo1d {
static double lectureReelDansIntervalle(double min,double max){
  double a;
  a=Clavier.saisirDouble();
  while(a<min || a>max){ 
    Ecran.afficher("Resaisir : ");
    a=Clavier.saisirDouble();
  }
  return a;
}

public static void main(String[]args){
  
  double x,min,max;
  Ecran.afficher("SVP saisir un minimum :");
  min=Clavier.saisirDouble();
  Ecran.afficher("SVP saisir un maximum :");
  max=Clavier.saisirDouble();
  Ecran.afficher("SVP saisir un reel appartenant à [",min,",",max,"] :");
  x=lectureReelDansIntervalle(min,max);
  Ecran.afficher(x," est bien compris dans l'intervalle [",min,",",max,"]. \n");
}
}