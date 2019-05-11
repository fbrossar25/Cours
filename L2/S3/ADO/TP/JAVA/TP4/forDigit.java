class forDigit{
	public static void main(String[]args){
		int n=256;
		int count = 0,save=n;
		char c;
		System.out.print("0x");
		do{
			n = n >>> 28;
			if((n-9)<=0) c = (char)(n + '0');
			else  c = (char)(n + 7 +'0');
			System.out.print(c);
			count++;
			save = save << 4;
			n = save;
		}while(count < 8);
		System.out.print("\n");
	}
}