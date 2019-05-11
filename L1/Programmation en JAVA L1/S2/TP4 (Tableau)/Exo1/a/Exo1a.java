public class Exo1a { //tire entre 1 et N nombres réels aléatoires et affiche combien appartiennent à un intervalle définit
  static final int N=20;

static class intervalle{
 double min=0.0;
 double max=0.0;
}

static double[] remplissageBorne(int n){
 double t [] = new double [n];
 int i;
 for(i=0;i<=n-1;i++){
  t[i]=Math.random()*20.0; //tirage aléatoire entre 0.0 et 20.0
  Ecran.afficher("\n valeur ",i+1," = ",t[i]);
 }
 Ecran.sautDeLigne();
 return t;
}

static int valeurBorne(int n, double [] t, intervalle inter){
 int i,nb=0; //nb de valeur dans l'intervalle
 Ecran.sautDeLigne();
 for(i=0;i<=n-1;i++){
  if((t[i]>=inter.min) && (t[i]<inter.max))nb++;
 }
 return nb;
}

static void classification(int n, double [] t){
  int classification[] = new int [20]; 
  int i,total=0;
  intervalle inter = new intervalle();
  for(i=0;i<=19;i++) classification[i]=0;
  for(i=0;i<=19;i++){ //intervalle [i;i+1[
      inter.min=i;
      inter.max=i+1;
      classification[i]+=valeurBorne(n,t,inter);
      Ecran.afficher("Valeurs comprisent dans l'intervalle [",inter.min,",",inter.max,"[ = ", classification[i],"\n");
  }
 for(i=0;i<=19;i++) total+=classification[i];
 Ecran.afficher("total = ",total,"\n");
  
}

static double calculAffichageMoyenne(int n, double [] t){
  double moyenne,somme=0.0;
  int i;
  for(i=0;i<=n-1;i++){
   somme=somme+t[i];
  }
 moyenne=somme/n;
 Ecran.afficher("\nMoyenne des valeurs du tableau = ",moyenne,"\n\n");
 return moyenne;
}

public static void main (String [] args) {
   double t[] = new double [N];
   intervalle inter = new intervalle();
   int n;
   do{
     Ecran.afficher("\n\nSVP nombre de valeurs (entier) à tirer au sort entre 1 et ",N, " ? ");
     n=Clavier.saisirInt();
   }while(n<1 || n>N);
   t=remplissageBorne(n);
   calculAffichageMoyenne(n,t);
   classification(n,t);
}
}