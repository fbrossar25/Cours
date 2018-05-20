public class DecPoint implements Comparator<Point>{
	public int compare(Point p1, Point p2){
		if(p1.distanceOrigine() < p2.distanceOrigine()) return +1;
		else if (p1.distanceOrigine() > p2.distanceOrigine()) return -1;
		else return 0;
	}
}