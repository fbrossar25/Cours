public class booleenTableau {
static final int N=20; //taille du tableau de booléens

static boolean[] tableauCharToBool(char [] tabChar){
	int i;
	boolean [] tabBool = new boolean[tabChar.length];
	for(i=0;i<N;i++){
		if(tabChar[i]=='1') tabBool[i] = true; // on remplis le tableau de booléens tabBool avec true pour les '1' et false pour les '0' de tabChar
		else tabBool[i] = false;
	}
	return tabBool;
}

public static void main (String [] args) {
	char [] tChar = new char [N];
	boolean [] tBool = new boolean [N];
	String c="";
	int i;
	do{
		Ecran.afficher("SVP, saisir une chaine de caractere contenant de 1 à ",N," caractere avec uniquement des 0 ou des 1 SANS espace \n") ;
		c=Clavier.saisirString();
	}while(c.length()<1 || c.length()>N);
	Ecran.sautDeLigne();
	for(i=0;i<c.length();i++){ //on complete le tableau de caractere
		tChar[i]=c.charAt(i);
	}
	tBool=tableauCharToBool(tChar);
	for(i=0;i<c.length();i++){
		if(tBool[i])Ecran.afficherln("\nBooléen ",i+1," = True\n");
		else Ecran.afficherln("\nBooléen ",i+1," = False\n");
	}
}
}