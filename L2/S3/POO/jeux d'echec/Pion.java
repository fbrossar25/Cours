public class Pion extends Piece{
	Pion(){
		super();
	}
	Pion(Position pos,Color color){
		super(pos,color);
	}
	boolean moveOK(Position target){
		//on suppose que les blanc sont en bas
		if(color == Color.white){
			if(pos.getY() == 2)return deltaY(pos,target) == 2 || deltaY(pos,target) == 1;
			else return deltaY(pos,target) == 1;
		}
		else{
			if(pos.getY() == 7)return deltaY(pos,target) == -2 || deltaY(pos,target) == -1;
			else return deltaY(pos,target) == -1;
		}
	}
	public String toString(){
		return "p";
	}
}