public class ExobTD{

static void affichageTableauChaine(String [] t){
  int i;
  Ecran.sautDeLigne();
  for(i=0;i<t.length;i++){
    if(i!=t.length-1) Ecran.afficher(t[i]," , ");
    else Ecran.afficher(t[i],"\n\n");
  }
}

static String[] decalageCycliqueVersDebut(String [] t){
  int i;
  String chaineSave=t[0];
  for(i=1;i<t.length;i++){
    t[i-1]=t[i];
  }
  t[t.length-1]=chaineSave;
  return t;
}

static String[] decalageCycliqueVersFin(String [] t){
  int i;
  String chaineSave=t[9];
  for(i=t.length-1;i>0;i--){
    t[i]=t[i-1];
  }
  t[0]=chaineSave;
  return t;
}

static String[] saisieChaineTableau(){
  int i;
  String [] t = new String [10];
  for(i=0;i<t.length;i++){
    t[i]="";
    t[i]+=(char)(65+i);
  }
  return t;
}

public static void main(String[]args) {
  String [] t = new String [10];
  t=saisieChaineTableau();
  affichageTableauChaine(t);
  t=decalageCycliqueVersDebut(t);
  affichageTableauChaine(t);
  t=decalageCycliqueVersFin(t);
  affichageTableauChaine(t); 
}
}