public class Personne{
	String nom;
	String prenom;
	int poids;
	int taille;
	Personne(String nom, String prenom, int poids, int taille){
		this.nom=nom;
		this.prenom=prenom;
		this.poids=poids;
		this.taille=taille;
	}
	Personne(String nom, String prenom){
		this (nom,prenom,0,0);
	}
	double calculIMC(){
		double IMC = 0.0;
		if(taille > 0.0) IMC = ((1.0 * poids) / ((taille * 0.01) * (taille * 0.01)));
		return IMC;
	}
	public String toString(){
		return nom+", "+prenom+" ("+poids+" Kg, "+taille+" cm) : IMC = "+String.format("%.3f",calculIMC());
	}
}