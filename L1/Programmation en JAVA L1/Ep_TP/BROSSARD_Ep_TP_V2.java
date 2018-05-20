//programme réalisé par BROSSARD Florian
public class BROSSARD_Ep_TP_V2 {
public static void main (String [] args) {
int P_ligne=0,P_colonne=0,Obj_ligne=0,Obj_colonne=0;
char direction;
String Action="";
final int N=4;
/*N dimension de la carte, Action l'action que le joueur effectue, P_ligne/P_colonne et Obj_ligne/Obj_colonne respectivement les coordonnées du personnage et du trésor*/
do //on demande et vérifie la saisie de L
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
do //on demande et vérifie la saisie de C
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
do  //on demande et vérifie la saisie de la direction actuelle du personnage
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
do //on effectue le tirage de la position du trésor
  {
	Obj_ligne=(int)(Math.random()*N);
  }while(Obj_ligne==P_ligne);
do
  {
	Obj_colonne=(int)(Math.random()*N);
  }while(Obj_colonne==P_colonne);
  Ecran.afficher("L'objectif se trouve en : (",Obj_ligne,",",Obj_colonne,")");
  Ecran.sautDeLigne();
do//un pas est un déplacement
  {
	do{
		Ecran.afficher("Veuillez effectuer une action : entrer 'a' pour avancer d'une case dans la direction courrante, \n a suivis de e,o,n ou s pour avancer dans une autre direction (ex: taper 'ae' pour avancer d'une case a l'est), \n 'q' pour quitter le jeu ");
		Ecran.sautDeLigne();
		Ecran.afficher("Votre choix ? ");
		Action=Clavier.saisirString();
	}while(Action.length()>=3);
	if (Action=="q") //si on quitte le jeu
	{
		Ecran.afficher("Fermeture du jeu...");
		Ecran.sautDeLigne(); 
	}
	else //on avance
	{
		if(Action.length()==2) //si on avance dans la direction courrante
		{
			direction=Action.charAt(1);
		}
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
	}
	Ecran.afficher("P (",P_ligne,",",P_colonne,") - dir : ",direction); //on affiche la ouvelle position
	Ecran.sautDeLigne();
	if((P_ligne==Obj_ligne)&&(P_colonne==Obj_colonne)) //on gagne
	{
		Ecran.afficher("Vous avez trouvé le trésor. Bravo!");
		Ecran.sautDeLigne();
	}
	else	if(P_ligne==Obj_ligne) //on est sur la même ligne que le trésor
	{
		Ecran.afficher("Le trésor est sur la même ligne que votre personnage");
		Ecran.sautDeLigne();
	}
	else if(P_colonne==Obj_colonne) //on est sur la même colonne que le trésor
	{
		Ecran.afficher("Le trésor est sur la même colonne que votre personnage");
		Ecran.sautDeLigne();
	}
}while((P_ligne!=Obj_ligne || P_colonne!=Obj_colonne) && Action!="q");//tant que l'on ne trouve pas le trésor ou que l'on ne quitte pas le jeu
}
}
