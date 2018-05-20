public class fusionTableau{ //fusion par ordre croissant de deus tableau d'entiers de tailles différentes dans un seul tableau de plus grande taille
static final int N = 10;
static final int M = 6;
static final int P = M+N;

static void affichageTableauInt(int [] t){ //affichage d'un tableau d'entier
  int i;
  Ecran.sautDeLigne();
  for(i=0;i<t.length;i++){
    if(i!=t.length-1) Ecran.afficher(t[i]," , ");
    else Ecran.afficher(t[i],"\n\n");
  }
}

static int[] triageTableauIntCroissant(int [] t){ //triage des valeurs d'une tableau d'entier par ordre croissant
  int i,j,save;
  for(i=0;i<t.length;i++){
    for(j=0;j<t.length;j++){
      if(t[i]<t[j]){
        save=t[j];
        t[j]=t[i];
        t[i]=save;
      }
    }
  }
  return t;
}

static int[] randTableau(int [] t){//remplissage aléatoire d'un tableau (valeures entre 0 et 50)
  int i;
  for(i=0;i<t.length;i++){
    t[i]=(int)(Math.random()*50);
  }
  return t;
}

static int[] fusionTableauIntCroissant(int [] t1, int [] t2){
  int [] t3 = new int [P];
  int i1=0,i2=0,i3;
  for(i3=0;i3<P;i3++){
    if(i1==N){
      t3[i3]=t2[i2];
      i2++;
    }
    else if(i2==M){
      t3[i3]=t1[i1];
      i1++;
    }
    else if(t1[i1]<=t2[i2]){
      t3[i3]=t1[i1];
      i1++;
    }
    else{
      t3[i3]=t2[i2];
      i2++;
    }
  }
  return t3;
}

public static void main(String[]args) {
  int [] t1 = new int [N]; 
  int [] t2 = new int [M];
  int [] t3 = new int [P];
  t1=randTableau(t1);
  t2=randTableau(t2);
  Ecran.afficher("\n t1 avant triage : ");
  affichageTableauInt(t1);
  Ecran.afficher("\n t2 avant triage : ");
  affichageTableauInt(t2);
  t1=triageTableauIntCroissant(t1);
  t2=triageTableauIntCroissant(t2);
  Ecran.afficher("\n t1 après triage : ");
  affichageTableauInt(t1);
  Ecran.afficher("\n t2 après triage : ");
  affichageTableauInt(t2);
  t3=fusionTableauIntCroissant(t1,t2);
  Ecran.afficher("\n fusion de t1 et de t2 : ");
  affichageTableauInt(t3);
}
}