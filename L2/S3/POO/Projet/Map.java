class Map{
	Cell [][] grille;
	ArrayList <Wall> lWall;
	Bound [] tBound;
	boolean [][] scanned;
	Map(){
		this(10,10);
	}
	
	Map(int l, int c){
		if(l >= 5 && c >= 5){
			grille = new Cell [l][c];
			scanned = new boolean [l][c];
			//initialisation des 4 bords
			tBound = new Bound [4];
			tBound[1] = new Bound();
			//initialisation de chaque cases vide
			for(int i=1;i<grille.length-1;i++){//lignes
				for(int j=1;j<grille[0].length-1;j++){//colonnes
					grille[i][j] = new Free(i,j);
					scanned[i][j] = false;
				}
			}
		}
		else {
			Ecran.afficher("\n\nMap(l,c) doit avoir l et c >= 5\n\n");
			System.exit(1);
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
	
	void setRandWall(int n){
		if(existFreePositon()){
			
		}
		else Ecran.afficherln("Pas de position libre disponible.\n");
	}
	
	void setRandHunter(){
		setRandBalle(1);
	}
	
	void setRandHunter(int n){
		Position pRand;
		if(existFreePositon()){
			for(int i=0; i<n;i++){
				pRand = new Position(getRandomFreePosition());
				grille[pRand.getL()][pRand.getC()] = new Hunter(pRand);
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

	void evolution(){
		Position nextPos;
		for(int i=1;i<grille.length -1;i++){//lignes sauf la premiere et la derniere car mur oblatoirement
			for(int j=1;j<grille[0].length -1;j++){//colonnes sauf la premiere et la derniere car mur oblatoirement
				if(grille[i][j].isMovableObject()){
					if(!(isBlocked(i,j))&&!(isScanned(i,j))){
						nextPos = new Position(grille[i][j].getNextPosition());
						if(!isFree(nextPos))grille[i][j].setDirection(getFreeDirection(i,j,grille[i][j].getDirection()));
						nextPos = new Position(grille[i][j].getNextPosition());
						deplacer(grille[i][j].getPosition(),nextPos);
					}
				}
				scanned[i][j] = true;
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
		grille[l][c] = new Free(currentPosition);
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