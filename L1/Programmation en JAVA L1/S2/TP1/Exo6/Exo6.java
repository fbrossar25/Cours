public class Exo6 {

static class position3D
  {
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
  }
static class parallelepipede
  {
  double l = 0.0; //longueur
  double h = 0.0; //hauteur
  double p = 0.0; //profondeur
  position3D centre = new position3D();
  }
public static void main(String[]args)
  {
  parallelepipede p = new parallelepipede();
  double volume = 0.0;
  Ecran.afficher("Saisir la longueur, la hauteur puis la profondeur de votre parallelepipede : \n");
  p.l=Clavier.saisirDouble();
  p.h=Clavier.saisirDouble();
  p.p=Clavier.saisirDouble();
  volume = p.l*p.h*p.p;
  Ecran.afficher("\nLe volume de votre parallelepipede est de ",volume," m cube\n");
}
}