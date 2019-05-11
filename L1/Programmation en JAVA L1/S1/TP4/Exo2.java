public class Exo2 {
public static void main(String[]args){
int jour,n;
Ecran.afficher("Entrer un nombre de 1 à 7 (représentant 1 pour Lundi, 2 pour Mardi, etc...) représentant le jour : ");
jour=Clavier.saisirInt();
Ecran.sautDeLigne();
if((jour<1)||(jour>7)){
    Ecran.afficher("Erreur de saisie, fermeture du programme...");
    Ecran.sautDeLigne();
    }
else{
      Ecran.afficher("Entrer le nombre de jour écoulés (nombre entier strictement positif) : ");
      n=Clavier.saisirInt();
      Ecran.sautDeLigne();
      while(n>7){
          n=n-7;
      }
      switch(n){
          case 1:{
              Ecran.afficher("Mardi");
              Ecran.sautDeLigne();
          }
          break;
        
          case 2:{
              Ecran.afficher("Mercredi");
              Ecran.sautDeLigne();
          }
          break;
          
          case 3:{
              Ecran.afficher("Jeudi");
              Ecran.sautDeLigne();
          }
          break;

          case 4:{
              Ecran.afficher("Vendredi");
              Ecran.sautDeLigne();
          }
          break;
        
          case 5:{
              Ecran.afficher("Samedi");
              Ecran.sautDeLigne();
          }
          break;
          
          case 6:{
              Ecran.afficher("Dimanche");
              Ecran.sautDeLigne();
          }
          break;

          case 7:{
              Ecran.afficher("Lundi");
              Ecran.sautDeLigne();
          }
          break;
        
          default:{
              Ecran.afficher("Erreur de saisie");
              Ecran.sautDeLigne();
          }
      }
}
}
}