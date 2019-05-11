public class Exo1 {
	static final int NL=20;
	static final int NC=8;

	static class positionMatrice{
		int l=0;
		int c=0;
	}

	static int[][] matriceRandom(int [][] m){
		int l,c;
		for(l=0;l<m.length;l++){
			for(c=0;c<m[0].length;c++){
				m[l][c]=(int)(Math.random()*200)-100;
			}
		}
		return m;
	}

	static void affichageMatrice(int [][] m){
		int l,c;
		for(l=0;l<m.length;l++){
			for(c=0;c<m[0].length;c++){
				Ecran.afficher("  ",m[l][c],"  ");
			}
			Ecran.afficher("\n");
		}
	}

	static int valMinMatrice(int [][] m){
		int l,c;
		int res=m[0][0];
		for(l=0;l<m.length;l++){
			for(c=0;c<m[0].length;c++){
				if(res>m[l][c])res=m[l][c];
			}
		}
		return res;
	}

	static positionMatrice positionValMatrice(int [][] m , int val){ //retourne le dernière position ou la valeur val à été trouver dans la matrice
		positionMatrice pVal = new positionMatrice();
		int l,c,res=m[0][0];
		for(l=0;l<m.length;l++){
			for(c=0;c<m[0].length;c++){
				res=m[l][c];
				if(res==val){
					pVal.l=l;
					pVal.c=c;
				}
			}
		}
		return pVal;
	}

	static int ligneSommeMaxMatrice(int [][] m){
		int l;
		int res=0,somme;
		int sommeRes = sommeLigneMatrice(m,0);
		for(l=1;l<m.length;l++){
			somme=sommeLigneMatrice(m,l);
			if(sommeRes < somme ){
				sommeRes=somme;
				res=l;
			}
		}
		return res;
	}

	static int sommeLigneMatrice(int [][] m , int l){
		int somme=m[l][0],c;
		for(c=1;c<m[0].length;c++){
			somme+=m[l][c];
		}
		return somme;
	}

	static void affichageMatriceIntGraphique(int [][] m){
		int xFenetre=m[0].length*40;
		int yFenetre=m.length*40;
		int xCellule,yCellule;
		int l,c;
		String nombre;
		EcranGraphique.setClearColor(255,255,255);
		EcranGraphique.clear();
		EcranGraphique.init(50,50,xFenetre+40,yFenetre+40,xFenetre,yFenetre,"Matrice Entier");
		EcranGraphique.setColor(0,0,200);
		for(l=0;l<m.length;l++){
			yCellule=40+l*40;
			for(c=0;c<m[0].length;c++){
				nombre=Integer.toString(m[l][c]);
				xCellule=c*40;
				EcranGraphique.drawString(xCellule,yCellule,3,nombre);
			}
		}
		EcranGraphique.flush();
	}

	public static void main(String[]args){
		int [][] m = new int [NL][NC];
		int valMin,indiceSommeMax;
		positionMatrice posValMin = new positionMatrice(); 
		m=matriceRandom(m);
		affichageMatrice(m);
		valMin = valMinMatrice(m);
		Ecran.afficherln("\n\n Valeur minimale de la matrice : ",valMin);
		posValMin=positionValMatrice(m,valMin);
		Ecran.afficherln("\n\n position de la valeur minimale : l = ",posValMin.l,"  c = ",posValMin.c);
		indiceSommeMax=ligneSommeMaxMatrice(m);
		Ecran.afficherln("\n\n Ligne ayant la somme maximale : ",indiceSommeMax);
		affichageMatriceIntGraphique(m);
	}
}