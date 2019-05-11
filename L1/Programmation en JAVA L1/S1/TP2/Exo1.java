public class Exo1 {
public static void main(String[]args){
float longueur,largeur,perimetre;
Ecran.afficher ("Saisir une longueur ");
longueur=Clavier.saisirFloat();
Ecran.afficher ("Saisir une largeur ");
Ecran.sautDeLigne();
largeur=Clavier.saisirFloat();
perimetre=2*longueur + 2*largeur;
Ecran.afficher("Le perimetre d'un rectangle de longueur ",longueur,"m et de largeur ",largeur,"m est : ",perimetre,"m.");
}
}
