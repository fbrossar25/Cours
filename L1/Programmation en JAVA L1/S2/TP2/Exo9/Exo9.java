public class Exo9 {

static class temps
  {
  int h = 0; //heure
  int m = 0; //minute
  int s = 0; //seconde
  }

public static void main(String[]args)
  {
  temps tps = new temps();
  int seconde=0;
  Ecran.afficher("SVP un temps (heure, minute puis seconde) :\n");
  tps.h = Clavier.saisirInt();
  tps.m = Clavier.saisirInt();
  tps.s = Clavier.saisirInt();
  Ecran.afficher("SVP saisir un nombre de secondes afin d'incrémenter le temps saisis : \n");
  seconde = Clavier.saisirInt();
  tps.h+=seconde/3600;
  tps.m+=((seconde-seconde/3600)/60)%60;
  tps.s+=(seconde-seconde/3600)%60;
  Ecran.afficher("Votre temps incrémenté de ",seconde," seconde(s) est ",tps.h,":",tps.m,":",tps.s,"\n");  
}
}