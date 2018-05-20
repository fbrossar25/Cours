public class Tour extends Piece{
	Tour(){
		super();
	}
	Tour(Position pos,Color color){
		super(pos,color);
	}
	boolean moveOK(Position target){
		return isHorizontalMove(pos,target) || isVerticalMove(pos,target);
	}
	public String toString(){
		return "T";
	}
}