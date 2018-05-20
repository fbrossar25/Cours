public class CastHoraire{
	public static void main(String [] args){
		Horaire h1= new Horaire(1,1,1), h2 = new Horaire(2,2,2);
		HorairePrecis hp1=new HorairePrecis(3,3,3,3), hpP2=new HorairePrecis(4,4,4,4);
		System.out.println("h1 = "+h1);
		System.out.println("h2 = "+h2);
		System.out.println("hp1 = "+hp1);
		System.out.println("hp2 = "+hp2);
		System.out.print("\n\n");
		h1 = hp1 ; // OK compil, OK exec car HorairePrecis est un horaire
		//h2 = hp2;
		System.out.println("h1 = "+h1);
		System.out.println("hp1 = "+hp1+"\n\n");
		//hp2 = h2 ; //erreur compil car Horaire n'est pas un HorairePrecis
		hp1 = (HorairePrecis) h1 ; // OK compil, OK exec car h1 est deja une étiquette de hp1 donc h1 est un HorairePrecis
		System.out.println("hp1 = "+hp1);
		hp2 = (HorairePrecis) h2 ; //OK compil, erreur exec car Horaire n'est pas un HorairePrecis
		//on peut cast un sous-classe avec sa super classe mais pas l'inverse
		System.out.println("hp2 = "+hp2);
	}
}