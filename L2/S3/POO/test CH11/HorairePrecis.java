public class HorairePrecis extends Horaire{
	private int ms;
	
	HorairePrecis(){
		this(0,0,0,0);
	}
	
	HorairePrecis(int h){
		this(h,0,0,0);
	}
	
	HorairePrecis(int h, int m){
		this(h,m,0,0);
	}
	
	HorairePrecis(int h, int m, int s){
		this(h,m,s,0);
	}
	
	HorairePrecis(int h, int m, int s, int ms){
		super(h,m,s);
		if(ms < 1000)this.ms = ms;
		else{
			this.ms = 0;
			System.out.println("Horaire saisie invalide. Initialisation avec (0,0,0,0)\n");
		}
	}
	
	int getMs(){
		return ms;
	}
	
	void setMs(int ms){
		this.ms = ms;
	}
	
	public String toString(){
		String s="";
		s += ((heure < 10) ? "0" : "") + heure + ":";
		s += ((minute < 10) ? "0" : "") + minute + ":";
		s += ((seconde < 10) ? "0" : "") + seconde + ", ";
		s += ms;
		return s;
	}
}