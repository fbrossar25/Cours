public class Fou extends Piece{
	Fou(){
		super();
	}
	Fou(Position pos,Color color){
		super(pos,color);
	}
	boolean moveOK(Position target){
		return isDiagonalMove(pos,target);
	}
	public String toString(){
		return "i";
	}
}