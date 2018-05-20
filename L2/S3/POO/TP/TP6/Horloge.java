import java.util.*;
class Horloge{
	private int h;
	private int m;
	private int s;
	Horloge(){
		this.h = GregorianCalendar.getInstance().get(GregorianCalendar.HOUR_OF_DAY);
		this.m = GregorianCalendar.getInstance().get(GregorianCalendar.MINUTE);
		this.s = GregorianCalendar.getInstance().get(GregorianCalendar.SECOND);
	}
	void update(){
		this.h = GregorianCalendar.getInstance().get(GregorianCalendar.HOUR_OF_DAY);
		this.m = GregorianCalendar.getInstance().get(GregorianCalendar.MINUTE);
		this.s = GregorianCalendar.getInstance().get(GregorianCalendar.SECOND);
	}
	public String toString(){
		String chaine="";
		if (h < 10) chaine += "0"+h;
		else chaine += h;
		chaine += ":";
		if (m < 10) chaine += "0"+m;
		else chaine += m;
		chaine += ":";
		if (s < 10) chaine += "0"+s;
		else chaine += s;
		return chaine;
	}
	public static void pause(int nbMillisecondes){
		try {
			Thread.sleep(nbMillisecondes);
		}
		catch (Exception e){}
	}
}