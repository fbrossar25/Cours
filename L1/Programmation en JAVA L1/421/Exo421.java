public class Exo421 {
	
static int[] lancer (int [] jeu, boolean [] relance){
	int [] jeu2 = new int [4];
	int i;
	for(i=1;i<4;i++){
		if(relance[i])jeu2[i] = (int)(Math.random()*6)+1;
		else jeu2[i]=jeu[i];
	}
	return jeu2;
}	

static void affichage (int [] lancer, int n){
	Ecran.afficher("\nLancer ",n," : ");
	for(int i = 1;i<4;i++){
		Ecran.afficher(lancer[i]," ");
	}
	Ecran.afficher("\n\n");
}

static boolean[] calculRelance (int [] lancer){
	boolean [] relance = new boolean [4];
	Ecran.afficher();
	for(int i = 1;i<4;i++){
		if (lancer[i] == 1 || lancer[i] == 2 || lancer[i] == 4) relance[i]=false;
		else relance[i] = true;
	}
	return relance;
}

static boolean resultat (boolean [] relance){
	boolean res = true;
	int i =1;
	while(i<4 && !res){
		if (relance[i]) res = false;
		else i++;
	}
	return res;
} 

public static void main(String[]args){
	boolean [] relance = new boolean [4];
	int [] lancer = new int [4];
	int n=1;
	for(int i = 0;i<4;i++) {
		lancer[i] = (int)(Math.random()*6)+1;
		relance[i] = false;
	}		
	affichage(lancer,n);
	relance = calculRelance(lancer);
	while(!resultat(relance)){
		n++;
		lancer(lancer,relance);
		relance = calculRelance(lancer);
		affichage(lancer,n);
	}
	Ecran.afficher("Il a fallus ",n," lancers afin de gagner.\n");
}
}
