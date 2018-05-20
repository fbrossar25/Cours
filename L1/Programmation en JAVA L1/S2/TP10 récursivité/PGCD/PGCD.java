public class PGCD{
/**
*retourne le PGCD de a et b
*@param int n 
*@return int res correspond à n!
**/
static int PGCD(int a , int b){
  int res;
  if(a < b){
    res=PGCD(b,a);
  }
  else if (b==0){
    res=a;
  }
  else{
    res=PGCD(b,a%b);
  }
  return res;
}

public static void main(String[]args){
  int a,b;
  Ecran.afficherln("\n a ?");
  a=Clavier.saisirInt();
  Ecran.afficherln("\n b ?");
  b=Clavier.saisirInt();
  Ecran.afficherln("\n PGCD(",a,",",b,") = ",PGCD(a,b));
}
}