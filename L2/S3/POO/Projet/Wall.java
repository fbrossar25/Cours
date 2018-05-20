class Wall extends Cell{
	private ArrayList <Stone> l;
	private boolean isVertical;
	Wall(){
		this(new Position(),new Position());
	}

	Wall(Position pDebut,Position pFin){
		l = new ArrayList <Stone>();
		pos = pDebut;
		boolean isNotVerOrHon = (pDebut.getL() != pFin.getL()) && (pDebut.getC() != pFin.getC());
		isVertical = (pDebut.getL() == pFin.getL()) && (pDEbut.getC() != pFin.getC());
		if( pDebut.equals(pFin) || isNotVerOrHon){//si le mur est de taille 1 OU si on donne des mauvaises position (mur ni horizontal ni vertical)
			l.add(pDebut);
			isVertical = false;
		}
		else if(isVertical){
			if(pDebut.getC() > pFin.getC()){
				int i=0;
				do{
					l.add(new Stone(pDEbut().getL() - i,pDebut.getC()));
					i++;
				}while(l.get(l.length() - 1).getL() != pFin.getL());
			}
			else{
				do{
					l.add(new Stone(pDEbut().getL() + i,pDebut.getC()));
					i++;
				}while(l.get(l.length() - 1).getL() != pFin.getL());
			}
		}
		else{
			if(pDebut.getC() > pFin.getC()){
				int i=0;
				do{
					l.add(new Stone(pDEbut().getL(),pDebut.getC() - i));
					i++;
				}while(l.get(l.length() - 1).getC() != pFin.getC());
			}
			else{
				do{
					l.add(new Stone(pDEbut().getL(),pDebut.getC() + i));
					i++;
				}while(l.get(l.length() - 1).getC() != pFin.getC());
			}
		}
	}

	boolean hasStoneIn(Position pos){
		return l.contains(new Stone(pos));
	}

	boolean hasStoneIn(int l, int c){
		return l.contains(new Stone(l,c));
	}

	private Stone getStone(Position p){
		int i=0;
		boolean run = true;
		do{
			if(p.equals(l.get(i).getP())){
				run = false;
			}
			else i++;
		}while(run && i < l.length());
		if(run)return null;
		else return l.get(i);
	}

	Direction redirect(Hunter p){
		if(p.getNextPosition().equals(l.get(0).pos)){//si le perso se dirige vers le premier bord
			if(p.getPosition().estAdjacent(l.get(0)).pos){//si il est sur une case adjacente a celle du bout du mur

			}
		}
		else if(p.getNextPosition().equals(l.get(l.length()-1).pos)){//si le perso se dirige vers le second bord
			if(p.getPosition().estAdjacent(l.get(l.length()-1)).pos){

			}
		}
		else{

		}
	}
}