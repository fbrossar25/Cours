public class Exo1 {
public static void main(String[]args){
char operation;
int compte,somme;
operation='a';
Ecran.afficher("Entrez un nombre entier strictement positif correspondant à la somme d'argent sur votre compte : ");
compte=Clavier.saisirInt();
while(compte<0){
      Ecran.afficher("Erreur de saisie veuillez réessayer ");
      compte=Clavier.saisirInt();
      Ecran.sautDeLigne();
}
Ecran.sautDeLigne();
while(operation!='q'){
      Ecran.afficher("Vous avez ",compte," euros sur votre compte.");
      Ecran.sautDeLigne();
      Ecran.afficher("Quelle opération souhaitez-vous effectuez ? (entrez r pour retrait, d pour dépot et q pour fermer le programme)");
      operation=Clavier.saisirChar();
      Ecran.sautDeLigne();
  switch(operation){
    case 'd' : {
      Ecran.afficher("Entrez la somme (nombre entier strictement positif) à déposer : ");
      somme=Clavier.saisirInt();
      Ecran.sautDeLigne();
      while(somme<0){
          Ecran.afficher("Erreur de saisie Veuillez réessayez : ");
          somme=Clavier.saisirInt();
          Ecran.sautDeLigne();
      }
      compte=compte+somme;
    }
    break;
  
    case 'r' : {
      Ecran.afficher("Entrez la somme (nombre entier strictement positif) à retirer : ");
      somme=Clavier.saisirInt();
      Ecran.sautDeLigne();
      while(somme<0){
          Ecran.afficher("Erreur de saisie Veuillez réessayez : ");
          somme=Clavier.saisirInt();
          Ecran.sautDeLigne();
      }
      if (somme>compte){
          Ecran.afficher("Votre solde ne permet pas cette opération.");
          Ecran.sautDeLigne();
          }
      else{
      compte=compte-somme;
      }
    }
    break;
  
      case 'q' : {
      Ecran.afficher("Arret du programme...");
      Ecran.sautDeLigne();
    }
    break;
  
    default:{
      Ecran.afficher("Erreur de saisie; veuillez recommencez");
      Ecran.sautDeLigne();
    }
  }
}
}
}
    


    