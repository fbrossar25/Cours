public class Exo1c {

static int lectureEntierPositif(){
  int x;
  x=Clavier.saisirInt();
  while(x<0){ 
    Ecran.afficher("Resaisir : ");
    x=Clavier.saisirInt();
  }
  return x;
}

public static void main(String[]args){
  int n;
  Ecran.afficher("SVP saisir un entier positif n :");
  n=lectureEntierPositif();
  Ecran.afficher("vous avez saisi le nombre entier positif \n",n);
}
}