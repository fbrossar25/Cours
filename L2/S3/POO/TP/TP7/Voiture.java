class Voiture extends Vehicule{
	static private int nbVoit=0;
	Voiture(){
		nbVoit++;
		tarifDeBase = 60;
	}
	public void finalize(){
		nbVoit--;
	}
	static int getNombreInstances(){
		return nbVoit;
	}
}