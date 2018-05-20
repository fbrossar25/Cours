class Point implements Comparable<Point>{
	private double x,y;

	Point(){
		this(0.0,0.0);
	}

	Point(double x,double y){
		this.x = x;
		this.y = y;
	}

	double distanceOrigine(){
		return Math.sqrt(x*x + y*y);
	}

	public int compareTo(Point that){
		double diff = distanceOrigine() - that.distanceOrigine();
		if(diff > 0) return +1;
		else if (diff < 0) return -1;
		else return 0;
	}
}
