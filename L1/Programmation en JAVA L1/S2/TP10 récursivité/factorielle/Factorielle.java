public class Factorielle{
/**
*retourne la résultat de factorielle n (n!)
*@param int n 
*@return int res correspond à n!
**/
static long factorielle(long n){
  long res;
  if(n==0 || n==1){
    res=1;
  }
  else{
    res=n*(factorielle(n-1));
  }
  return res;
}

public static void main(String[]args){
  long n;
  Ecran.afficherln("\n n ?");
  n=Clavier.saisirLong();
  Ecran.afficherln("\n ",n,"! = ",factorielle(n));
}
}