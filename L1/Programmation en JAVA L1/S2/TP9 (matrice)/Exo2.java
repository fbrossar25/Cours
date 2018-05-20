public class Exo2 {
static final int NL=20;
static final int NC=8;

static class positionMatrice{
  int l=0;
  int c=0;
}

static float[][] matriceRandomFloat(float [][] m){
  int l,c;
  for(l=0;l<m.length;l++){
    for(c=0;c<m[0].length;c++){
      m[l][c]=(float)((Math.random()*100.0)-50.0);
    }
  }
  return m;
}

static void affichageMatrice(float [][] m){
  int l,c;
  for(l=0;l<m.length;l++){
    for(c=0;c<m[0].length;c++){
      Ecran.afficher("  ",m[l][c],"  ");
    }
    Ecran.afficher("\n");
  }
}

static float[][] copieMatriceFloat(float [][] src){
  int l,c;
  float [][] dst = new float [src.length][src[0].length];
  for(l=0;l<src.length;l++){
    for(c=0;c<src[0].length;c++){
      dst[l][c]=src[l][c];
    }
  }
  return dst;
}

static float[][] transpositionMatriceFloat(float [][] src , float [][] dst){
  int l,c;
  for(l=0;l<src.length;l++){
    for(c=0;c<src[0].length;c++){
      dst[c][l]=src[l][c];
    }
  }
  return dst;
}

public static void main(String[]args){
  float [][] m1 = new float [NL][NC];
  float [][] m2 = new float [NL][NC];
  float [][] m3 = new float [NC][NL];
  m1=matriceRandomFloat(m1);
  m2=copieMatriceFloat(m1);
  m3=transpositionMatriceFloat(m2,m3);
  Ecran.afficherln("\nMatrice source : \n");
  affichageMatrice(m1);
  Ecran.afficherln("\nMatrice copie : \n");
  affichageMatrice(m2);
  Ecran.afficherln("\nMatrice transposée : \n");
  affichageMatrice(m3);
}
}