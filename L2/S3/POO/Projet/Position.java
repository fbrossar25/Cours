class Position{
	private int l;
	private int c;
	
	Position(){
		this(0,0);
	}
	
	Position(int l, int c){
		this.l = l;
		this.c = c;
	}
	
	Position(Position p){
		l = p.l;
		c = p.c;
	}
	
	int getL(){
		return l;
	}
	
	int getC(){
		return c;
	}
	
	void setL(int l){
		set(l,this.c);
	}
	
	void setC(int c){
		set(this.l,c);
	}
	
	void set(Position p){
		set(p.l,p.c);
	}
	
	void set(int l, int c){
		this.l = l;
		this.c = c;
	}
	
	boolean equals(Position lui){
		return (this.l == lui.l) && (this.c == lui.c);
	}
/*
	boolean estAdjacent(Position lui){
		if(this.equals(lui)) return false; // on considère qu'une case n'est pas adjacente à elle même
		else{
			int n;
			for(int l=-1;l!=1;l++){
				for(int c=-1;c!=1;c++){
					if(!(c==0 && l==0)){
						if((lui.l == (this.l + l)) && (lui.c == this.c + c)) return true;
					}
				}
			}
		}
		return false;
	}
*/
	public String toString(){
		return "("+l+","+c+")";
	}
}