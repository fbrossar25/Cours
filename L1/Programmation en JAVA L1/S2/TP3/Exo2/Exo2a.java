public class Exo2a {
static class angle{
  double sinus=0.0;
  double cosinus=0.0;
}
static double calculSin(double a){
  double sinus=0.0;
  sinus=Math.sin(a);
  return sinus;
}

static double calculCos(double a){
  double cosinus=0.0;
  cosinus=Math.cos(a);
  return cosinus;
}

public static void main(String[]args){
  double x=0.0;
  angle a = new angle();

  Ecran.afficher("SVP saisir un angle en degré : ");
  x=Clavier.saisirDouble();
  a.sinus=calculSin((x*Math.PI)/180.0);
  a.cosinus=calculCos((x*Math.PI)/180.0);
  Ecran.afficher("Le sinus de ",x,"° vaut ",a.sinus," et son cosinus vaut ",a.cosinus,".\n");
}
}