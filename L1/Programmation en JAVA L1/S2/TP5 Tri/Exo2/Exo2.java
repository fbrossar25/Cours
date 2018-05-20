public class Exo2{
static final int N=10;

static int comparaisonChaine(String c1, String c2) { //-1 c1 > c2  0 c1=c2  1 c1 < c2
  int res=0,i=0;
  boolean run=true;
  if(c1.equals(c2)){
    run=false;
    res=0;
  }
  while((c1.length()==c2.length())&&(run==true)){
    if(c1.charAt(i)<c2.charAt(i)){
      run=false;
      res=1;
    }
    else if(c1.charAt(i)>c2.charAt(i)){
      run=false;
      res=-1;
    }
  }
  return res;
}

public static void main (String [] args){
  int ordre;
  String c1="",c2="";
  Ecran.afficherln("\nSVP, saisir une chaine de caractere c1 : ");
  c1=Clavier.saisirString();
  do{
  Ecran.afficherln("\nSVP, saisir une deuxième chaine de caractere c2 de la même longueur que c1 (",c1.length(),") : ");
  c2=Clavier.saisirString();
  }while(c2.length()!=c1.length());
  if(comparaisonChaine(c1,c2)==0)Ecran.afficherln("\nLes chaines sont identiques");
  else if(comparaisonChaine(c1,c2)==1)Ecran.afficherln("\nc1 passe avant c2 ");
  else Ecran.afficherln("\nc1 passe après c2 ");
}
}