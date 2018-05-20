public class GoFerry{
	public static void main(String[]args){
		Ferry ferry = new Ferry();
		ferry.addVehicule(3);
		ferry.addVehicule(1);
		ferry.addVehicule(2);
		ferry.addVehicule(1);
		ferry.addVehicule(3);
		ferry.addVehicule(-1);
		ferry.addVehicule(1);
		System.out.println("Recette  = "+ferry.recette());
		System.out.println("Nombre de voiture(s) : "+ferry.getNbVoiture());
		System.out.println("Nombre de moto(s) : "+ferry.getNbMoto());
		System.out.println("Nombre de velo(s) : "+ferry.getNbVelo());
	}
}