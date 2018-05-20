class Vide extends Case{
	Vide(){
		super();
	}
	
	Vide(int nl, int nc){
		this(new Position(nc,nl));
	}
	
	Vide(Position pos){
		this.pos = new Position(pos);
	}
	
	boolean isFree(){
		return true;
	}
	
	boolean isMovableObject(){
		return false;
	}
	
	void move(){};
	
	void setRandDirection(){};
		
	void setDirection(Direction d){};
	
	Position getNextPosition(){
		return pos;
	}
	
	String getDirectionString(){
		return "";
	}
	
	Direction getDirection(){
		return new Direction(0,0);
	}
	
	int getType(){
		return -1;
	}
	
	public String toString(){
		return " . ";
	}
}