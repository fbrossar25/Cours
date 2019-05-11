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
	
	static int entierBornes(int min, int max){
		return (int)(Math.random()*(max + 1 - min) + min);
		// x vaut de min inclus à max+1 exclus (donc max inclus)
	}
}