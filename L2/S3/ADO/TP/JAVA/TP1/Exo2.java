public class Exo2{
	
	public static String ensembleHexa(long n){
		int i;
		String s="";
		for(i=1;i<17;i++){
			s=s+Character.forDigit((int)(n>>>60),16);
			if ((i & 3)==0) s=s+" ";
			n = n << 4;
		}
		return s;
	}
	
	//forDigit n'est plus indispensable
	public static String ensembleBin(long n){
		int i;
		String s="";
		for(i=1;i<65;i++){
			s=s+(int)(n>>>63);
			if ((i & 3)==0) s=s+" ";
			n = n<<1;
		}
		return s;
	}
	
	static boolean fonction(int x){ //ya-til plus d'un bit à 1 <=> x est-il une puissance de 2 ?
		return ((x & (x-1)) == 0);
	}
	
	static boolean testSuperieurUnsignedInt(long a, long b){
		if(a==b) return false;
		else{
			while((a>>>63)==(b>>>63)){
				a=a<<1;
				b=b<<1;
			}
		}
		return ((a>>>63)==1);
	}
	
	
	
	public static void main(String[] args){
		long N1 = 0x405F500000000000L, N2 = 0xBFD8000000000000L;
		long A = 0x7FFFFFFFFFFFFFFFL, B = 0xFFFFFFFFFFFFFFFFL;
		int x;
		System.out.println("N1 =                        "+ensembleBin(N1));
		System.out.println("N2 =                        "+ensembleBin(N2));
		System.out.println("N1 r à gauche de 1 = "+ensembleBin(Long.rotateLeft(N1,1)));
		System.out.println("N2 r à gauche de 1 = "+ensembleBin(Long.rotateLeft(N2,1)));
		System.out.println("N1 r à gauche de 8 = "+ensembleBin(Long.rotateLeft(N1,8)));
		System.out.println("N2 r à gauche de 8 = "+ensembleBin(Long.rotateLeft(N2,8)));
		System.out.println("N1 r à droite de 1 =   "+ensembleBin(Long.rotateRight(N1,1)));
		System.out.println("N2 r à droite de 1 =   "+ensembleBin(Long.rotateRight(N2,1)));
		System.out.println("N1 r à droite de 8 =   "+ensembleBin(Long.rotateRight(N1,8)));
		System.out.println("N2 r à droite de 8 =   "+ensembleBin(Long.rotateRight(N2,8)));
		System.out.println("Saisir x : ");
		x=Clavier.saisirInt();
		if(fonction(x)){
			System.out.println("x est une puissance de 2");
		}
		else{
			System.out.println("x n'est pas une puissance de 2");
		}
		if(testSuperieurUnsignedInt(A,B)){
			System.out.println("A > B");
		}
		else{
			System.out.println("A <= B");
		}
		
	}
}