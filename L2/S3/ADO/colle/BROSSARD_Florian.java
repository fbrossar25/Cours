public class BROSSARD_Florian{
	static int bitCountSansBoucle(int n){
		n -=  ( ( n >>> 1 ) & 0x55555555 );
		n = ( n & 0x33333333 ) + ( ( n >>> 2 ) & 0x33333333 );
		n = ( n + ( n >>> 4 ) ) & 0x0f0f0f0f;
		n +=  ( n >>> 8 );
		n +=  ( n >>> 16 );
		return (n & 0x3f);
	} 
	
	static int bitCountAvecBoucle(int n){
		int res = 0;
		for(int i=0; i<32; i++){
			res += (n>>i) & 0x1;
		}
		return res;
	}
	
	public static void main (String[]args){
		int a = 0xffffffff;
		int b = 0xf000000f;
		int c = 0x10;
		System.out.println("Test bitCountSansBoucle : \n");
		System.out.println("Nombre de bits a 1 dans "+a+" = "+bitCountSansBoucle(a));
		System.out.println("Nombre de bits a 1 dans "+b+" = "+bitCountSansBoucle(b));
		System.out.println("Nombre de bits a 1 dans "+c+" = "+bitCountSansBoucle(c));
		System.out.println("\nTest bitCountAvecBoucle : \n");
		System.out.println("Nombre de bits a 1 dans "+a+" = "+bitCountAvecBoucle(a));
		System.out.println("Nombre de bits a 1 dans "+b+" = "+bitCountAvecBoucle(b));
		System.out.println("Nombre de bits a 1 dans "+c+" = "+bitCountAvecBoucle(c));
	}
}
