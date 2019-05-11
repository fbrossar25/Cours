public class Exo4 {
public static void main(String[]args){
int i=0,j=0,N;
Ecran.afficher("Entrez un nombre N entier positif (pas trop gros pour éviter les bugs) ");
N=Clavier.saisirInt();
Ecran.sautDeLigne();
while(N<1)
  {
  Ecran.afficher("Entrez un nombre N entier positif (pas trop gros pour éviter les bugs)");
  N=Clavier.saisirInt();
  Ecran.sautDeLigne();
  }
for(j=1;j<=N;j++)
  {
  for(i=1;i<=N;i++)
    {
    Ecran.afficher("* ");
    }
  Ecran.sautDeLigne();
  }
}
}