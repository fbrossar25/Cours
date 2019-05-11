public class Exo5 {
	static class position2D 
	{
		double x = 0.0;
		double y = 0.0;
	}
	static class triangle2D
	{
		position2D A = new position2D();
		position2D B = new position2D();
		position2D C = new position2D();
	}
	public static void main(String[]args)
	{
		triangle2D ABC = new triangle2D();
		double surface = 0.0;
		Ecran.afficher("SVP coordonnées (x,y) du point A du trianble ABC : \n");
		ABC.A.x=Clavier.saisirDouble();
		ABC.A.y=Clavier.saisirDouble();
		Ecran.afficher("\nSVP coordonnées (x,y) du point B du trianble ABC : \n");
		ABC.B.x=Clavier.saisirDouble();
		ABC.B.y=Clavier.saisirDouble();
		Ecran.afficher("\nSVP coordonnées (x,y) du point C du trianble ABC : \n");
		ABC.C.x=Clavier.saisirDouble();
		ABC.C.y=Clavier.saisirDouble();
		//surface = |(Ax+Bx) * (Ay-By) * (Bx+Cx) * (By-Cy) * (Cx+Ax) * (Cy-Ay)|
		surface = Math.abs((ABC.A.x+ABC.B.x)*(ABC.A.y-ABC.B.y)+(ABC.B.x+ABC.C.x)*(ABC.B.y-ABC.C.y)+(ABC.C.x+ABC.A.x)*(ABC.C.y-ABC.A.y));
		Ecran.afficher("La surface du triangle ABC est :",surface," m².\n");
	}
}