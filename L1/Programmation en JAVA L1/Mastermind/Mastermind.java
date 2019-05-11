public class Mastermind {
public static void main (String [] args) {
int chiffre=0,i=0,tirage=0,nb0=0,nb1=0,nb2=0,nb3=0,tentatives=10,noir=0,blanc=0;
String reponse="", proposition="";  
/*
i et j sont des compteurs, tentatives repr�sente le nombres tentatives jou�es, noir et blanc repr�sentent le nombre de pions de leurs couleur respectives
les diff�rentes variables nb(0 � 3) sont les nombre class� par ordre, ils sont utilis� pour m�moris� les nombre tir�s au hasard et pour faire des comparaisons 
afin de ne pas avoir de chiffre en double
chiffre est une variable (m�moire) qui est utilis� pour construire la chaine reponse
reponse est la r�ponse tir�e au hasard, proposition est la r�ponse saisie par le joueur
*/
boolean fin_jeu=false;
//si fin_jeu est vraie , le jeu s'arrete (10 coups tent�s ou combinaison trouv�e ou encore un bug est survenus)
for(i=0;i<=3;i++)	//On calcul la combinaison secr�te (pas de couleur en double)
	{
		switch(i)
		{
			case 0:{
				nb0=(int)((Math.random()*8)+1);
			}
			break;
			case 1:{
				nb1=(int)((Math.random()*8)+1);
				if(nb1==nb0)
				{
					i--;
				}
			}
			break;
			case 2:{
				nb2=(int)((Math.random()*8)+1);
				if((nb2==nb0)||(nb2==nb1))
				{
					i--;
				}
			}
			break;
			case 3:{
				nb3=(int)((Math.random()*8)+1);
				if((nb3==nb0)||(nb3==nb1)||(nb3==nb2))
				{
					i--;
				}
			}
			break;
			default:{
				Ecran.afficher("Une erreur est survenue. Arr�t du programme...");
				Ecran.sautDeLigne();
				fin_jeu=true;
			}
		}
	}
//on construit la chaine r�ponse
for(i=0;i<=3;i++)
	{
		switch(i)
		{
			case 0:{
				chiffre=nb0;
			}
			break;
			case 1:{
				chiffre=nb1;
			}
			break;
			case 2:{
				chiffre=nb2;
			}
			break;
			case 3:{
				chiffre=nb3;
			}
			break;
			default:{
				Ecran.afficher("Une erreur est survenue. Arr�t du programme...");
				Ecran.sautDeLigne();
				fin_jeu=true;
			}
		}
		switch(chiffre)
		{
			case 1:{reponse=reponse+'R';}break;
			case 2:{reponse=reponse+'B';}break;
			case 3:{reponse=reponse+'G';}break;
			case 4:{reponse=reponse+'J';}break;
			case 5:{reponse=reponse+'V';}break;
			case 6:{reponse=reponse+'O';}break;
			case 7:{reponse=reponse+'I';}break;
			case 8:{reponse=reponse+'M';}break;
			default:{
				Ecran.afficher("Une erreur est survenue. Arr�t du programme...");
				Ecran.sautDeLigne();
				fin_jeu=true;
			}
		}
	}
//�nonciations des r�gles
Ecran.afficher("Les r�gles sont :\n -Vous devez entr�e une combinaison de 4 lettres MAJUSCULES \n -Les lettres possibles sont R,V,J,G,B,M,I,O et aucunes autres");
Ecran.afficher("\n\nBonne combinaison : ",reponse,"\n\n");
	while((tentatives>0) || (!fin_jeu))
	{
		do
		{
		Ecran.afficher("Saisissez une combinaison de 4 lettres (R,B,G,J,V,O,I,M) : ");
		proposition=Clavier.saisirString();
		}while(proposition.length()!=4);
		for(i=0;i<=3;i++) //on calcul le nombre de jetons
		{
			if(proposition.charAt(i)==reponse.charAt(i)) //jetons noirs
			{
				noir++;
			}
			//jetons blanc
			if(proposition.charAt(i)==reponse.charAt(0)||proposition.charAt(i)==reponse.charAt(1)||proposition.charAt(i)==reponse.charAt(2)||proposition.charAt(i)==reponse.charAt(3))
			{
				blanc++;
			}
			// si un des jetons blanc correspond � un noir, on enl�ve un jetons blanc
			if(proposition.charAt(i)==reponse.charAt(i))
			{
				blanc--;
			}
		}
		tentatives--; //on d�cremente le nombre de tentatives
		if(proposition.equals(reponse))
		{
			Ecran.afficher("Vous avez trouv� la bonne combinaison en ",tentatives," tentatives. Bravo!"); //le joueur gagne
			Ecran.sautDeLigne();
			System.exit(0);
		}
		else
		{
			if(tentatives>0)
			{
				Ecran.afficher("Vous avez ",noir," jetons noir(s)",blanc," jetons blanc(s). Il vous reste ",tentatives, "tentatives.\n"); //le joueurs  � encore n tentatives
				Ecran.sautDeLigne();
			}
			else
			{
				Ecran.afficher("Vous avez ",noir," jetons noir(s)",blanc," jetons blanc(s).");
				Ecran.sautDeLigne();
				Ecran.afficher("Vous n'avez pas r�ussis � trouv� la bonne combinaison. La bonne combinaison �tait \n",reponse); //le joueurs  � encore n tentatives
				Ecran.sautDeLigne();
				Ecran.afficher("GAME OVER !");
				fin_jeu=true;
			}
		}
		noir=0;
		blanc=0;
	}
}
}

		
		
		