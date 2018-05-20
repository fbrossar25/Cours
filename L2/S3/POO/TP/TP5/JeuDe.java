class JeuDe{
	private final int NB_DES;
	private final int NB_FACES;
	private De [] jet;
	private boolean [] remiseEnJeu;
	
	JeuDe(int nbDes, int nbFaces){
		this.NB_DES = nbDes;
		this.NB_FACES = nbFaces;
		if(NB_DES > 0 && NB_FACES > 0){
			this.jet = new De [NB_DES];
			this.remiseEnJeu = new boolean[NB_DES];
			for(int i=0; i<NB_DES; i++){
				jet[i] = new De(NB_FACES);
				remiseEnJeu[i] = true;
			}
		}
		else {
			Ecran.afficherln("Vous devez indiquez des valeures entières > 0");
			System.exit(1);
		}
	}
	
	JeuDe(){
		this(3,6);
	}
	
	void lancerDeN(int n){
		if(n>=0 && n<NB_DES)this.jet[n].lancer();
	}
	
	void lancer(){
		for(int i=0; i<NB_DES; i++){
			if(this.remiseEnJeu[i]) this.jet[i].lancer();
		}
	}
	
	void lancerTout(){
		for(int i=0; i<NB_DES; i++){
			this.jet[i].lancer();
		}
	}
	
	void bloquerDe(int n){
		this.remiseEnJeu[n] = false;
	}
	
	void unblockAll(){
		for(int i=0; i<NB_DES; i++){
			this.remiseEnJeu[i] = true;
		}
	}
	
	void blockAll(){
		for(int i=0; i<NB_DES; i++){
			this.remiseEnJeu[i] = false;
		}
	}
	
	void conserverDes(int [] t){
		this.unblockAll();
		for(int i=0; i<t.length; i++){
			this.remiseEnJeu[t[i]] = false;
		}
		this.afficheBloquage();
	}
	
	void afficheBloquage(){
		for (int i=0; i<NB_DES; i++){
			if(this.remiseEnJeu[i])Ecran.afficherln("Dé ",i," débloqué");
			else Ecran.afficherln("Dé ",i," bloqué");
		}
		Ecran.sautDeLigne();
	}
	
	private void triEntierCroissant(int [] t){
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
	}
	
	boolean equals(JeuDe j){
		if(j.NB_DES == this.NB_DES){
			int i;
			int [] t1 = new int [this.NB_DES];
			for(i=0; i<this.NB_DES; i++){
				t1[i] = this.jet[i].getFace();
			}
			int [] t2 = new int [j.NB_DES];
			for(i=0; i<j.NB_DES; i++){
				t2[i] = j.jet[i].getFace();
			}
			boolean res = true;
			triEntierCroissant(t1);
			triEntierCroissant(t2);
			i=0;
			do{
				if(t1[i] != t2[i]) res = false;
				else i++;
			}while(res == true && i<this.NB_DES);
			return res;
		}
		else return false;
	}
	
	boolean equals(int [] t){
		if(t.length == this.NB_DES){
			int i;
			int [] t1 = new int [this.NB_DES];
			for(i=0; i<this.NB_DES; i++){
				t1[i] = this.jet[i].getFace();
			}
			boolean res = true;
			triEntierCroissant(t1);
			triEntierCroissant(t);
			i=0;
			do{
				if(t1[i] != t[i]) res = false;
				else i++;
			}while(res == true && i<this.NB_DES);
			return res;
		}
		else return false;
	}
	
	int getNbDes(){
		return this.NB_DES;
	}
	
	public String toString(){
		String s="";
		for(int i=0; i<this.NB_DES; i++){
			if(i!=0 && (((i+1)%3) == 0)) s+= "\n";
			s += (this.remiseEnJeu[i] ? " ":"*" )+(i+1)+": "+this.jet[i].toString()+(this.remiseEnJeu[i] ? "       ":"*      " );
		}
		return s;
	}
}