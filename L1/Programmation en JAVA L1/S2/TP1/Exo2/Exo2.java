public class Exo2 {
	static class position3D {
		double x = 0.0;
		double y = 0.0;
		double z = 0.0;
	}
	public static void main(String[]args){
		position3D P = new position3D();
		Ecran.afficher("Veuillez saisir les trois coordonnées (x,y,z) du point P \n");
		P.x=Clavier.saisirDouble();
		P.y=Clavier.saisirDouble();
		P.z=Clavier.saisirDouble();
		Ecran.afficher("Les coordonnées du point P est (",P.x,",",P.y,",",P.z,")");
		Ecran.sautDeLigne();
	}
}