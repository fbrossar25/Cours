public class Exo3b {
static final int NL=14;
static final int NC=20;

static class positionMatrice{
	int l = 0;
	int c= 0;
}
	
static void affichageMatriceBooleen(boolean [][] m){
int l,c;
char bool;
	for(l=0;l<m.length;l++){
		for(c=0;c<m[0].length;c++){
			if (m[l][c]) bool='O';
			else bool ='X';
			Ecran.afficher("    ",bool,"    ");
		}
		Ecran.afficher("\n");
	}
}

static boolean[][] remplissageTerritoire(int [][] m , boolean [][] b , int tailleTerritoire){
	int l,c;
	for(l=0;l<NL;l++){
		for(c=0;c<NC;c++){
			if(m[l][c]<=tailleTerritoire){
				b[l][c]=true;
			}
		}
	}
	return b;
}

static int[][] matriceDesDistances(positionMatrice p){
  int l,c;
  int [][] m = new int [NL][NC];
	for(l=0;l<NL;l++){
		for(c=0;c<NC;c++){
			m[l][c]=Math.abs(l-p.l)+Math.abs(c-p.c);
		}
	}
	return m;
}

static int[][] territoireAtteignable(boolean [][] matriceTerritoire , positionMatrice p){
	boolean territoireJoueur = matriceTerritoire[p.l][p.c];
	int [][] territoireAtteignable = new int [NL][NC];
	int l,c;
	for(l=0;l<matriceTerritoire.length;l++){
		for(c=0;c<matriceTerritoire[0].length;c++){
			if(celluleAtteignable(territoireJoueur,matriceTerritoire[l][c])){
				territoireAtteignable[l][c]=distanceCellule(p,l,c);
			}
			else territoireAtteignable[l][c]=-1;
		}
	}
	return territoireAtteignable;
}

static boolean celluleAtteignable(boolean territoireJoueur, boolean territoire){
	boolean atteignable = false;
	if(territoireJoueur==territoire) atteignable = true;
	return atteignable;
}

static int distanceCellule(positionMatrice p, int l, int c){
	int d = 0;
	d=Math.abs(l-p.l)+Math.abs(c-p.c);
	return d;
}

static void affichageMatriceInt(int [][] m){
  int l,c;
	for(l=0;l<m.length;l++){
		for(c=0;c<m[0].length;c++){
			Ecran.afficher("    ",m[l][c],"    ");
		}
		Ecran.afficher("\n");
	}
}

static void affichageMatriceIntGraphique(int [][] m){
	int xFenetre=m[0].length*30;
	int yFenetre=m.length*30;
	int xCellule,yCellule;
	int l,c;
	String nombre;
	EcranGraphique.setClearColor(255,255,255);
	EcranGraphique.clear();
	EcranGraphique.init(50,50,xFenetre+30,yFenetre+30,xFenetre,yFenetre,"Matrice Entier");
	EcranGraphique.setColor(0,0,200);
	for(l=0;l<m.length;l++){
		yCellule=30+l*30;
		for(c=0;c<m[0].length;c++){
			nombre=Integer.toString(m[l][c]);
			xCellule=c*30;
			EcranGraphique.drawString(xCellule,yCellule,3,nombre);
		}
	}
	EcranGraphique.flush();
}

static void affichageMatriceBoolGraphique(boolean [][] m){
	int xFenetre=m[0].length*30;
	int yFenetre=m.length*30;
	int xCellule,yCellule;
	int l,c;
	String bool;
	EcranGraphique.setClearColor(255,255,255);
	EcranGraphique.clear();
	EcranGraphique.init(50,50,xFenetre+30,yFenetre+90,xFenetre,yFenetre,"Matrice Booleen");
	EcranGraphique.setColor(0,0,200);
	for(l=0;l<m.length;l++){
		yCellule=30+l*30;
		for(c=0;c<m[0].length;c++){
			if(m[l][c])bool="O";
			else bool="X";
			xCellule=c*30;
			EcranGraphique.drawString(xCellule,yCellule,3,bool);
		}
	}
	EcranGraphique.flush();
}

public static void main(String[]args){
	
	int [][] matriceDistance = new int [NL][NC];
	boolean [][] matriceTerritoire = new boolean [NL][NC];
	positionMatrice posTerritoire = new positionMatrice();
	positionMatrice posActuelle = new positionMatrice();
	int [][] matriceDistanceAtteignable = new int [NL][NC];
	
	do{
		Ecran.afficher("\nSVP saisir l'indice de la ligne de depart du territoire O\n");
		posTerritoire.l=Clavier.saisirInt();
		if(posTerritoire.l<0 || posTerritoire.l>NL-1) Ecran.afficherln("Saisir un entier entre 0 et ",NL);
	}while(posTerritoire.l<0 || posTerritoire.l>NL-1);
	do{
		Ecran.afficher("\nSVP saisir l'indice de la colonne de depart du territoire O\n");
		posTerritoire.c=Clavier.saisirInt();
		if(posTerritoire.c<0 || posTerritoire.c>NC-1) Ecran.afficherln("Saisir un entier entre 0 et ",NC);
	}while(posTerritoire.c<0 || posTerritoire.c>NC-1);
	matriceDistance=matriceDesDistances(posTerritoire);
	matriceTerritoire=remplissageTerritoire(matriceDistance,matriceTerritoire,14);
	affichageMatriceBooleen(matriceTerritoire);
	affichageMatriceBoolGraphique(matriceTerritoire);
	do{
		Ecran.afficherln("\n Sur quel indice de ligne etes-vous ?");
		posActuelle.l=Clavier.saisirInt();
		if(posActuelle.l<0 || posActuelle.l>NL-1) Ecran.afficherln("Saisir un entier entre 0 et ",NL);
	}while(posActuelle.l<0 || posActuelle.l>NL-1);
	do{
		Ecran.afficherln("\n Sur quel indice de colonne etes-vous ?");
		posActuelle.c=Clavier.saisirInt();
		if(posActuelle.c<0 || posActuelle.c>NC-1) Ecran.afficherln("Saisir un entier entre 0 et ",NC);
	}while(posActuelle.c<0 || posActuelle.c>NC-1);
	matriceDistanceAtteignable=territoireAtteignable(matriceTerritoire,posActuelle);
	affichageMatriceInt(matriceDistanceAtteignable);
	affichageMatriceIntGraphique(matriceDistanceAtteignable);
	do{
		Ecran.afficherln("\n Taper q pour quitter.");
	}while(Clavier.saisirChar()!='q');
	EcranGraphique.exit();
}
}