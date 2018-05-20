public class Exo2 {
	public static void main(String[]args){
		long TM,N_Go;
		int N_Mo,N_Ko,N_o;
		Ecran.afficher("Entrez un nombre d'octets entier à convertir : ");
		TM=Clavier.saisirLong();
		Ecran.sautDeLigne();
		N_o=(int)(TM % 1024);
		TM=TM/1024;
		N_Ko=(int)(TM % 1024);
		TM=TM/1024;
		N_Mo=(int)(TM % 1024);
		TM=TM/1024;
		N_Go=TM%1024;
		Ecran.afficher("La valeur convertie vaut : ",N_Go,"Go ",N_Mo,"Mo ",N_Ko,"Ko ",N_o,"o.");
	}
}
