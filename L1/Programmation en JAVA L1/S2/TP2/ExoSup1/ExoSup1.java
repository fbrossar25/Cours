public class ExoSup1 {

static class position3D
  {
  double x=0.0;       
  double y=0.0;
  double z=0.0;
  }
static class sphere
  {
  position3D centre=new position3D();
  double r=0.0;
  }
public static void main(String[]args)
  {
  sphere s1=new sphere();
  sphere s2=new sphere();
  //sphere 1
  Ecran.afficher("SVP rayon de s1 :\n");
  s1.r=Clavier.saisirDouble();
  Ecran.afficher("SVP coordonné du centre de s1 (x,y,z) :\n");
  s1.centre.x=Clavier.saisirDouble();
  s1.centre.y=Clavier.saisirDouble();
  s1.centre.z=Clavier.saisirDouble();
  //sphere 2
  Ecran.afficher("SVP rayon de s2 :\n");
  s2.r=Clavier.saisirDouble();
  Ecran.afficher("SVP coordonné du centre de s2 (x,y,z) :\n");
  s2.centre.x=Clavier.saisirDouble();
  s2.centre.y=Clavier.saisirDouble();
  s2.centre.z=Clavier.saisirDouble();
}
}