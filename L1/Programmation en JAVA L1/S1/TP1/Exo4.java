public class Exo4{
public static void main(String[]args){
double rayon,perimetre,aire,PI;
PI=3.14;
Ecran.afficher("Quel est le rayon du cercle ? ");
Ecran.sautDeLigne();
rayon=Clavier.saisirFloat();
perimetre=2*PI*rayon;
aire=PI*rayon*rayon;
Ecran.afficher("Le rayon du périmètre du cerlce est ",perimetre," et son aire vaut ",aire);
Ecran.sautDeLigne();
  }
}

