public class point{
	double x = 0;
	double y = 0;
	double distanceOrigine(){
		return Math.sqrt(x*x+y*y);
	}
	double distPointPoint(point p){
		return Math.sqrt((p.x-x)+(p.y-y));
	}
}