public class Roi extends Piece{
	Roi(){
		super();
	}
	Roi(Position pos,Color color){
		super(pos,color);
	}
	boolean moveOK(Position target){
		return (Math.abs(deltaX(pos,target)) == 1) || (Math.abs(deltaY(pos,target)) == 1);
	}
	public String toString(){
		return "+";
	}
}