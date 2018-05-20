public class Exo3 {
static class temps 
  {
  int h = 0;
  int m = 0;
  int s = 0;
  }
public static void main(String[]args)
  {
  temps t1 = new temps();
  temps t2 = new temps();
  int s1=0,s2=0,sdiff=0;
  Ecran.afficher("Veuillez saisir une première date (heure puis minutes puis secondes) :\n");
  t1.h=Clavier.saisirInt();
  t1.m=Clavier.saisirInt();
  t1.s=Clavier.saisirInt();
  Ecran.afficher("Veuillez saisir une deuxième date (heure puis minutes puis secondes) :\n");
  t2.h=Clavier.saisirInt();
  t2.m=Clavier.saisirInt();
  t2.s=Clavier.saisirInt();
  s1=t1.h*3600+t1.m*60+t1.s;
  s2=t2.h*3600+t2.m*60+t2.s;
  if (s1>s2)
  {
    Ecran.afficher("L'heure la plus tardive est : ",t1.h,":",t1.m,":",t1.s,".\n");
    Ecran.afficher("L'heure la moins tardive est : ",t2.h,":",t2.m,":",t2.s,".\n");
  }
else
  {
    Ecran.afficher("L'heure la plus tardive est : ",t2.h,":",t2.m,":",t2.s,".\n");
    Ecran.afficher("L'heure la moins tardive est : ",t1.h,":",t1.m,":",t1.s,".\n");
  }
sdiff = Math.abs(s1 - s2);
Ecran.afficher("La différence en secondes entre les deux heure est :",sdiff," secondes.\n");
}
}