public class Interets {
public static void main (String [] args) {
float capital,taux,interets;
//Saisi des donn�es
Ecran.afficher("Montant du capital ?");
capital = Clavier.saisirFloat();
Ecran.afficher("Montant du taux ? ");
taux=Clavier.saisirFloat();
//Traitement
interets=capital*taux/100;
//R�sultat(s)
Ecran.afficher("Les interets : ",interets, " au bout d'un an");
Ecran.sautDeLigne();
  }
}