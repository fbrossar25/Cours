abstract class Case{
	protected Position pos;
	
	Case(){
		this(new Position());
	}
	Case(Position pos){
		this.pos = new Position(pos);
	}
	Case(int nl, int nc){
		this(new Position(nc,nl));
	}
	
	Position getPosition(){
		return pos;
	}
	
	abstract boolean isFree();
	abstract boolean isMovableObject();
	abstract void move();
	abstract void setRandDirection();
	abstract void setDirection(Direction d);
	abstract Position getNextPosition();
	abstract String getDirectionString();
	abstract Direction getDirection();
	abstract int getType(); //-1 <=> objet immobile (Mur, Vide), 0 = Balle, 1= Faucheur, 2 = Ame, 3 = Resurrecteur
}