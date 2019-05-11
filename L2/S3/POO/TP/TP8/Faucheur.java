class Faucheur extends Case{
	private Direction dir;
	private boolean isAlive;
	
	Faucheur(){
		super();
		dir = new Direction();
		setRandDirection();
	}
	
	Faucheur(int nl, int nc){
		this(new Position(nc,nl));
	}
	
	Faucheur(Position pos){
		super(pos);
		dir = new Direction();
		setRandDirection();
	}
	
	Faucheur(Position pos,Direction d){
		super(pos);
		dir = new Direction(d);
	}
	
	Faucheur(int nl, int nc,Direction d){
		this(new Position(nc,nl),d);
	}
	
	void setDirection(int l, int c){
		dir.set(l,c);
	}
	
	void setDirection(Direction d){
		dir.set(d);
	}
	
	void move(){
		pos.setL(pos.getL()+dir.getL());
		pos.setC(pos.getC()+dir.getC());
	}
	
	boolean isDead(){
		return !isAlive;
	}
	
	boolean isAlive(){
		return isAlive;
	}
	
	boolean isFree(){
		return false;
	}
	
	boolean isMovableObject(){
		return true;
	}
	
	void setRandDirection(){
		int a,b;
		do{
			a = Hasard.entierBornesMoins1Et1();
			b = Hasard.entierBornesMoins1Et1();
		}while(a==0 && b==0);
		dir.set(a,b);
	}
	
	Position getNextPosition(){
		return new Position((pos.getL()+dir.getL()),(pos.getC()+dir.getC()));
	}
	
	String getDirectionString(){
		return dir.toString();
	}
	
	Direction getDirection(){
		return dir;
	}
	
	public String toString(){
		return " F ";
	}
}