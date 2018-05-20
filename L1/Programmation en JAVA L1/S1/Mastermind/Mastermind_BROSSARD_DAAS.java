//programme réalisé par BROSSARD Florian et DAAS Zackaria du groupe A1 de L1 ST
public class MastermindV2_BROSSARD_DAAS {
public static void main (String [] args) {
int i=0,j=0,nb0=0,nb1=0,nb2=0,nb3=0,chiffre=0,tentatives_rest=10,noir=0,blanc=0;
String reponse="", proposition="";  
/*
i et j sont des compteurs, tentatives_rest représente le nombres tentatives restantes avant de perdre, noir et blanc représentent le nombre de pions de leurs couleure respectives
les différentes variables nb(0 à 3) sont les nombre tirées au hasard, ils sont utilisé pour construire la chaine réponse (en fonction de leurs valeurs) 
chiffre est une variable mémoire qui est utilisé pour construire la chaine reponse (il mémorise la valeur des variables nbx afin de les convertir 
reponse est la réponse tirée au hasard, proposition est la réponse saisie par le joueur
*/
boolean erreur_saisie=false,fin_jeu=false;
//si fin_jeu est vraie, le jeu s'arrete (10 coups tentés ou combinaison trouvée ou encore si un bug est survenus)
//erreur_saisie est un booléen qui est vraie si l'utilisateur à commis une erreur de saisie
for(i=0;i<=3;i++)
	{
		switch(i)  //on tire les 4 nombres qui serviront à construire la chaine reponse
		{
			case 0:{
				nb0=(int)((Math.random()*8)+1);
			}
			break;
			case 1:{
				nb1=(int)((Math.random()*8)+1);
				if(nb1==nb0)
				{
					i--; //on décrement i si nb1==nb0 ce qui fait recommencer le tirage
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
				Ecran.afficher("Une erreur est survenue. Arrêt du programme..."); // code mort
				Ecran.sautDeLigne();
				fin_jeu=true;
			}
		}
	}
//on construit la chaine réponse
for(i=0;i<=3;i++)
	{
		switch(i) //en fonction de i on change la valeur de chiffre pour lui assigner la valeur de nb0,1,2 ou 3
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
				Ecran.afficher("Une erreur est survenue. Arrêt du programme...");//code mort
				Ecran.sautDeLigne();
				fin_jeu=true;
			}
		}
		switch(chiffre) //en fonction de la valeur de chiffre on ajoute une lettre différente à la chaine réponse
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
				Ecran.afficher("Une erreur est survenue. Arrêt du programme...");//code mort
				Ecran.sautDeLigne();
				fin_jeu=true;
			}
		}
	}
//énonciations des règles
Ecran.afficher("Les règles sont :\n -Vous devez entrée une combinaison de 4 lettres MAJUSCULES \n -Les lettres possibles sont R,V,J,G,B,M,I,O et aucunes autres\n");
Ecran.sautDeLigne();
Ecran.afficher("reponse attendue : ",reponse); //on affiche la réponse
Ecran.sautDeLigne();
        do 
	{//un pas est une tentative
		do  
		{//saisie et vérification de la saisie
			erreur_saisie=false;
			Ecran.sautDeLigne();
			Ecran.afficher("Saisissez une combinaison de 4 lettres (R,B,G,J,V,O,I,M) : ");
			proposition=Clavier.saisirString();
			i=0;
			do
			{//vérification de la saisie du joueur
				if(proposition.length()==4) 
				{//si la longueur de la proposition = 4 alors...
					if((proposition.charAt(i)=='R')||(proposition.charAt(i)=='B')||(proposition.charAt(i)=='G')||(proposition.charAt(i)=='J')||  
					(proposition.charAt(i)=='V')||(proposition.charAt(i)=='O')||(proposition.charAt(i)=='I')||(proposition.charAt(i)=='M'))
					{//si les couleurs entrées sont correct alors ...
						do
						{
							if((j==i)||(proposition.charAt(j)!=proposition.charAt(i))) 
							{//s'il n'y a pas de doublons alors...
								erreur_saisie=false;
							}
							else   
							{//s'il y as des doublons alors...
								erreur_saisie=true;
							}
							j++;
						}while(erreur_saisie==false && j<=3);
						j=0;
						i++;
					}
					else  
					{//s'il y as une lettre non-autorisée alors...
						erreur_saisie=true;
					}
				}
				else 
				{//si la longueur de la chaine proposition est différente de 4 alors...
					erreur_saisie=true;
				}
			}while((i<=3)&&(erreur_saisie==false)); //tant que erreur_saisie est vraie et que i<=3 donc que toute ls lettres n'ont pas été testé on recommence
		}while(erreur_saisie==true);//tant que des erreurs de saisies sont détectées
		for(i=0;i<=3;i++) //on calcul le nombre de jetons noirs et blancs
		{
			if(proposition.charAt(i)==reponse.charAt(i)) 
			{//s'il y a un jeton noir alors...
				noir++;
			}
			else if(proposition.charAt(i)==reponse.charAt(0)||proposition.charAt(i)==reponse.charAt(1)||
                        proposition.charAt(i)==reponse.charAt(2)||proposition.charAt(i)==reponse.charAt(3))
                              {//s'il y a un jeton blanc alors...
                                blanc++;
                              }
		}
		tentatives_rest--; //on décremente le nombre de tentatives
                //on affiche les résultats
		if(proposition.equals(reponse))
		{//si le joueur gagne alors...
			Ecran.afficher("Vous avez trouvé la bonne combinaison en ",(10-tentatives_rest)," tentatives. Bravo!"); 
			Ecran.sautDeLigne();
			fin_jeu=true;
		}
		else
		{//si le joueur ne trouve pas la bonne réponse alors...
			if(tentatives_rest>0)
			{//si le joueurs  à encore n tentatives alors...
				Ecran.afficher("Vous avez ",noir," jetons noir(s)",blanc," jetons blanc(s). Il vous reste ",tentatives_rest," tentatives.\n"); 
				Ecran.sautDeLigne();
			}
			else
			{//si le joueurs à perdu alors...
				Ecran.afficher("Vous avez ",noir," jetons noir(s)",blanc," jetons blanc(s).");
				Ecran.sautDeLigne();
				Ecran.afficher("Vous n'avez pas réussis à trouvé la bonne combinaison. La bonne combinaison était \n",reponse); 
				Ecran.sautDeLigne();
				Ecran.afficher("GAME OVER !\n");
				fin_jeu=true;
			}
		}
		noir=0;
		blanc=0;
	}while(fin_jeu==false); //fin du jeu
/*
	Liste des tests effectués :
	On doit effectuer une autre saisie pour ces cas :
	Avec une lettre non autorisées (P), avec trois lettres ou moins, avec 5 lettres ou plus, avec 4 fois la même lettre autorisées (O), 
	même choses avec P, avec trois lettres autorisées différentes et une non autorisées
	Le fonctionne dans ces cas :
	4 lettres différentes autorisées (R,B,G,J,V,O,I,M)
*/
}
}

		
		
		