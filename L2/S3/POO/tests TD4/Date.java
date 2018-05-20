public class Date implements Comparable{
	private int j;
	private int m;
	Date(int j,int m){
		if((j>0 && j<32) && (m > 0 && m<13)){
			this.j = j;
			this.m = m;
		}
		else{
			this.j=1;
			this.m=1;
		}
	}
	Date(){
		this(1,1);
	}
	public boolean equals(Date lui){
		return (this.j == lui.j && this.m == lui.m);
	}
	
	public int compareTo(Object o){
		return ((this.j + 31*this.m) - (((Date) o).j + 31*((Date)o).m));
	}
}