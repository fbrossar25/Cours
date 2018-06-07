class Ame extends Case{
	private Direction dir;
	private boolean isAlive;
	
	Ame(){
		super();
		dir = new Direction();
		setRandDirection();
	}
	
	Ame(int nl, int nc){
		this(new Position(nc,nl));
	}
	
	Ame(Position pos){
		super(pos);
		dir = new Direction();
		setRandDirection();
	}
	
	Ame(Position pos,Direction d){
		super(pos);
		dir = new Direction(d);
	}
	
	Ame(Ame a){
		super(a.pos);
		dir = new Direction(a.dir);
		isAlive = a.isAlive;
	}
	
	Ame(int nl, int nc,Direction d){
		this(new Position(nc,nl),d);
	}
	
	void setDirection(int l, int c){
		dir.set(l,c);
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
	
	void setDirection(Direction d){
		dir.set(d);
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
	
	void kill(){
		isAlive = false;
	}
	
	void resurrect(){
		isAlive = true;
	}
	
	int getType(){
		return 2;
	}
	
	public String toString(){
		if (isAlive) return " A ";
		else return "X";
	}
}