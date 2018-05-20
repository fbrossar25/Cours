public class rectangle{
	int h = 0;
	int l = 0;
	point csg = new point();
	void setPos(double x, double y){
		csg.x = x;
		csg.y = y;
	}
	point getMilieu(){
		point c = new point();
		c.x = csg.x + (l/2);
		c.y = csg.y + (h/2);
		return c;
	}
	int aire(){
		return (l*h);
	}
	int perimetre(){
		return (l*2 + h*2);
	}
	void setSize(int hToSet, int lToSet){
		h = hToSet;
		l = lToSet;
	}
	void dessinePlein(){
		if(h>0 && l>0){
			for(int i=0;i<h;i++){
				for(int j=0;j<l;j++){
					Ecran.afficher(" * ");
				}
				Ecran.sautDeLigne();
			}
		}
	}
	void dessineCreux(){
		if(h>0 && l>0){
			for(int i=0;i<h;i++){
				for(int j=0;j<l;j++){
					if(i==0 || (j==0 || j==(l-1)) || i==(h-1))Ecran.afficher(" * ");
					else Ecran.afficher(" .  ");
				}
				Ecran.sautDeLigne();
			}
		}
	}
	void dessineRepere(){
		point c = new point();
		int csgX = (int)(csg.x);
		int csgY = (int)(csg.y);
		int tx = (int)(c.x) + 5;
		int ty = (int)(c.y) + 5;
		for(int i =0; i<ty;i++){
			for(int j = 0; j < tx ; j++){
				if (j==0){
					if(csgX > 0){
						if(i==0) Ecran.afficher("^");
						else Ecran.afficher("|");
					}
					else Ecran.afficher(" * ");
				}
				if (i==(csgY-1)){
					if(j>=(csgX-1) && j<(csgX+ l))
				}
			}
			Ecran.sautDeLigne();
		}
		Ecran.afficher("\n\n");
	}
}