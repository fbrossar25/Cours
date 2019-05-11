public class Exo10 {

static class localisationGeo
  {
  int deg = 0; //degré
  int m = 0; //minute
  double s = 0.0; //seconde
  }
static class localisationGPS
  {
  localisationGeo lo = new localisationGeo(); //longitude
  localisationGeo la = new localisationGeo(); //latitude
  }

public static void main(String[]args)
  {
  final double rayonTerrestre=6378.137; //km
  localisationGPS pos1 = new localisationGPS();
  localisationGPS pos2 = new localisationGPS();
  double dlo=0.0,dla=0.0,lo1=0.0,lo2=0.0,la1=0.0,la2=0.0,a=0.0,d=0.0;
  Ecran.afficher("SVP saisir la longitude de votre position (degré et minute (entier) puis seconde (réel)) :\n"); //longitude 1
  pos1.lo.deg=Clavier.saisirInt();
  pos1.lo.m=Clavier.saisirInt();
  pos1.lo.s=Clavier.saisirDouble();
  lo1=pos1.lo.deg+(pos1.lo.m/60)+(pos1.lo.s/3600.0);
  Ecran.afficher("lo1 = ",lo1,"\n\n");
  Ecran.afficher("SVP saisir la latitude de votre position (degré et minute (entier) puis seconde (réel)) :\n"); //latitude 1
  pos1.la.deg=Clavier.saisirInt();
  pos1.la.m=Clavier.saisirInt();
  pos1.la.s=Clavier.saisirDouble();
  la1=pos1.la.deg+(pos1.la.m/60)+(pos1.la.s/3600.0);
  Ecran.afficher("la1 = ",la1,"\n\n");
  Ecran.afficher("SVP saisir la longitude de votre position (degré et minute (entier) puis seconde (réel)) :\n"); //longitude 2
  pos2.lo.deg=Clavier.saisirInt();
  pos2.lo.m=Clavier.saisirInt();
  pos2.lo.s=Clavier.saisirDouble();
  lo2=pos2.lo.deg+(pos2.lo.m/60)+(pos2.lo.s/3600.0);
  Ecran.afficher("lo2 = ",lo2,"\n\n");
  Ecran.afficher("SVP saisir la latitude de votre position (degré et minute (entier) puis seconde (réel)) :\n"); //latitude 2
  pos2.la.deg=Clavier.saisirInt();
  pos2.la.m=Clavier.saisirInt();
  pos2.la.s=Clavier.saisirDouble();
  la2=pos2.la.deg+(pos2.la.m/60)+(pos2.la.s/3600.0);
  Ecran.afficher("la2 = ",la2,"\n\n");
  //calcul en degré radians des longitudes et latitudes
  lo1=Math.toRadians(lo1);
  lo2=Math.toRadians(lo2);
  la1=Math.toRadians(la1);
  la2=Math.toRadians(la2);
  dlo=(lo2-lo1)/2.0;
  Ecran.afficher("dlo = ",dlo,"\n\n");
  dla=(la2-la1)/2.0;
  Ecran.afficher("dla = ",dla,"\n\n");
  a=Math.abs((Math.sin(dla)*Math.sin(dla))+(Math.cos(la1)*Math.cos(la2))*(Math.sin(dla)*Math.sin(dla)));
  Ecran.afficher("a = ",a,"\n\n");
  d =2.0*Math.atan2(Math.sqrt(a),Math.sqrt(1.0 - a))*rayonTerrestre;
  Ecran.afficher("d = ",d,"\n\n");
  //Ecran.afficher("La distance entre vos deux points à vol d'oiseau est de ",d," km.\n");
}
}