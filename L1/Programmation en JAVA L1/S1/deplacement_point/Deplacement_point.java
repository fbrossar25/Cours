public class Deplacement_point {
public static void main(String[]args){
int xP,yP,dire_imp; //xP et yP = coordonnées en x et y de P ; dire_imp = variable qui passe à 1 si le changement de direction est impossible (point au bord de l’écran)
char direction;   //caractère utilisé pour la direction du changement de position
dire_imp=0;
Ecran.afficher("Saisissez la coordonnée en x (entre 0 pour la gauche et 799 pour la droite) du point P : ");
xP=Clavier.saisirInt();
Ecran.sautDeLigne();
Ecran.afficher("Saisissez la coordonnée en y (entre 0 pour le haut et 599 pour le bas) du point P : ");
yP=Clavier.saisirInt();
Ecran.sautDeLigne();
Ecran.afficher("Saisissez un caractère (N :Nord ;O :Ouest ;S :Sud ;E :Est) pour appliquer un changement de direction de une unité vers la direction désirée ");
direction=Clavier.saisirChar();
Ecran.sautDeLigne();
switch (direction)
	{
	case 'O' : if(xP==0)
		{
			dire_imp=1;
		}
	      else
		      {
			      xP=xP-1;
		      }
		      break;
	case 'E' : if(xP==799)
		{
			dire_imp=1;
		}
		else
			{
				xP=xP+1;
			}
			break;
	case 'N' : if(yP==0)
		{
			dire_imp=1;
		}
	      else
		      {
			      yP=yP+1;
			}
			break;
	case 'S' : if(yP==599)
		{
			dire_imp=1;
		}
	      else
		      {
			      yP=yP-1;
			}
			break;
	default : Ecran.afficher("Erreur de saisie");
	}
if(dire_imp==1)
	{
		Ecran.afficher("Déplacement impossible");
		Ecran.sautDeLigne();
	}
else
	{
		Ecran.afficher("Nouvelles position de P : (",xP," ;",yP,")");
		Ecran.sautDeLigne();
	}

}
}