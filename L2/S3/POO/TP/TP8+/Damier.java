class Damier{
	Case [][] grille;
	boolean [][] scanned;
	Damier(){
		this(8,8);
	}
	
	Damier(int l, int c){
		grille = new Case [l][c];
		scanned = new boolean [l][c];
		//initialisationde chaque case
		for(int i=0;i<grille.length;i++){//lignes
			for(int j=0;j<grille[0].length;j++){//colonnes
				if(i==0 || j==0 || i==(grille.length - 1) || j==(grille[0].length - 1))grille[i][j] = new Mur(i,j);
				else grille[i][j] = new Vide(i,j);
				scanned[i][j] = false;
			}
		}
	}
	
	boolean existFreePositon(){
		for(int i=1;i<grille.length -1;i++){//lignes sauf la premiere et la derniere car mur oblatoirement
			for(int j=1;j<grille[0].length-1;j++){//colonnes sauf la premiere et la derniere car mur oblatoirement
				if(grille[i][j].isFree()) return true;
			}
		}
		return false;
	}
	
	Position getRandomFreePosition(){
		Position res = new Position();
			do{
				res.set((int)(Math.random()*grille.length-1),(int)(Math.random()*grille[0].length-1));
			}while(!(grille[res.getL()][res.getC()].isFree()));
		return res;
	}
	
	void setRandMur(){
		setRandMur(1);
	}
	
	void setRandMur(int n){
		Position pRand;
		if(existFreePositon()){
			for(int i=0; i<n;i++){
				pRand = new Position(getRandomFreePosition());
				grille[pRand.getL()][pRand.getC()] = new Mur(pRand);
			}
		}
		else Ecran.afficherln("Pas de position libre disponible.\n");
	}
	
	void setRandBalle(){
		setRandBalle(1);
	}
	
	void setRandBalle(int n){
		Position pRand;
		if(existFreePositon()){
			for(int i=0; i<n;i++){
				pRand = new Position(getRandomFreePosition());
				grille[pRand.getL()][pRand.getC()] = new Balle(pRand);
			}
		}
		else Ecran.afficherln("Pas de position libre disponible.\n");
	}
	
	void setRandFaucheur(){
		setRandFaucheur(1);
	}
	
	void setRandFaucheur(int n){
		Position pRand;
		if(existFreePositon()){
			for(int i=0; i<n;i++){
				pRand = new Position(getRandomFreePosition());
				grille[pRand.getL()][pRand.getC()] = new Faucheur(pRand);
			}
		}
		else Ecran.afficherln("Pas de position libre disponible.\n");
	}
	
	void setRandAme(){
		setRandAme(1);
	}
	
	void setRandAme(int n){
		Position pRand;
		if(existFreePositon()){
			for(int i=0; i<n;i++){
				pRand = new Position(getRandomFreePosition());
				grille[pRand.getL()][pRand.getC()] = new Ame(pRand);
			}
		}
		else Ecran.afficherln("Pas de position libre disponible.\n");
	}
	
	void setRandResurrecteur(){
		setRandResurrecteur(1);
	}
	
	void setRandResurrecteur(int n){
		Position pRand;
		if(existFreePositon()){
			for(int i=0; i<n;i++){
				pRand = new Position(getRandomFreePosition());
				grille[pRand.getL()][pRand.getC()] = new Resurrecteur(pRand);
			}
		}
		else Ecran.afficherln("Pas de position libre disponible.\n");
	}
	
	void affichageGraphique(){
		int xFenetre=grille[0].length*20;
		int yFenetre=grille.length*20;
		int xCellule,yCellule;
		int l,c;
		String car;
		EcranGraphique.setClearColor(255,255,255);
		EcranGraphique.clear();
		EcranGraphique.init(50,50,xFenetre+40,yFenetre+80,xFenetre,yFenetre,"Damier");
		EcranGraphique.setColor(0,0,200);
		for(l=0;l<grille.length;l++){
			yCellule=20+l*20;
			for(c=0;c<grille[0].length;c++){
				car = grille[l][c].toString();
				xCellule=c*20;
				EcranGraphique.drawString(xCellule,yCellule,3,car);
			}
		}
		EcranGraphique.flush();
	}
	
	static void wait(int n){
		EcranGraphique.wait(n);
	}

	void evolution(){
		Position nextPos;
		for(int i=1;i<grille.length -1;i++){//lignes sauf la premiere et la derniere car mur oblatoirement
			for(int j=1;j<grille[0].length -1;j++){//colonnes sauf la premiere et la derniere car mur oblatoirement
				if(grille[i][j].isMovableObject()){
					//Ecran.afficherln("Objet (",i,";",j,") movible. Direction : ",grille[i][j].getDirectionString());
					if(!(isBlocked(i,j))&&!(isScanned(i,j))){
						//Ecran.afficherln("Objet (",i,";",j,") non bloque.");
						switch(grille[i][j].getType()){
							case 0:{
								nextPos = new Position(grille[i][j].getNextPosition());
								if(!isFree(nextPos))grille[i][j].setDirection(getFreeDirection(i,j,grille[i][j].getDirection()));
								nextPos = new Position(grille[i][j].getNextPosition());
								deplacer(grille[i][j].getPosition(),nextPos);
							}
							break;
							case 1:{
								nextPos = new Position(grille[i][j].getNextPosition());
								if(grille[nextPos.getL()][nextPos.getC()].getType()==2){
									Ame a = new Ame((Ame)(grille[i][j]));
									if(a.isAlive()) a.kill();
									grille[nextPos.getL()][nextPos.getC()] = new Ame(a);
								}
								scanned[nextPos.getL()][nextPos.getC()] = false;
								grille[i][j].setDirection(getFreeDirection(i,j,grille[i][j].getDirection()));
								nextPos = new Position(grille[i][j].getNextPosition());
								deplacer(grille[i][j].getPosition(),nextPos);
							}
							break;
							case 2:{
								
							/////////////////////////////////////////////////////////////////////////////////////////	
								nextPos = new Position(grille[i][j].getNextPosition());
								if(grille[nextPos.getL()][nextPos.getC()].getType()==2){
									Ame a = new Ame((Ame)(grille[i][j]));
									if(a.isAlive()) a.kill();
									grille[nextPos.getL()][nextPos.getC()] = new Ame(a);
								}
								scanned[nextPos.getL()][nextPos.getC()] = false;
								grille[i][j].setDirection(getFreeDirection(i,j,grille[i][j].getDirection()));
								nextPos = new Position(grille[i][j].getNextPosition());
								deplacer(grille[i][j].getPosition(),nextPos);
							////////////////////////////////////////////////////////////////////////////////////////
								
							}
							break;
							default: {}
						}
					}
					else{
						//Ecran.afficherln("Objet (",i,";",j,") bloque.");
						scanned[i][j] = true;
					}
				}
				scanned[i][j] = false;
				//else Ecran.afficherln("Objet (",i,";",j,") non movible.");
			}
		}
		resetScan();
	}
	
	boolean isScanned(int i, int j){
		return scanned[i][j];
	}
	
	private void resetScan(){
		for(int i=0;i<scanned.length;i++){
			for(int j=0;j<scanned[0].length;j++){
				scanned[i][j] = false;
			}
		}
	}
	
	void deplacer(Position currentPosition,Position nextPosition){
		int l = currentPosition.getL();
		int c = currentPosition.getC();
		int lNext = nextPosition.getL();
		int cNext = nextPosition.getC();
		grille[l][c].move();
		grille[lNext][cNext] = grille[l][c];
		grille[l][c] = new Vide(currentPosition);
		scanned[l][c] = true;
		scanned[lNext][cNext] = true;
	}
	
	Direction getFreeDirection(int i, int j,Direction currentDirection){
		Direction res = new Direction(-currentDirection.getL(),-currentDirection.getC());
		if(grille[i+res.getL()][j+res.getC()].isFree()) return res;
		boolean run = true;
		int l = i - 1;
		int c = j - 1;
		do{
			do{
				if(grille[l][c].isFree() && !(l==i && c==j)){
					run = false;
					res = new Direction(l-i,c-j);
				}
				else c++;
			}while(run && c<grille[0].length);
			c = j - 1;
			l++;
		}while(run && l<grille.length);
		return res;
	}
	boolean isBlocked(int i, int j){
		boolean res = true;
		int l = i - 1;
		int c = j - 1;
		do{
			do{
				if(grille[l][c].isFree()) res = false;
				else c++;
			}while(c != j+1 && res && c<grille[0].length);
			c = j - 1;
			l++;
		}while(l != i+1 && res && l<grille.length);
		return res;
	}
	boolean isFree(Position p){
		if(p.getL()>0 && p.getL()<(grille.length-1) && p.getC() >0 && p.getC()<(grille[0].length-1))return grille[p.getL()][p.getC()].isFree();
		else return false;
	}
	
	public static void pause(int nbMillisecondes){
		try {
			Thread.sleep(nbMillisecondes);
		}
		catch (Exception e){}
	}
	
	public String toString(){
		String res ="";
		for(int i=0;i<grille.length;i++){//lignes
			for(int j=0;j<grille[0].length;j++){//colonnes
				res += grille[i][j];
			}
			res += "\n";
		}
		return res;
	}
}