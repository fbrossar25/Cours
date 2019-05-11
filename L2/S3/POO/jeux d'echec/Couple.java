public class Couple <T,E>{
	T e1;
	E e2;
	Couple(){
		this(null,null);
	}
	Couple(T x,E y){
		e1 = x;
		e2 = y;
	}
	T getFirst(){
		return e1;
	}
	E getLast(){
		return e2;
	}
	public String toString(){
		return "("+e1+","+e2+")";
	}
}