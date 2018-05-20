public class Exo6 {
public static void main(String[]args){
double r,x,y,xA,xB,yA,yB,distance;
Ecran.afficher("Entrez les coordonnées du point A : xA=");
xA=Clavier.saisirFloat();
Ecran.afficher("yA=");
yA=Clavier.saisirFloat();
Ecran.sautDeLigne();
Ecran.afficher("Entrez le rayon r du cerle de centre A : ");
r=Clavier.saisirFloat();
Ecran.sautDeLigne();
Ecran.afficher("Entrez les coordonnées du point B : xB=");
xB=Clavier.saisirFloat();
Ecran.afficher("yB=");
yB=Clavier.saisirFloat();
Ecran.sautDeLigne();
x=(xB-xA)*(xB-xA);
y=(yB-yA)*(yB-yA);
distance=Math.sqrt(x+y);
Ecran.afficher("La distance entre le point A (",xA,",",yA,") et le point B(",xB,",",yB,") vaut : ",distance);
if((xB>=xA-r&&xB<=xA+r)&&(yB>=yA-r&&yB<=yA+r))
  {Ecran.sautDeLigne();
  Ecran.afficher("Le point B est dans le cercle de centre A et de rayon r");
  Ecran.sautDeLigne();
  }
else
  {Ecran.sautDeLigne();
  Ecran.afficher("Le point B n'est pas dans le cercle de centre A et de rayon r");
  Ecran.sautDeLigne();
  }
}
}