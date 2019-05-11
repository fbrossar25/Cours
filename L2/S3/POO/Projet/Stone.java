class Stone extends Cell{
	Position pos;

	Stone(){
		this(new Position());
	}

	Stone(int l,int c){
		this(new Position(l,c));
	}

	Stone(Position p){
		pos = p;
	}

	boolean isFree(){
		return false;
	}

	Direction redirect(Hunter p){
		return new Direction();
	}

	public String toString(){
		return "#";
	}
}