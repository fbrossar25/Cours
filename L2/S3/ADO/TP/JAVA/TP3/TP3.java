public class TP3{
	
	static char forDigit(int n){
		char[] digits = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
		return digits[n & 0xF];
	}
	
	static String toString (int nombre, int base){
		String res="";
		boolean negatif = true;
		if((nombre & 0x80000000) == 0){
			nombre = -nombre;
			negatif = false;
		}
		do{
			res = forDigit(-(nombre % base)) + res;
			nombre /= base;
		}while(nombre !=0);
		if(negatif){
			res = "-"+res;
		}
		return res;
	}
	
	static int parseInt(String ch, int base){
		int res = 1;
		for(int i=1; i<ch.length(); i++){
			res *= base * digit(ch.charAt(i));
		}
		if (ch.charAt(0) == '-'){
			res = -res;
		}
		return res;
	}
	
	static int digit(char c){
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
	

	static int signum(int n){
		return (-n >>> 31) | (n>>31);
	}

	
	static int abs(int n){
		return (n & (-n >> 31)) | (-n & (n>>31));
	}
	
	public static void main(String[]args){
		System.out.println("500 = "+toString(500,10));
		System.out.println("-1000 = "+toString(-1000,10));
		System.out.println("0xFF = "+parseInt("+FF",16));
		System.out.println("-0xFF = "+parseInt("-FF",16));
		System.out.println("abs : 25 = "+abs(25));
		System.out.println("abs : -25 = "+abs(-25));
		System.out.println("signum : 25 = "+signum(25));
		System.out.println("signum : -25 = "+signum(-25));
		System.out.println("signum : 0 = "+signum(0));
	}
} 
