public class Exo3a {
static final int NL=14;
static final int NC=20;

static class positionMatrice{
	int l = 0;
	int c= 0;
}
	
static void affichageMatriceInt(int [][] m){
  int l,c;
	for(l=0;l<m.length;l++){
		for(c=0;c<m[0].length;c++){
			Ecran.afficher("    ",m[l][c],"    "); //affichage à 3 chiffres après la virgule
		}
		Ecran.afficher("\n");
	}
}

static void calculDeplacementElementaireMatrice(int [][] m, positionMatrice p){
  int l,c;
	for(l=0;l<m.length;l++){
		for(c=0;c<m[0].length;c++){
			m[l][c]=Math.abs(l-p.l)+Math.abs(c-p.c);
		}
	}
}

public static void main(String[]args){
	
	int [][] m = new int [NL][NC];
	positionMatrice posDepart = new positionMatrice();
	
	//saisie de la position de départ du calcul du nombre de déplacement élémentaire
	Ecran.afficher("\nSVP saisir l'indice de la ligne de départ\n");
	posDepart.l=Clavier.saisirInt();
	Ecran.afficher("\nSVP saisir l'indice de la colonne de départ\n");
	posDepart.c=Clavier.saisirInt();
	
	calculDeplacementElementaireMatrice(m,posDepart);
	affichageMatriceInt(m);
}
}