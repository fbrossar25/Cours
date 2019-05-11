public class Exo1 {
public static void main(String[]args){
int Nombre1,Nombre2,Produit;
Ecran.afficher("Entrer un nombre entier ");
Nombre1 = Clavier.saisirInt();
Ecran.sautDeLigne();
Ecran.afficher("Entrer un nombre entier ");
Nombre2 = Clavier.saisirInt();
Ecran.sautDeLigne();
Produit=Nombre1*Nombre2;
Ecran.afficher("Le produit de ",Nombre1," et ",Nombre2," vaut : ",Produit);
Ecran.sautDeLigne();
  }
}
