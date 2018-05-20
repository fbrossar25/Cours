public class Exo3 {
	public static void main(String[]args){
		int nombre,compteur=0;
		final int N=3;
		do
		{
			compteur++;
			nombre=(int)(Math.random()*51)+5; //math.random()*(max + 1 - min) + min pour avoir un nombre entre min et max compris
			Ecran.afficher("nombre aléatoire : ",nombre);
			Ecran.sautDeLigne();
		}while(nombre%N!=0);
		Ecran.afficher("On a tiré au hasard ",compteur," fois un nombre entre 5 et 55 compris.");
		Ecran.sautDeLigne();
	}
}