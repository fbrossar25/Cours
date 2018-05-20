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
	
	public String toString(){
		return "("+l+","+c+")";
	}
}