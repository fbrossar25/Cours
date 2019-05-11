public class Exo1 {
public static void main(String[]args){
float x,y;
Ecran.afficher("Entrez un nombre x : ");
x=Clavier.saisirFloat();
Ecran.sautDeLigne();
Ecran.afficher("Entrez un nombre y : ");
y=Clavier.saisirFloat();
Ecran.sautDeLigne();
if(x>y)
  {
  Ecran.afficher(y," > ",x);
  Ecran.sautDeLigne();
  }
else
  {
  if(x<y)
    {
    Ecran.afficher(x," < ",y);
    Ecran.sautDeLigne();
    }
  else{
  Ecran.afficher(y," = ",x);
  Ecran.sautDeLigne();
  }
  }
}
}