class Balle extends Case{
	private Direction dir;
	
	Balle(){
		super();
		dir = new Direction();
		setRandDirection();
	}
	
	Balle(int nl, int nc){
		this(new Position(nc,nl));
	}
	
	Balle(Position pos){
		super(pos);
		dir = new Direction();
		setRandDirection();
	}
	
	Balle(Balle b){
		super(b.pos);
		dir = new Direction(b.dir);
	}
	
	Balle(Position pos,Direction d){
		super(pos);
		dir = new Direction(d);
	}
	
	Balle(int nl, int nc,Direction d){
		this(new Position(nc,nl),d);
	}
	
	void setDirection(Direction d){
		dir.set(d);
	}
	
	void move(){
		Ecran.afficherln("Position avant changement : ",pos);
		pos.setL(pos.getL()+dir.getL());
		pos.setC(pos.getC()+dir.getC());
		Ecran.afficherln("Position après changement : ",pos,"\n\n");
	}
	
	Position getNextPosition(){
		return new Position((pos.getL()+dir.getL()),(pos.getC()+dir.getC()));
	}
	
	void setDirection(int l, int c){
		dir.set(l,c);
	}
	
	String getDirectionString(){
		return dir.toString();
	}
	
	void setRandDirection(){
		int a,b;
		do{
			a = Hasard.entierBornesMoins1Et1();
			b = Hasard.entierBornesMoins1Et1();
		}while(a==0 && b==0);
		dir.set(a,b);
	}
	
	boolean isFree(){
		return false;
	}
	
	boolean isMovableObject(){
		return true;
	}
	
	Direction getDirection(){
		return dir;
	}
	
	public String toString(){
		return " o ";
	}
}