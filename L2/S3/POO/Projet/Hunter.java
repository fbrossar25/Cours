class Hunter{
	private Position pos;
	private Direction dir;
	//private static int nbInstances=0;

	Hunter(){
		this(0,0);
	}

	Hunter(Position p){
		pos = p;
		dir = new Direction();
		//nbInstances++;
	}
	
	Hunter(int px,int py){
		pos = new Position(px,py);
		dir = new Direction();
		//nbInstances++;
	}
	
	void move(){
		pos.setL(pos.getL()+dir.getL());
		pos.setC(pos.getC()+dir.getC());
	}
	
	Position getPosition(){
		return pos;
	}

	Position getNextPosition(){
		return new Position((pos.getL()+dir.getL()),(pos.getC()+dir.getC()));
	}
	
	void setDirection(Direction d){
		dir.set(d);
	}

	void setDirection(int l, int c){
		dir.set(l,c);
	}

	void setRandDirection(){
		int a,b;
		do{
			a = Hasard.entierBornesMoins1Et1();
			b = Hasard.entierBornesMoins1Et1();
		}while(a==0 && b==0);
		dir.set(a,b);
	}

	Direction getDirection(){
		return dir;
	}

	public String toString(){
		return "O";
		//return ""+nbInstances;
	}
}