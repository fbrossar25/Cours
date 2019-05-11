public class GoPersonne{
	public static void main(String[] args){
		String prenom="",nom = "";
		int poids, taille;
		Ecran.afficherln("Saisir un nom : ");
		nom = Clavier.saisirString();
		Ecran.afficherln("Saisir un prenom : ");
		prenom = Clavier.saisirString();
		Personne p1 = new Personne(nom,prenom);
		Ecran.afficherln("Saisir un nom : ");
		nom = Clavier.saisirString();
		Ecran.afficherln("Saisir un prenom : ");
		prenom = Clavier.saisirString();
		Ecran.afficherln("Saisir un poids (entier attendu) : ");
		poids = Clavier.saisirInt();
		Ecran.afficherln("Saisir une taille en cm (entier attendu) : ");
		taille = Clavier.saisirInt();
		Personne p2 = new Personne(nom,prenom,poids,taille);
		Ecran.afficherln(p1);
		Ecran.afficherln(p2);
	}
}