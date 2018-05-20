public class nombreMots{
	
static char[] toCharArray(String s){
	int i;
	char [] t=new char [s.length()];
	for(i=0;i<t.length;i++){
		t[i] = s.charAt(i);
	}
	return t;
}
	
static int nombreDeMots(String s){
	int i,res=0;
	char [] t = new char [s.length()];
	t=toCharArray(s);
	for(i=0;i<t.length;i++){
		if(i==0){
			if(t[i]!=' ') res++;
		}
		else if(t[i-1]==' ' && t[i] !=' ') res++;
	}
	return res;
}

public static void main(String[]args) {
	String s="";
	Ecran.afficherln("\n SVP saisir une chaîne de caractère :");
	s=Clavier.saisirString();
	Ecran.afficherln("\nIl y a ",nombreDeMots(s)," mot(s) dans cette chaîne de caractère.");
}
}