public class Exo2 {
public static void main(String[]args){
int table,produit,i;
Ecran.afficher("Entrez un nombre entier positif allant de 2 à 9 afin d'afficher sa table de multiplication: ");
table=Clavier.saisirInt();
Ecran.sautDeLigne();
while ((table<2)||(table>9)){//verif saisie
  Ecran.afficher("Erreur de saisie.");
  Ecran.sautDeLigne();
  Ecran.afficher("Entrez un nombre entier positif allant de 2 à 9 afin d'afficher sa table de multiplication: ");
  table=Clavier.saisirInt();
  Ecran.sautDeLigne();
}
for(i=1;i<=10;i++){
  produit=table*i;
  Ecran.afficher(table,"*",i,"=",produit);
  Ecran.sautDeLigne();
}
}
}