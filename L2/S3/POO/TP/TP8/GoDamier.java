public class GoDamier{
	public static void main(String [] args){
		int n=0;
		Damier jeux = new Damier(22,32);
		jeux.setRandMur(30);
		jeux.setRandBalle(20);
		while(n<10){
			//System.out.println(jeux);
			jeux.affichageGraphique();
			Damier.pause(1000);
			//Ecran.afficherln("\n\nn = ",n,"\n\n");
			jeux.evolution();
			n++;
		}
		while(EcranGraphique.getKey() == 0){}
		System.exit(0);
	}
}