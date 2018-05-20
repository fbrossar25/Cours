public class Exo1f {
static final int N=10;

static double calculSinusDVL(double a){
  double sinus=0.0;
  int b=6,i,k=2; //i ordre, k signe, b factorielle
  sinus=a-(Math.pow(a,3)/b); //ordre 3
  //calcul du sin � un ordre i jusqu'a N
  for(i=5;i<=N;i+=2){ //d�but de la boucle � l'ordre 5
    b=b*(i-1)*i; //calcul de factorielle
    sinus+= ((Math.pow(-1,k))*(Math.pow(a,i)/(b)));
    k++; //changement du signe
  }
  return sinus;
}

public static void main(String[]args){
  double sinus=0.0,a=0.0;
  Ecran.afficher("SVP saisir un angle en degr� : ");
  a=Clavier.saisirDouble();
  a=(a*Math.PI)/180.0; //conversion en radians
  sinus=calculSinusDVL(a);
  Ecran.afficher("Le sinus de ",a,"� vaut ",sinus," avec le d�veloppement limit� de sinus � l'ordre ",N,".\n");
}
}