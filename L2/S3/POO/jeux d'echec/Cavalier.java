public class Cavalier extends Piece{
	Cavalier(){
		super();
	}
	Cavalier(Position pos,Color color){
		super(pos,color);
	}
	boolean moveOK(Position target){
		return (((Math.abs(deltaY(pos,target))==2) && (Math.abs(deltaX(pos,target))) == 1) || ((Math.abs(deltaY(pos,target))==1) && ((Math.abs(deltaX(pos,target))) == 2)));
	}
	public String toString(){
		return "C";
	}
}