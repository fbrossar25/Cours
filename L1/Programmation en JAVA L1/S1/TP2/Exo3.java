public class Exo3 {
	public static void main(String[]args){
		float longueur,largeur,surface;
		int N_pots;
		Ecran.afficher ("Saisir une longueur ");
		longueur=Clavier.saisirFloat();
		Ecran.afficher ("Saisir une largeur ");
		largeur=Clavier.saisirFloat();
		Ecran.sautDeLigne();
		surface=longueur*largeur;
		N_pots=(int)(surface/6);//un pot recouvre 6m² et on arrondi a l'entier au dessus
		if((surface%6) != 0) N_pots++;
		Ecran.afficher("Le perimetre d'un rectangle de longueur ",longueur,"m et de largeur ",largeur,"m est : ",surface,"m. Il vous faudras ",N_pots," pots afin de tout repeindre");
		Ecran.sautDeLigne();
	}
}
