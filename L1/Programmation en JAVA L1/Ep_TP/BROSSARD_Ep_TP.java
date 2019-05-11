//programme réalisé par BROSSARD Florian
public class BROSSARD_Ep_TP {
public static void main (String [] args) {
int P_ligne=0,P_colonne=0,Obj_ligne=0,Obj_colonne=0;
char direction,Action;
final int N=4;
/*N dimension de la carte, Action l'action que le joueur effectue, P_ligne/P_colonne et Obj_ligne/Obj_colonne respectivement les coordonnées du personnage et du trésor*/
do
  {
	  Ecran.afficher("Veuillez saisir la ligne de départ de votre personnage\n (nombre entier correspondant au numéro de la ligne et étant compris entre 0 et ",N-1,") ");
	  P_ligne=Clavier.saisirInt();
	  Ecran.sautDeLigne();
	    if(P_ligne<0 || P_ligne>N)
	    {
		    Ecran.afficher("Erreur. La coordonnée saisie doit être comprise entre 0 et ",N-1);
		    Ecran.sautDeLigne();
	    }
  }while(P_ligne<0 || P_ligne>N-1);
do
  {
	  Ecran.afficher("Veuillez saisir la colonne de départ de votre personnage\n (nombre entier correspondant au numéro de la colonne et étant compris entre 0 et ",N-1,") ");
	  P_colonne=Clavier.saisirInt();
	  Ecran.sautDeLigne();
	    if(P_colonne<0 || P_colonne>N)
	    {
		    Ecran.afficher("Erreur. La coordonnée saisie doit être comprise entre 0 et ",N-1);
		    Ecran.sautDeLigne();
	    }
  }while(P_colonne<0 || P_colonne>N-1);
do
  {
	  Ecran.afficher("Veuillez saisir l'orientation de votre personnage par une lettre\n (e pour est, o pour ouest, n pour nord, s pour sud) ");
	  direction=Clavier.saisirChar();
	  Ecran.sautDeLigne();
	  if(direction!='e' && direction!='o' && direction!='n' && direction!='s')
	    {
		    Ecran.afficher("Erreur vous avez saisis une mauvaise lettre, il faut saisir e, o, n ou s");
		    Ecran.sautDeLigne();
	    }
  }while(direction!='e' && direction!='o' && direction!='n' && direction!='s');
  Ecran.afficher("P (",P_ligne,",",P_colonne,") - dir : ",direction);
  Ecran.sautDeLigne();
do
  {
	Obj_ligne=(int)(Math.random()*N);
  }while(Obj_ligne==P_ligne);
do
  {
	Obj_colonne=(int)(Math.random()*N);
  }while(Obj_colonne==P_colonne);
  Ecran.afficher("L'objectif se trouve en : (",Obj_ligne,",",Obj_colonne,")");
  Ecran.sautDeLigne();
do
  {
	  Ecran.afficher("Veuillez effectuer une action : entrer a d'une case ou q pour quitter le jeu ");
	  Action=Clavier.saisirChar();
	  if(Action=='a')
	    {
		Ecran.afficher("Dans quelle direction voulez-vous avancez ?");
		direction=Clavier.saisirChar();
		Ecran.sautDeLigne();
		switch(direction)
		{
		  case 'e':{
		    if(P_colonne<N-1)
		      {
			P_colonne++;
		      }
		    else {
			Ecran.afficher("Déplacement impossible");
			Ecran.sautDeLigne();
		    }
		  }break;
		  case 'o':{
		    if(P_colonne>0)
		      {
			P_colonne--;
		      }
		    else {
			Ecran.afficher("Déplacement impossible");
			Ecran.sautDeLigne();
		    }
		  }break;
		  case 'n':{
		    if(P_ligne>0)
		      {
			P_ligne--;
		      }
		    else {
			Ecran.afficher("Déplacement impossible");
			Ecran.sautDeLigne();
		    }
		  }break;
		  case 's':{
		    if(P_ligne<N-1)
		      {
			P_ligne++;
		      }
		    else {
			Ecran.afficher("Déplacement impossible");
			Ecran.sautDeLigne();
		    }
		  }break;
		  default:{
			Ecran.afficher("Erreur de saisie");
			Ecran.sautDeLigne();
		  }
		}
		Ecran.afficher("P (",P_ligne,",",P_colonne,") - dir : ",direction);
		Ecran.sautDeLigne();
		if((P_ligne==Obj_ligne)&&(P_colonne==Obj_colonne))
		{
			Ecran.afficher("Vous avez trouvé le trésor. Bravo!");
			Ecran.sautDeLigne();
		}
		else	if(P_ligne==Obj_ligne)
		{
			Ecran.afficher("Le trésor est sur la même ligne que votre personnage");
			Ecran.sautDeLigne();
		}
		else if(P_colonne==Obj_colonne)
		{
			Ecran.afficher("Le trésor est sur la même colonne que votre personnage");
			Ecran.sautDeLigne();
		}
	    }
	    else if (Action=='q')
	      {
		Ecran.afficher("Fermeture du jeu...");
		Ecran.sautDeLigne();
	      }
	    else
	      {
		Ecran.afficher("Erreur de saisie");
		Ecran.sautDeLigne();
	      }
  }while(P_ligne!=Obj_ligne || P_colonne!=Obj_colonne && Action!='q');//tant que l'on ne trouve pas le trésor ou que l'on ne quitte pas le jeu
}
}
