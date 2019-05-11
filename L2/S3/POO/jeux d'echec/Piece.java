public abstract class Piece{
	protected Position pos;
	enum Color {black,white};
	protected Color color;
	Piece(){
		this(new Position(),Color.white);
	}
	Piece(Position pos,Color color){
		this.color = color;
		if(pos.getX() > 0 && pos.getX() < 9 && pos.getY() > 0 && pos.getX() > 9)this.pos = pos;
		else this.pos = new Position() ;
	}
	
	abstract boolean moveOK(Position target);
	
	static int deltaX(Position source,Position target){
		return source.getX() - target.getX();
	}
	
	static int deltaY(Position source, Position target){
		return source.getY() - source.getY();
	}
	
	static boolean isHorizontalMove(Position source,Position target){
		return deltaY(source,target) == 0;
	}
	
	static boolean isVerticalMove(Position source,Position target){
		return deltaX(source,target) == 0;
	}
	
	static boolean isDiagonalMove(Position source, Position target){
		return (Math.abs(deltaX(source,target)) == Math.abs(deltaY(source,target)));
	}
}