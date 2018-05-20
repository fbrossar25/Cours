public class Exo4 {
	public static void main(String[]args){
		int val_lettre_min,val_lettre_maj;
		char lettre_min,lettre_maj;
		Ecran.afficher("Entrez un lettre minuscule ");
		lettre_min=Clavier.saisirChar();
		Ecran.sautDeLigne();
		val_lettre_min=(int)lettre_min;
		val_lettre_maj=val_lettre_min-((int)('a')-(int)('A'));
		lettre_maj=(char)val_lettre_maj;
		Ecran.afficher("la lettre ",lettre_min," à pour majuscule la lettre ",lettre_maj);
		Ecran.sautDeLigne();
	}
}

