public class Exo2 {
public static void main(String[]args){
int n;
Ecran.afficher("Entrez un nombre entier : ");
n=Clavier.saisirInt();
Ecran.sautDeLigne();
if((n-10)<0){
Ecran.afficher(n," est un nombre.");
Ecran.sautDeLigne();
}
else{
Ecran.afficher(n," est un chiffre.");
Ecran.sautDeLigne();
}
}
}
