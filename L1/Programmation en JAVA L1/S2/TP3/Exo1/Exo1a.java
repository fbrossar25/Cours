public class Exo1a {

static double calculSinus(double angle){
  final double PI = 3.14159;
  double sinus;
  angle = (angle * PI) / 180.0;
  sinus = Math.sin(angle);
  return sinus;
}

public static void main(String[]args){
  double angle=0.0,sinus=0.0;
  Ecran.afficher("SVP saisir un angle en degrés : \n");
  angle=Clavier.saisirDouble();
  sinus=calculSinus(angle);
  Ecran.afficher("Le sinus de ",angle,"° vaut ",sinus,"\n");
}
}