public class Exo3 {
public static void main(String[]args){
float poids;
Ecran.afficher("Entrez le poids en grammes de votre lettre : ");
Ecran.sautDeLigne();
poids=Clavier.saisirFloat();
if(poids>=100)
  {
  Ecran.afficher("Le prix d'affranchissement d'une lettre de ",poids," grammes est de 1.55 euros");
  Ecran.sautDeLigne();
  }
else
  {
  if(poids<=20)
    {
    Ecran.afficher("Le prix d'affranchissement d'une lettre de ",poids," grammes est de 0.63 euros");
    Ecran.sautDeLigne();
    }
  else
    {
    Ecran.afficher("Le prix d'affranchissement d'une lettre de ",poids," grammes est de 1.05 euros");
    Ecran.sautDeLigne();
    }
  }
}
}