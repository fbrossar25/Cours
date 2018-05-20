public class GoJeuxDeDes{
	static void choisirDesConserver(JeuDe jeu){
		int choix,i=0;
		boolean run=true;
		jeu.unblockAll();
		do{
			Ecran.afficherln("Chosir un dé à conserver (indice attendus/0 pour arrêter) :");
			choix = Clavier.saisirInt();
			if(choix == 0 ) run = false;
			else jeu.bloquerDe(choix-1);
			i++;
		}while(run && i<jeu.getNbDes());
	}
	
	static void jeu421(JeuDe jeu){
		jeu.lancerTout();
		int n=1;
		boolean run=true;
		do{
			System.out.println(jeu);
			if(!jeu.equals(new int[] {4,2,1})){
				choisirDesConserver(jeu);
				n++;
			}
			else{
				Ecran.afficher("Vous avez gagnez en "+n+" lancer(s) !!!\n");
				run = false;
			}
			if(run) jeu.lancer();
		}while(run);
	}
	
	public static void main (String[]args){
		JeuDe jeu = new JeuDe();
		jeu421(jeu);
	}
}