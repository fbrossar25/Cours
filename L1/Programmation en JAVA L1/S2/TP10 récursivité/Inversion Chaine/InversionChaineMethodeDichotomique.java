public class InversionChaineMethodeDichotomique{
/**
*retourne la chaine st invers�e (abcd devient dcba) par m�thode dichotomique
*@param String st 
*@return String si la chaine invers�e
*/
static String inversionChaine(String st){
	String si="",s1,s2;
	int l1,lst;
	lst=st.length();
	if(lst==0 || lst==1) si=st;
	else{
		l1=lst/2;
		s1=inversionChaine(sousChaine(st,0,l1));
		s2=inversionChaine(sousChaine(st,l1,lst));
		si=concatener(s2,s1);
	}
	return si;
}

/**
*concat�ne s1 et s2
*@param String s1
*@param String s2
*@return String res la chaine concatenant s1 et s2
*/
static String concatener(String s1, String s2){
	return s1+s2;
}

/**
*extrait une la chaine de caract�re allant de l'indice iInitial a l'indice iFinal � l'int�rieur de la chaine s
*@param String s
*@param int iInitial
*@param int iFinal
*@return String res la chaine extraite de s
*/
static String sousChaine(String s, int iInitial, int iFinal){
	String res="";
	int i;
	if(iInitial <= iFinal){
		for(i=iInitial;i<iFinal;i++){
			res+=s.charAt(i);
		}
	}
	return res;
}

/**
*Demande � l'utilisateur la chaine s devant �tre invers�e
*@author BROSSARD Florian
*/
public static void main(String[]args){
	String s="";
	Ecran.afficher("\n Chaine � inverser : ");
	s=Clavier.saisirString();
	Ecran.afficherln("\n Chaine invers�e : ",inversionChaine(s));
}
}