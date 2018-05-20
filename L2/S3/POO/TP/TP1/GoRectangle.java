public class GoRectangle{
	public static void main(String[] args){
		rectangle r = new rectangle();
		int l,h;
		Ecran.afficherln("\nSaisir la hauteur du rectangle (entier > 0)");
		do{
			h=Clavier.saisirInt();
		}while(h<=0);
		Ecran.afficherln("\nSaisir la longueur du rectangle (entier > 0)");
		do{
			l=Clavier.saisirInt();
		}while(l<=0);
		r.setSize(h,l);
		r.dessinePlein();
		Ecran.afficher("\n\n");
		r.dessineCreux();
	}
}