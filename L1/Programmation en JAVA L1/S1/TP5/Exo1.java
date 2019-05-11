public class Exo1 {
public static void main(String[]args){
int table,produit,i;
Ecran.afficher("Entrez un nombre entier positif allant de 2 à 9 afin d'afficher sa table de multiplication: ");
table=Clavier.saisirInt();
Ecran.sautDeLigne();
for(i=1;i==10;i++){
  produit=table*i;
  Ecran.afficher(table,"*",i,"=",produit);
  Ecran.sautDeLigne();
}
}
}