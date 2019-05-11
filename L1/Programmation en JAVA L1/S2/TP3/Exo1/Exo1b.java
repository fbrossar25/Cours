public class Exo1b {

static boolean testCaractereAlphabetique(char c){
  boolean test=false;
  if ((c>='A' && c<='Z') || (c>='a' && c<='z')) test=true;
  return test;
}

public static void main(String[]args){
  char c=' ';
  boolean alphabetique;
  Ecran.afficher("SVP saisir un caractère : \n");
  c=Clavier.saisirChar();
  alphabetique=testCaractereAlphabetique(c);
  if (alphabetique==true) Ecran.afficher("Votre caractère est alphabétique.");
  else Ecran.afficher("Votre caractère n'est pas alphabétique.");
}
}