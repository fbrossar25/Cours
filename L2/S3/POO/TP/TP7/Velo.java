class Velo extends Vehicule{
	static private int nbVelo=0;
	Velo(){
		nbVelo++;
		tarifDeBase = 5;
	}
	public void finalize(){
		nbVelo--;
	}
	static int getNombreInstances(){
		return nbVelo;
	}
}