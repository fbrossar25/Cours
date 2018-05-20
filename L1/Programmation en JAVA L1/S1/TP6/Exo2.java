public class Exo2 {
public static void main(String[]args)
  {
	int nb_allumettes=17,tirage_al,choix,nb_retirer;
	  //nb_allumettes représente le nombre d'allumettes
	  //tirage_al est le nombre d'alumettes tirées au hasard entre 1 et 3 par l'ordinateur
	  //choix représente le choix de l'utilisateur
	  //nb_retirer représente le nombre d'allumettes que le joueur veut retirer
	boolean VS_IA=true,fin_jeu=false;
	  //fin_jeu est le booléen qui arrete le jeu (victoire ou défaite d'un des adversaires)
	  //VS_IA est un booléen représentant si le joueur veut jouer contre l'ordinateur (true) ou non (false)
	Ecran.afficher("Jeux des allumettes\n");
	Ecran.sautDeLigne();
	Ecran.afficher("Voulez vous jouez contre l'ordinateur ou contre un adversaire ? \n entrez 1 pour l'ordinateur, 0 pour l'adversaire ");
	choix=Clavier.saisirInt();
	  Ecran.sautDeLigne();
	switch(choix)
	  {
		  case 1:{
			  VS_IA=true; //on joue contre l'ordinateur
		  }
		  break;
		  case 0:{
			  VS_IA=false; //on joue contre un adversaire (ou soi même)
		  }
		  break;
		  default :{
			  Ecran.afficher("une erreur est survenue\n");
			  fin_jeu=true;
			  Ecran.sautDeLigne();
		  }
	  }
	  if(VS_IA=true){
		  Ecran.afficher("Les règles sont : \n-Il y a 17 allumettes \n-On ne peu en retirer que 1,2 ou 3 et pas plus qu'il n'en reste \n-on entre le chiffre correspondant au nombre d'allumettes à retirées \n-May the force be with you\n");
		  Ecran.sautDeLigne();
		  while(fin_jeu=false);{
			if (nb_allumettes <=3 && nb_allumettes >0){
				do{
					tirage_al=(int)(Math.random()*3)+1;
				}while(tirage_al>=3);
				nb_allumettes = nb_allumettes - tirage_al;
				Ecran.afficher("L'ordinateur enlève ",tirage_al," allumettes. Il reste ",nb_allumettes," allumettes\n");
				Ecran.sautDeLigne();
				if(nb_allumettes==1){
					Ecran.afficher("Vous avez perdu \n");
					fin_jeu=true;
				}
				else{
					Ecran.afficher("A vous de jouez  \n");
					do{
						Ecran.afficher("Combien d'allumettes voulez-vous enlevez ? (1,2 ou 3)");
						nb_retirer=Clavier.saisirInt();
					}while(nb_retirer!=1 && nb_retirer!=2 && nb_retirer!=3);
					nb_allumettes = nb_allumettes - nb_retirer;
					Ecran.afficher("Vous enlevé ",nb_retirer," allumettes. Il reste ",nb_allumettes," allumettes\n");
				}
				if(nb_allumettes==1){
					Ecran.afficher("Vous avez gagnez \n");
					fin_jeu=true;
				}
			}
		  }
	  }
	  else{
		  Ecran.afficher("Les règles sont : \n-Il y a 17 allumettes \n-On ne peu en retirer que 1,2 ou 3 et pas plus qu'il n'en reste \n-on entre le chiffre correspondant au nombre d'allumettes à retirées \n-May the force be with you\n");
		  Ecran.sautDeLigne();
		  Ecran.afficher("J'ai pas finis cette partie");
		  Ecran.sautDeLigne();
	  }
  }
  }
	