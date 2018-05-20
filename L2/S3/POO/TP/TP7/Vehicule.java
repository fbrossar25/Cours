abstract class Vehicule{
	static private int nbInstances=0;
	protected int tarifDeBase;
	protected final int maj;
	Vehicule(){
		nbInstances++;
		maj = nbInstances - 1;
	}
	public void finalize(){
		nbInstances--;
	}
	static int getNombreInstances(){
		return nbInstances;
	}
	protected double getAugmentation(){
		return (0.05 * maj);
	}
	protected double getPrixTransport(){
		return (1.0 + getAugmentation()) * tarifDeBase;
	}
}