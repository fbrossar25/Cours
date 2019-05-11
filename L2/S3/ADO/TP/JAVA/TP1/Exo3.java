public class Exo3{
	
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
		return ((x!=0) && ((x & (x-1)) == 0));
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
	
	public static char forDigitPerso(long n){
		char c = ' ';
		if(n < 10){
			c = (char)(n+'0');
		}
		else{
			c = (char)(n-10+'A');
		}
		return c;
	}
	
	static char forDigit(int n){
		char[] digits = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
		return digits[n & 0xF];
	}
	
	static int digit(char c){
		int res;
		int[] entier = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
		if (c>='A' && c<='F') res = entier[(int)(c-0x41)+10];
		else if (c>='a' && c<='f') res = entier[(int)(c-0x61)+10];
		else res = (int)(c-0x30);
		return res;
	}
	
	static int digitPerso(char c){
		int res = 0;
		if(c >= '0' && c <= '9'){
			res = (int)(c-'0');
		}
		else if (c >= 'a' && c<='f'){
			res = (int)(c-'a')+10;
		}
		else if (c >= 'A' && c<='F'){
			res = (int)(c-'A')+10;
		}
		return res;
	}
	
	static long bitCountPerso(long i){
		i = i - ( ( i >>> 1 ) & 0x5555555555555555L ) ;
		i = ( i & 0x3333333333333333L ) + ( ( i >>> 2 ) & 0x3333333333333333L ) ;
		i = ( i + ( i >>> 4 ) ) & 0x0f0f0f0f0f0f0f0fL ;
		i = i + ( i >>> 8 ) ;
		i = i + ( i >>> 16 ) ;
		i = i + ( i >>> 32 ) ;
		return (i & 0x7f) ;
	}
	
	public static void main(String[] args){
		long N1 = 0x405F500000000000L, N2 = 0xBFD8000000000000L;
		long A = 0x7FFFFFFFFFFFFFFFL, B = 0xFFFFFFFFFFFFFFFFL;
		int x,y;
		char c;
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
		System.out.println("nombre de bits à 1 dans A = "+Long.bitCount(A));
		System.out.println("nombre de bits à 1 dans A (perso) = "+bitCountPerso(A));
		System.out.println("Saisir y (entier >= 0 ET <16): ");
		do{
			y=Clavier.saisirInt();
		}while( (y<0) || (y>15) );
		System.out.println("Fonction API : "+y+" = 0x"+Character.forDigit(y,16));
		System.out.println("Fonction Perso : "+y+" = 0x"+forDigitPerso(y));
		System.out.println("Fonction TP : "+y+" = 0x"+forDigit(y));
		System.out.println("nombre de bits à 1 dans A = "+Long.bitCount(A));
		System.out.println("Saisir c (caractère alphabétique de 0 à F en majuscule ou minuscule): ");
		do{
			c=Clavier.saisirChar();
		}while( (c<'0') || (c>'F') && (c<'a' || c>'f') );
		System.out.println("Fonction API : "+c+" = "+Character.digit(c,16));
		System.out.println("Fonction Perso : "+c+" = "+digitPerso(c));
		System.out.println("Fonction TP : "+c+" = "+digit(c));
	}
}