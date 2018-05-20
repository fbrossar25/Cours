class Moto extends Vehicule{
	static private int nbMoto=0;
	Moto(){
		nbMoto++;
		tarifDeBase = 20;
	}
	public void finalize(){
		nbMoto--;
	}
	static int getNombreInstances(){
		return nbMoto;
	}
}