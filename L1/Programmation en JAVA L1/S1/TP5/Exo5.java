public class Exo5 {
	public static void main(String[]args){
		int espace,largeur,hauteur;
		//i,j et k sont des compteurs, espace est le nombre d'espace � afficher avant d'afficher les �toiles,ligne est le numero de la ligne en cours de traitement (en partant du haut ou ligne =1), largeur la largeur du tronc
		Ecran.afficher("Entrez la hauteur du tronc de l'arbre (nombre entiers sup�rieur ou �gal � 3) : ");
		hauteur=Clavier.saisirInt();
		while (hauteur<3){