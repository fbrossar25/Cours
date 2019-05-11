public class GoGroupe{
	public static void main(String[] args){
		Ecran.afficherln("Taille du groupe ? ");
		Groupe etudiant = new Groupe (Clavier.saisirInt());
		Ecran.sautDeLigne();
		Ecran.afficher(etudiant);
	}
}