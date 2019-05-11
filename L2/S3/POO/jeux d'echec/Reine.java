public class Reine extends Piece{
	Reine(){
		super();
	}
	Reine(Position pos,Color color){
		super(pos,color);
	}
	boolean moveOK(Position target){
		return isDiagonalMove(pos,target) || isHorizontalMove(pos,target) ||isVerticalMove(pos,target);
	}
	public String toString(){
		return "*";
	}
}