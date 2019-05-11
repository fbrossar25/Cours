class TP4{
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
		return "0x"+s;	
	}
	
	static int getSigne(int n){
		return (n >>> 31);
	}
	
	static float setSigne(int n){
		return (n << 31);
	}
	
	static int getExposant(int n){
		return ((n & 0x7F800000)>>>23);
	}
	
	static float setExposant(int n){
		return 
	}
	
	static int getMantisse(int n){
		return (n & 0x007FFFFF);
	}
	
	static void afficherDecompositionFloat(float f){
		System.out.println("Signe = "+getSigne(Float.floatToIntBits(f)));
		System.out.println("Exposant = "+getExposant(Float.floatToIntBits(f)));
		System.out.println("Mantisse = "+toHexString(getMantisse(Float.floatToIntBits(f))));
	}
	
	public static void main(String[]args){
		float f1=125.25f, f2=0.375f, f3=-0.375f;
		double d1=125.25, d2=0.375, d3=-0.375;
		int y=1;
		System.out.println("f1 = "+f1+" = "+toHexString(Float.floatToIntBits(f1)));
		System.out.println("f2 = "+f2+" = "+toHexString(Float.floatToIntBits(f2)));
		System.out.println("f3 = "+f3+" = "+toHexString(Float.floatToIntBits(f3)));
		System.out.println("d1 = "+d1+" = "+toHexString(Double.doubleToLongBits(d1)));
		System.out.println("d2 = "+d2+" = "+toHexString(Double.doubleToLongBits(d2)));
		System.out.println("d3 = "+d3+" = "+toHexString(Double.doubleToLongBits(d3)));
		while(y+1 == y){
			y++;
		}
		System.out.println("y-1 = "+(y-1));
		System.out.println("Décomposition de "+f1);
		afficherDecompositionFloat(f1);
		System.out.println("\n\n");
		System.out.println("Décomposition de "+f2);
		afficherDecompositionFloat(f2);
		System.out.println("\n\n");
		System.out.println("Décomposition de "+f3);
		afficherDecompositionFloat(f3);
		System.out.println("\n\n");
	}
}