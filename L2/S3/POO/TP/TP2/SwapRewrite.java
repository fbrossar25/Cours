public class SwapRewrite{
	public static void swap (MonEntier a, MonEntier b){
		int tmp = a.val;
		a.val = b.val;
		b.val = tmp;
	}
	
	public static void main(String[] args){
		MonEntier a = new MonEntier(5);
		MonEntier b = new MonEntier(8);
		Ecran.afficherln("Avant echange : a = "+a.val+" ; b = "+b.val);
		swap(a,b);
		Ecran.afficherln("Après echange : a = "+a.val+" ; b = "+b.val);
	}
}