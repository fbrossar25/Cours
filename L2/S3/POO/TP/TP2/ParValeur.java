public class ParValeur{
	public static void swap (int a, int b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	public static void main(String[] args){
		int a=5, b=8;
		Ecran.afficherln("Avant echange : a = "+a+" ; b = "+b);
		swap(a,b);
		Ecran.afficherln("Après echange : a = "+a+" ; b = "+b);
	}
}
//le swap n'as pas eu lieu car il n'a lieu que localement