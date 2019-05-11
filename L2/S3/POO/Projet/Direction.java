class Direction{
	private int l;
	private int c;
	
	Direction(){
		this(0,0);
	}
	
	Direction(int l, int c){
		if(l > -2 && l < 2)this.l = l;
		else this.l = 0;
		if(c > -2 && c < 2)this.c = c;
		else this.c = 0;
	}
	
	Direction (Direction d){
		this(d.l,d.c);
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
	
	void set(Direction d){
		set(d.l,d.c);
	}
	
	void set(int l, int c){
		if(l>-2 && l<2 && c>-2 && c<2){
			this.l = l;
			this.c = c;
		}
	}
	
	public String toString(){
		String s = "";
		if(l == -1){
			if(c == -1) s+= "SO";
			else if(c == 0) s+= "S";
			else if(c == 1) s+= "SE";
		}
		else if(l == 0){
			if(c == -1) s+= "O";
			else if(c == 0) s+= "X";
			else if(c == 1) s+= "E";
		}
		else{
			if(c == -1) s+= "NO";
			else if(c == 0) s+= "N";
			else if(c == 1) s+= "NE";
		}
		return s + " : ("+l+","+c+")";
	}
}