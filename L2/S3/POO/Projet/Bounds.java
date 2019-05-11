class Bound extends Wall{

	Bound(){
		super();
	}

	Bound(int n,Position pDebut,Position pFin){
		super(n,p);
	}

	Direction redirect(Hunter p){
			return new Direction(-(p.getDir().getL()),-(p.getDir().getC()));
	}
}