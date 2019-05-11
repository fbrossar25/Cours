public class NombreComplexe{
	private int r,i;
	int getR(){
		return r;
	}
	int getI(){
		return i;
	}
	NombreComplexe(int r, int i){
		this.r = r;
		this.i = i;
	}
	NombreComplexe(){
		this(0,0);
	}
	static NombreComplexe getConjugue(NombreComplexe that){
		NombreComplexe conjugue = new NombreComplexe(that.r, -that.i);
		return  conjugue;
	}
	NombreComplexe getConjugue(){
		return getConjugue(this);
	}
	//la m�thode getConjugue() n'est pas statique car on doit instancier l'objet pour utilis� la m"thode � l'inverse de la m�thode getConjugue(that)
	double module(){
		return Math.sqrt(r*r + i*i);
	}
	void mulThisComplexe(NombreComplexe that){
		r = (r*that.r) - (i*that.i);
		i = (r*that.i) - (i*that.r);
	}
	void addThisComplexe(NombreComplexe that){
		this.r+=that.r;
		this.i+=that.i;
	}
	static NombreComplexe addComplexe(NombreComplexe c1, NombreComplexe c2){
		NombreComplexe res = new NombreComplexe();
		res.r = c1.r + c2 .r;
		res.i = c1.i + c2.i;
		return res;
	}
	static NombreComplexe mulComplexe(NombreComplexe c1, NombreComplexe c2){
		NombreComplexe res = new NombreComplexe();
		res.r = (c1.r * c2.r) - (c1.i * c2.i);
		res.i = (c1.r * c1.i) - (c1.i * c2.r);
		return res;
	}
	//ces 2 m�thodes sont statiques car elles doivent pouvoir �tres appel�es sans instancier la classe
	public String toString(){
		String s="";
		if(i == 0) s+=r;
		else if (i == 1 && r == 0) s = "i";
		else if (i == 1 && r != 0) s = r+" + "+"i";	
		else if (i != 1 && r == 0) s = i+"i";
		else if(i == 0 && r == 0) s = "0";
		else if(i < 0 && r != 0) s = r+" "+i+"i";
		else s = r+" + "+i+"i";
		return s;
	}
	boolean identique(NombreComplexe that){
		return ((this.r == that.r) && (this.i == that.i));
	}
}
