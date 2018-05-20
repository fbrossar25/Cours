public class Exo8 {

static class position3D
  {
  double x=0.0;
  double y=0.0;
  double z=0.0;
  }
static class quadrilatere
  {
  double l = 0.0; //longueur
  double h = 0.0; //hauteur
  double p = 0.0; //profondeur
  position3D centre = new position3D();
  }

public static void main(String[]args)
  {
  quadrilatere quad = new quadrilatere();
  double perimetre=0.0;
  Ecran.afficher("SVP saisir la longueur, hauteur puis la profondeur de votre quadrilatere :\n");
  quad.l = Clavier.saisirDouble();
  quad.h = Clavier.saisirDouble();
  quad.p = Clavier.saisirDouble();
  Ecran.afficher("SVP saisir les coordonnées x,y puis z du centre du quadrilatere : \n");
  quad.centre.x = Clavier.saisirDouble();
  quad.centre.y = Clavier.saisirDouble();
  quad.centre.z = Clavier.saisirDouble();
  perimetre = 4.0*(quad.l+quad.h+quad.p);
  Ecran.afficher("\nLe perimetre de votre quadrilatere vaut ",perimetre," unité de longueur.\n");  
}
}