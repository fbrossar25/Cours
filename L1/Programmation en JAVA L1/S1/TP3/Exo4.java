public class Exo4 {
public static void main(String[]args){
char lettre;
Ecran.afficher("Entrez une lettre : ");
Ecran.sautDeLigne();
lettre=Clavier.saisirChar();
if(lettre>='A' && lettre<='Z')
  {
  Ecran.afficher(lettre," est une lettre majuscule.");
  Ecran.sautDeLigne();
  }
else
  {
  if(lettre>='a' && lettre<='z')
    {
    Ecran.afficher(lettre," est une lettre minuscule.");
    Ecran.sautDeLigne();
    }
  else
    {
    Ecran.afficher(" Erreur de saisie : ",lettre," n'est pas une lettre.");
    Ecran.sautDeLigne();
    }
  }
}
}