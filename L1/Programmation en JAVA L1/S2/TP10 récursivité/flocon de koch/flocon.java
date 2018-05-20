public class flocon{
/* Type structure de stockage                   */
/* d'un segment de droite a coordonnees reelles */

static class Segment {
  double xi = 0.0;
  double yi = 0.0;
  double xf = 0.0;
  double yf = 0.0; };

/* Calcul et affichage d'un flocon de Koch      */

public static void flocon(Segment s,int niveau) {
  Segment s1 = new Segment();
  Segment s2 = new Segment();
  Segment s3 = new Segment();
  Segment s4 = new Segment();
  double dx;
  double dy;
  if ( niveau == 0 ) {
    EcranGraphique.drawLine((int) s.xi,(int) s.yi,
                            (int) s.xf,(int) s.yf); }
    else {
    dx = (s.xf-s.xi)/3.0;
    dy = (s.yf-s.yi)/3.0;
    s1.xi = s.xi;
    s1.yi = s.yi;
    s1.xf = s.xi+dx;
    s1.yf = s.yi+dy;
    flocon(s1,niveau-1);
    s2.xi = s1.xf;
    s2.yi = s1.yf;
    s2.xf = s2.xi+(dx-Math.sqrt(3.0)*dy)/2.0;
    s2.yf = s2.yi+(dy+Math.sqrt(3.0)*dx)/2.0;
    flocon(s2,niveau-1);
    s3.xi = s2.xf;
    s3.yi = s2.yf;
    s3.xf = s.xf-dx;
    s3.yf = s.yf-dy;
    flocon(s3,niveau-1);
    s4.xi = s3.xf;
    s4.yi = s3.yf;
    s4.xf = s.xf;
    s4.yf = s.yf;
    flocon(s4,niveau-1); 
    }
}

 public static void main(String [] args) {
    Segment s = new Segment();
    EcranGraphique.init(50,20,1300,600,1200,500,"Flocon");
    EcranGraphique.setColor(0,0,0);
    EcranGraphique.setClearColor(255,255,255);
    EcranGraphique.clear();
    Ecran.afficherln("\n Quel niveau du flocon de koch à afficher ?");
    int n = Clavier.saisirInt();
    s.xi = 50.0;
    s.yi = 20.0;
    s.xf = 1200.0;
    s.yf = 20.0;
    flocon(s,0);
    for ( int i = 1 ; i < n ; i++ ) {
      EcranGraphique.clear();
      s.xi = 50.0;
      s.yi = 20.0;
      s.xf = 1200.0;
      s.yf = 20.0;
      flocon(s,i); 
      EcranGraphique.flush();
      EcranGraphique.wait(1000);
    }
    boolean run=true;
    do{
        Ecran.afficherln("\n appuyer su q pour fermer la fenêtre");
        if(Clavier.saisirChar()=='q'){
            EcranGraphique.exit();
            System.exit(0);
        }
    }while(1==1);
  }
}