class De{
	private final int NB_FACES;
	private int face;
	
	De(){
		this(6);
	}
	
	De(int n){
		NB_FACES = n;
	}
	
	int getFace(){
		return this.face;
	}
	
	void lancer(){
		this.face = Hasard.entier(NB_FACES)+1;
	}
	
	public String toString(){
		return "["+this.face+"]";
	}
}