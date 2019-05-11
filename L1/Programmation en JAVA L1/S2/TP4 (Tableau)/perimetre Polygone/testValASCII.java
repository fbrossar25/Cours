public class testValASCII {
public static void main (String [] args) {
	int n;
	char c;
do{
	Ecran.afficherln("\n0 pour afficher la valeur d'un caractere, autre entier pour le caractere d'une valeur : ");
	if(Clavier.saisirInt()==0){
		Ecran.afficherln("\nSVP saisir un caractere : ");
		c=Clavier.saisirChar();
		n=(int)c;
		Ecran.afficherln("Valeur du caractere ",c," = ",n);	
	}
	else{		
		Ecran.afficherln("\nSVP saisir une valeur de la table ASCII : ");
		n=Clavier.saisirInt();
		c=(char)n;
		Ecran.afficherln("\nCaractere de valeur ",n," = ",c);
	}
}while(1==1);
}
}