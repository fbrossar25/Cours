public class Horaire{
	protected int heure;
	protected int minute;
	protected int seconde;
	Horaire(){
		this(0,0,0);
	}
	Horaire(int h){
		this(h,0,0);
	}
	Horaire(int h, int m){
		this(h,m,0);
	}
	Horaire(int h, int m, int s){
		if(h >=0 && h<24 && m>=0 && m<60 && s>=0 && s <60){
			heure = h;
			minute = m;
			seconde = s;
		}
		else{
			heure = 0;
			minute = 0;
			seconde = 0;
			System.out.println("Horaire saisie invalide. Initialisation avec (0,0,0)\n");
		}
	}
	
	void setHoraire(int h, int m, int s){
		heure = h;
		minute = m;
		seconde = s;
	}
	
	void setHoraire(int h){
		setHoraire(h,0,0);
	}
	
	void setHoraire(int h, int m){
		setHoraire(h,m,0);
	}
	
	int getHeure(){
		return heure;
	}
	
	int getMinute(){
		return minute;
	}
	
	int getSeconde(){
		return seconde;
	}
	
	public String toString(){
		String s="";
		s += ((heure < 10) ? "0" : "") + heure + ":";
		s += ((minute < 10) ? "0" : "") + minute + ":";
		s += ((seconde < 10) ? "0" : "") + seconde;
		return s;
	}
}