public class goComplexe{
	static NombreComplexe sommeTabComplexe(NombreComplexe [] t){
		NombreComplexe res = new NombreComplexe(0,0);
		for(int i = 0; i<t.length ; i++){
			res.addThisComplexe(t[i]);
		}
		return res;
	}
	
	static NombreComplexe produitTabComplexe(NombreComplexe [] t){
		NombreComplexe res = new NombreComplexe(1,1);
		for(int i = 0; i<t.length ; i++){
			res.mulThisComplexe(t[i]);
		}
		return res;
	}
	
	static void affichageTabComplexe(NombreComplexe [] t){
		for(int i = 0; i < t.length; i++){
			System.out.println("complexe "+i+" : "+t[i]);
		}
		System.out.print("\n\n");
	}
	
	static boolean testIdentiqueTabComplexe(NombreComplexe [] t){
		int i=0, j=0;
		boolean run = true;
		do{
			do{
				if( (j != i) && (t[i].identique(t[j])) ) run = false;
				//if (!run) System.out.println("Complexe "+i+" et "+j+" identiques");
				//else if(j != i) System.out.println("Complexe "+i+" : "+t[i]+" et "+j+": "+t[j]+" différents");
				j++;
			}while(run && j < t.length);
			i++;
			j=0;
		}while(run && i < t.length);
		return !run;
	}
	
	public static void main(String[] args){
		NombreComplexe somme = new NombreComplexe(0,0);
		NombreComplexe produit = new NombreComplexe(0,0);
		NombreComplexe t[] = new NombreComplexe [20];
		for(int i =0;i<t.length;i++){
			t[i] = new NombreComplexe((int)((Math.random()*20)-10),((int)(Math.random()*20)-10));
		}
		affichageTabComplexe(t);
		somme = sommeTabComplexe(t);
		produit = produitTabComplexe(t);
		System.out.println("La somme des complexes du tableau vaut : "+somme);
		System.out.println("Le produit des complexes du tableau vaut : "+produit);
		if(testIdentiqueTabComplexe(t)) System.out.println("Au moins deux nombres complexe dans le tableau t sont identiques");
		else System.out.println("Aucun doublons n'est présent dans le tableau");
	}
}