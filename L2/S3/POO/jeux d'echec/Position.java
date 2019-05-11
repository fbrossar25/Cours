class Position{
	private int x;
	private int y;
	Position(){
		this(1,1);
	}
	Position(int x, int y){
		if(x > 0 && x < 9 && y >0 && y <9){
			this.x = x;
			this.y = y;
		}
		else{
			this.x = 1;
			this.y = 1;
		}
	}
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
}