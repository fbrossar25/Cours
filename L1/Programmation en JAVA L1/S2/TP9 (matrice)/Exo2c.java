public class Exo2c {
static final int N=10;

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
      Ecran.afficher(String.format("   %.3f   ",m[l][c])); //affichage à 3 chiffres après la virgule
    }
    Ecran.afficher("\n");
  }
}

static void transpositionMatriceCarreFloat(float [][] m){
  int l,c;
  float aux;
	if(m.length==m[0].length){
		for(l=0;l<m.length-2;l++){
			for(c=l+1;c<m.length-1;c++){
				aux=m[l][c];
				m[l][c]=m[c][l];
				m[c][l]=aux;
			}
		}
	}
	else Ecran.afficher("\nLa matrice m doit être carrée.\n");
}

public static void main(String[]args){
  float [][] m = new float [N][N];
  m=matriceRandomFloat(m);
  Ecran.afficherln("\nMatrice source : \n");
  affichageMatrice(m);
  transpositionMatriceCarreFloat(m);
  Ecran.afficherln("\nMatrice transposée : \n");
  affichageMatrice(m);
}
}