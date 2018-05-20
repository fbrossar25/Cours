public class GoDate{
	static int signe(int n){
		if(n > 0) return 1;
		else if (n< 0) return -1;
		else return 0;
	}
	
	public static void main (String [] args){
		Date d1 = new Date();
		Date d2 = new Date(5,11);
		Date d3 = new Date(99,99);
		if(d1.equals(d3)) System.out.println("d1 et d3 égaux\n\n");
		if(d1.equals(d2))System.out.println("d1 et d2 équivalent\n\n");
		else System.out.println("d1 et d2 pas équivalent\n\n");
		switch(signe(d1.compareTo(d2))){
			case 1 : System.out.println("d1 ultérieur à d2\n\n");break;
			case -1 : System.out.println("d1 antérieur à d2\n\n");break;
			case 0: System.out.println("d1 = d2\n\n");break;
			default: System.out.println("Houston on a un problème\n\n");
		}
	}
}