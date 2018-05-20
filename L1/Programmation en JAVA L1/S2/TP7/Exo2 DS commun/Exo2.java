public class Exo2{

static int[] initTableau(int [] t){
  int i;
  for(i=0;i<t.length;i++){
    t[i]=0;
  }
  return t;
}

static void affichageTableau(int [] t){
  int i,res=0;
  Ecran.sautDeLigne();
  for(i=0;i<t.length;i++){
	if(i<20){
	    Ecran.afficher(" ",t[i]," ,");
	    res+=t[i];
	}
	else{
		Ecran.afficher(" ",t[i]);
		res+=t[i];
	}
  }
  Ecran.sautDeLigne();
  Ecran.afficherln("\n somme = ",res);
}

static boolean[] tirageSerieBool(double p){
  boolean [] serie = new boolean [20];
  int i;
  for(i=0;i<serie.length;i++){
    if(Math.random()<=p) serie[i]=true;
    else serie[i]=false;
  }
  return serie;
}

static int nombreDeVrai(boolean [] t){
  int res=0,i;
  for(i=0;i<t.length;i++){
    if(t[i]) res++;
  }
  return res;
}

public static void main(String[]args) {
  int [] tnbv=new int [21];
  int i,n;
  double p;
  do{
    Ecran.afficherln("\nSaisir p (réel entre 0.0 et 1.0)");
    p=Clavier.saisirDouble();
  }while(p<0.0 && p>1.0);
  initTableau(tnbv);
  for(i=0;i<1000000;i++){
    n=nombreDeVrai(tirageSerieBool(p));
    tnbv[n]++;
  }
  affichageTableau(tnbv);
}
}