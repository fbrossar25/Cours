class Arc{
	private Point a,b;

	Arc(){
		this(new Point(0,0),new Point(1,1));
	}

	Arc(Point p1, Point p2){
		if(!p1.equals(p2)){
			a = p1;
			b = p2;
		}
	}

	
}