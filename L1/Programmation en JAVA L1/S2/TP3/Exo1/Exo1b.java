public class Exo1b {

static boolean testCaractereAlphabetique(char c){
  boolean test=false;
  if ((c>='A' && c<='Z') || (c>='a' && c<='z')) test=true;
  return test;
}

public static void main(String[]args){
  char c=' ';
  boolean alphabetique;
  Ecran.afficher("SVP saisir un caract�re : \n");
  c=Clavier.saisirChar();
  alphabetique=testCaractereAlphabetique(c);
  if (alphabetique==true) Ecran.afficher("Votre caract�re est alphab�tique.");
  else Ecran.afficher("Votre caract�re n'est pas alphab�tique.");
}
}