public class Insertion{
static final int N=10;

static int indiceInsertion(int [] t, int n){ //donne le premier indice pour lequel il faudrait insérer la valeur n
  int res=0;
  while((n>t[res]) && (res<N-1)){
    res++;
  }
  return res;
}

static int[] triageCroissant(int [] t){ //tri un tableau d'entier dans l'ordre croissant
  int i,j,save;
  for(i=0;i<t.length-1;i++){
    for(j=0;j<t.length-1;j++){
      if(t[j]>t[j+1]){
        save=t[j+1];
        t[j+1]=t[j];
        t[j]=save;
        }
    }
  }
  return t;
}

static void affichageTableauInt(int [] t){ //affiche un taleau d'entier en une ligne
  int i;
  Ecran.sautDeLigne();
  for(i=0;i<t.length;i++){
    if(i==t.length-1) Ecran.afficher(t[i]);
    else Ecran.afficher(t[i]," , ");
  }
  Ecran.sautDeLigne();
}

static int [] tableauIntRandom(int n){ //génere un tableau d'entier aléatoire entre 0 et 100 trié par ordre croissant
  int [] t=new int [n];
  int i;
  for(i=0;i<n;i++){
    t[i]=(int)(Math.random()*100);
  }
  triageCroissant(t);
  return t;
}

public static void main (String [] args){
  int [] t=new int [N];
  int indiceIns,n;
  t=tableauIntRandom(N);
  affichageTableauInt(t);
  Ecran.afficherln("\nSasir la valeur à insérer n : ");
  n=Clavier.saisirInt();
  indiceIns=indiceInsertion(t,n);
  Ecran.afficherln("\nIndice d'insertion de la valeur = ",indiceIns);
}
}