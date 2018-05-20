public class Groupe{
	Personne p[];
	final int TAILLE;
	Groupe(int n){
		String nom="", prenom="";
		int poids,taille;
		p = new Personne [n];
		for(int i=0; i<n; i++){
			Ecran.afficherln("Nom de la personne ",i+1," : ");
			do {
				nom = Clavier.saisirString();
			}while(nom.equals(""));
			Ecran.afficherln("Prenom de la personne ",i+1," : ");
			do {
				prenom = Clavier.saisirString();
			}while(prenom.equals(""));
			Ecran.afficherln("Poids de la personne ",i+1," en Kg (entrez 0 si inconnu): ");
			poids = Clavier.saisirInt();
			Ecran.afficherln("Poids de la personne ",i+1," en cm (entrez 0 si inconnu): ");
			taille = Clavier.saisirInt();
			p[i] = new Personne(nom,prenom,poids,taille);
			nom = "";
			prenom = "";
			taille = 0;
			poids = 0;
			Ecran.sautDeLigne();
		}
		TAILLE = n;
	}
	Groupe(){
		this (5);
	}
	public String toString(){
		String pres="";
		for(int i=0;i<TAILLE;i++){
			pres = pres + p[i].prenom+" , "+p[i].nom+" , "+p[i].poids+" Kg "+p[i].taille+" cm  IMC : "+String.format("%.3f",p[i].calculIMC())+"\n";
		}
		return "taille du groupe : "+TAILLE+"\nnom , prenom :\n"+pres;
	}
}