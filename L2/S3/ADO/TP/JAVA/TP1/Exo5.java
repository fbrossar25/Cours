public class Exo5{
	
	static String toString(long n){
		String s="";
		do{
			s = forDigit((int)(n%10)) + s;
			n /= 10;
		}while(n!=0);
		return s;
	}
	
	static char forDigit(int n){
		char[] digits = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
		return digits[n & 0xF];
	}
	
	static String toHexString(long n){
		String s="";
		do{
			s = forDigit((int)((n<<60)>>>60)) + s;
			n = n >>> 4;
		}while(n!=0);
		return s;	
	}
	
	static String toBinaryString(long n){
		String s="";
		do{
			s = forDigit((int)((n<<63)>>>63)) + s;
			n = n >>> 1;
		}while(n!=0);
		return s;	
	}
	
	static String toOctalString(long n){
		String s="";
		do{
			s = forDigit((int)((n<<61)>>>61)) + s;
			n = n >>> 3;
		}while(n!=0);
		return s;	
	}
	
	public static void main(String[]args){
		long N1 = 0x405F500000000000L, N2 = 0xBFD8000000000000L;
		long N3 = 999999999999999L;
		System.out.println("N1 = "+Long.toString(N1));
		System.out.println("N2 = "+Long.toString(N2));
		System.out.println("N1 perso= "+toString(N1));
		System.out.println("N2 perso= "+toString(N2));
		//N2 est un nombre négatif car signé donc toString ne revoie pas le bon résultat
		System.out.println("N3  (décimale) = "+N3);
		System.out.println("N3 = 0x"+toHexString(N3));
		System.out.println("N3 = 0b"+toBinaryString(N3));
		System.out.println("N3 (octale) = "+toOctalString(N3));
	}
}