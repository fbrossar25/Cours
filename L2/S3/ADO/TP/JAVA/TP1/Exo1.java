public class Exo1{
	//sans l'appel de forDigit on obtient que le nombre des dizaine en hexa à la place d'obtenir a,b,c,d,e ou f
	//pour afficher en binaire, pas besoin de la fonction forDigit
	//même chose pour l'octale
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
	
	public static long valChamp(long n, int msb, int lsb){
		long x,res=0;
		int i;
		if(lsb > msb) swap(msb,lsb);
		for(i=lsb; i<=msb;i++){
			x=((n<<i)>>>63)*2;
			res+=Math.pow(x,i);
		}
		System.out.println("res = "+res);
		return res;
	}
	
	public static void swap(long a, long b){
			long temp = a;
			a = b;
			b = temp;
	}
	
	public static void main (String[]args){
		long x1,x2,x3;
		long N1 = 0x405F500000000000L, N2 = 0xBFD8000000000000L;
		System.out.println(N1+" "+N2);
		System.out.println(Long.toHexString(N1)+" "+Long.toHexString(N2));
		System.out.println(ensembleHexa(N1)+"\n"+ensembleHexa(N2));
		System.out.println(ensembleBin(N1)+"\n"+ensembleBin(N2));
		System.out.println("N1 & N2 = "+(N1 & N2));
		System.out.println(ensembleBin(N1 & N2)+"\n");
		System.out.println(ensembleHexa(N1 & N2)+"\n");
		System.out.println("N1 | N2 = "+(N1 | N2));
		System.out.println(ensembleBin(N1 | N2)+"\n");
		System.out.println(ensembleHexa(N1 | N2)+"\n");
		System.out.println("N1 ^ N2 = "+(N1 ^ N2));
		System.out.println(ensembleBin(N1 ^ N2)+"\n");
		System.out.println(ensembleHexa(N1 ^ N2)+"\n");
		x1 = valChamp(N2,63,63);
		System.out.println("x1 = "+x1);
		x2 = valChamp(N2,62,52);
		System.out.println("x2 = "+x2);
		x3 = valChamp(N2,51,0);
		System.out.println("x3 = "+x3);
	}
}