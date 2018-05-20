public class Exo5 {
	public static void main(String[]args){
		int h,m,n,h2,m2;
		Ecran.afficher("Entrez un nombre d'heure ");
		h=Clavier.saisirInt();
		Ecran.afficher("Entrez un nombre de minute ");
		m=Clavier.saisirInt();
		Ecran.afficher("Entrez un deuxième nombre de minute ");
		n=Clavier.saisirInt();
		m2=m+n;
		h2=h;
		while(m>=60){
			m=m-60;
			h++;
		}
		while(m2>=60){
			m2=m2-60;
			h2++;
		}
		while(h2>=24){
			h2=h2-24;
		}
		Ecran.afficher("Il est ",h," heures et ",m," minutes. Plus tard, dans ",n," minutes il seras ",h2," heures et ",m2," minutes.");
		Ecran.sautDeLigne();
	}
}
