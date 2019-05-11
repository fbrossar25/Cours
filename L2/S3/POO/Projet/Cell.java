abstract class Cell implements Askable{
	protected Position pos;

	Cell(){
		this(new Position());
	}

	Cell(int px,int py){
		pos = new Position(px,py);
	}

	Cell(Position p){
		pos = p;
	}

	Position getPos(){
		return pos;
	}

	int getL(){
		return pos.getL();
	}

	int getC(){
		return pos.getC();
	}

	int distanceFromTreasure(Treasure t){
		int dl = Math.abs(t.getPos().getL() - pos.getL());
		int dc = Math.abs(t.getPos().getC() - pos.getC());
		if (dl > dc)return dl;
		else return dc;
	}

	abstract boolean isFree();
	abstract Direction redirect();
}