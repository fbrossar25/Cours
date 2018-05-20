/* Application exemple d'utilisation des methodes   */
/* contenues dans EcranGraphique.class              */

public class testAffichage{
  
  public static void croix(int x,int y) {
    EcranGraphique.drawLine(x-10,y,x+10,y);
    EcranGraphique.drawLine(x,y-10,x,y+10);
  }
  
  public static void main(String [] args) {
    int val = -1;
  /* Initialisation de la fenetre d'affichage       */
    EcranGraphique.init(50,50,480,360,640,480,"Test affichage graphique");
  /* Boucle de gestion de l'application             */
    while ( val != 0 ) {
  /* Menu                                           */
      Ecran.afficherln("1 - Afficher 3 pixels");      
      Ecran.afficherln("2 - Afficher un segment de droite");      
      Ecran.afficherln("3 - Animation d'un segment de droite");
      Ecran.afficherln("4 - Afficher un rectangle et remplir un rectangle");
      Ecran.afficherln("5 - Afficher un cercle et remplir un cercle");
      Ecran.afficherln("6 - Affichage d'une chaine de caracteres");      
      Ecran.afficherln("7 - Effacer l'ecran");
      Ecran.afficherln("8 - Lire un caractere au clavier");
      Ecran.afficherln("9 - Deplacer une croix a la souris");
      Ecran.afficherln("0 - Quitter");
      Ecran.afficher("Choix ? ");
      val = Clavier.saisirInt();
  /* Action en fonction de la valeur saisie         */
      switch (val) {
        case 1 : {
  /* Affichage de trois pixels de couleurs differentes */
          EcranGraphique.setColor(200,0,0);
          EcranGraphique.drawPixel(100,200);
          EcranGraphique.setColor(0,200,0);
          EcranGraphique.drawPixel(200,100);
          EcranGraphique.setColor(0,0,200);
          EcranGraphique.drawPixel(300,200);
          EcranGraphique.flush(); }
          break;
        case 2 : {
  /* Affichage d'un segment de droite               */
          EcranGraphique.setColor(200,0,0);
          EcranGraphique.drawLine(-100,100,100,100);
          EcranGraphique.flush(); }
          break;
        case 3 : {
  /* Animation d'un segment de droite               */
          for ( int i = 0 ; i <= 768 ; i++ ) {
            EcranGraphique.clear();
            EcranGraphique.setColor(i/3,i%256,(i+128)%256);
            EcranGraphique.drawLine((int) (320+200*Math.cos(i*Math.PI*2.0/768.0)+0.5),
                                    (int) (240+200*Math.sin(i*Math.PI*2.0/768.0)+0.5),
                                    (int) (320-200*Math.cos(i*Math.PI*2.0/768.0)+0.5),
                                    (int) (240-200*Math.sin(i*Math.PI*2.0/768.0)+0.5));
            EcranGraphique.flush(); } }
          break;
        case 4 : {
  /* Affichage d'un rectangle                       */
          EcranGraphique.setColor(200,0,0);
          EcranGraphique.drawRect(-100,100,400,500);
  /* Remplissage d'un rectangle                     */
          EcranGraphique.setColor(200,200,0);
          EcranGraphique.fillRect(500,300,700,100);
          EcranGraphique.flush(); }
          break;
        case 5 : {
  /* Affichage d'un cercle                          */
          EcranGraphique.setColor(200,0,0);
          EcranGraphique.drawCircle(120,250,200);
  /* Remplissage d'un cercle                        */
          EcranGraphique.setColor(200,200,0);
          EcranGraphique.fillCircle(500,320,240);
          EcranGraphique.flush(); }
          break;
        case 6 : {
  /* Affichage d'une chaine de caracteres */
          EcranGraphique.setColor(255,255,255);
          EcranGraphique.drawString(10,200,EcranGraphique.SYMBOL8x13,"ABCDEFGHIJKLMNOPQRSTUVWXYZ-abcdefghijklmnopqrstuvwxyz-0123456789");
          EcranGraphique.drawString(10,220,EcranGraphique.COLABA8x13,"ABCDEFGHIJKLMNOPQRSTUVWXYZ-abcdefghijklmnopqrstuvwxyz-0123456789");
          EcranGraphique.flush(); }
          break;
        case 7 : {
  /* Effacement de la fenetre de dessin             */
          EcranGraphique.clear();
          EcranGraphique.flush(); }
          break;
        case 8 : {
  /* Lecture d'un caractere au clavier              */
          char c;
          while ( (c = EcranGraphique.getKey()) == 0x00 );
          System.out.println(c);
          System.out.println((int) c); }
          break;
        case 9 : {
  /* Deplacement d'une croix a la souris            */
          EcranGraphique.setColor(255,255,255);
          while ( EcranGraphique.getMouseState() == 0 );
          EcranGraphique.setXorMode(true);
          int xOld = EcranGraphique.getMouseX();
          int yOld = EcranGraphique.getMouseY();
          croix(xOld,yOld);
          while ( EcranGraphique.getMouseState() == 1 ) {
            int x = EcranGraphique.getMouseX();
            int y = EcranGraphique.getMouseY();
            if ( ( x != xOld ) || ( y != yOld ) ) {
              croix(xOld,yOld);
              xOld = x;
              yOld = y;
              croix(x,y);
              EcranGraphique.flush(); } }
          croix(xOld,yOld);
          EcranGraphique.flush();
          EcranGraphique.setXorMode(false); }
          break;
        case 0 : {
          Ecran.afficherln("A bientot!!!");
          break; } } }
  /* Fermeture de la fenetre                        */
  /* et interruption de l'application               */
    EcranGraphique.exit();
  }   
}