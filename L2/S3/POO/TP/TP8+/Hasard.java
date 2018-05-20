class Hasard{
	static int entierRel(int n){
		return (int)(Math.random()*2*n-n);
	}
	
	static int entierRel(){
		return entierRel(100);
	}
	
	static int entier(int n){
		return (int)(Math.random()*n);
	}
	
	static int entier(){
		return entier(100);
	}
	
	static int entierBornes(int a, int b){
		int min,max;
		if(a>b){
			min = b;
			max = a;
		}
		else{
			min = a;
			max = b;
		}
		return (int)(Math.random()*(max + 1 - min) + min);
		// x vaut de min inclus a max+1 exclus (donc max inclus)
	}
	
	static int entierBornesMoins1Et1(){
		return (int)(Math.random()*(2 + 1 - 0) + 0)-1;
	}

	static boolean bool(){
		return (Math.random()<0.5);
	}
}