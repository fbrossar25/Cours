class Fibonacci{
	public static void main(String [] args){
		int n = 6;
		int mem1 = 0;
		int mem2 = 1;
		int res = 0;
		for(int i=0;i<=n-2;i++){
			res = mem1 + mem2;
			mem1 = mem2;
			mem2 = res;
		}
		System.out.println("Fib("+n+") = "+res);
	}
}