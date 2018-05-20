public class perimetrePolygone {
	static final int N=10; //taille des tableau, nombre de points max du polygone
	static final double MAX=50.0;//valeur max de la coordonnées tirés aléatoirement dans random
static class polygone {
	position2D [] tp = new position2D [N]; //coordonnées des pts du polygone
	int np = 0; //nombre de points
}
static class position2D {
	double x=0.0;
	double y=0.0;
}

static double random(double max){ //tire un nombre aléatoire entre 0 et MAX
	double res;
	res=Math.random()*max;
	return res;
}
static polygone pointPolyRandom(int n){ //créer des coordonnées aléatoire entre 0 et la constante MAX pour tout les pts du polygone
	int i;
	polygone p = new polygone();
	p.np=n;
	for(i=0;i<=N-1;i++){
		p.tp[i]=new position2D();
	}
	for(i=0;i<=n-1;i++){
		p.tp[i].x=random(MAX);
		p.tp[i].y=random(MAX);
	}
	return p;
}
static void affichagePointPoly(polygone poly){ //affiche les coordonnées de touts les points du polygone
	int i;
	for(i=0;i<=poly.np-1;i++){
		Ecran.afficher("\nPoint ",i+1," : x=",poly.tp[i].x,"  y=",poly.tp[i].y,"\n\n");
	}
}
static position2D barycentrePolygone(polygone poly){ //calcul des coordonnées du barycentre du polygone
	int i;
	position2D barycentre=new position2D();
	double sommeX=0.0,sommeY=0.0;
	for(i=0;i<=poly.np-1;i++){
		sommeX+=poly.tp[i].x;
		sommeY+=poly.tp[i].y;
	}
	barycentre.x=sommeX/poly.np;
	barycentre.y=sommeY/poly.np;
	return barycentre;
}

static double perimetrePolygone(polygone poly){ //calcul du perimetre
	int i;
	double perimetre=0.0,toto;
	for(i=1;i<=poly.np-1;i++){
		perimetre+=distance(poly.tp[i],poly.tp[i-1]);
	}
	return perimetre;
}

static double distance (position2D p1, position2D p2){
	return Math.sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

public static void main (String [] args) {
	//On choisis un nb aléatoire de points entre 1 et N, puit on place chaque coordonnées 
	//de points entre 0 et 10 aléatoirement et on calcule le perimetre et le barycentre du polygone
	int i=0;
	position2D barycentre = new position2D();
	polygone poly = new polygone();
	poly.np= (int)(Math.random()*N+1);//choisis un nombre aléatoire entre 1 et N
	Ecran.afficher("\nNombre de points du polygone P : ",poly.np,"\n\n");
	poly=pointPolyRandom(poly.np);
	affichagePointPoly(poly); //affichage des points
	barycentre=barycentrePolygone(poly); //calcul du barycentre
	Ecran.afficher("\nle perimetre du polygone P = ",perimetrePolygone(poly),"\n\n");
	Ecran.afficher("\nle barycentre du polygone P à pour coordonnées (",barycentre.x," , ",barycentre.y,")\n\n");
	
}
}