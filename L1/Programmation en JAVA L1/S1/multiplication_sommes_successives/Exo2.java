public class Exo2 {
public static void main(String[]args)
  {
	  int a,b,i,produit;
	  produit=0;
	  Ecran.afficher("Saisir un nombre entier a pour effectuer a*b ");
	  a=Clavier.saisirInt();
	  Ecran.sautDeLigne();
	  Ecran.afficher("Saisir un nombre entier b pour effectuer a*b ");
	  b=Clavier.saisirInt();
	  Ecran.sautDeLigne();
	  if(b>=0)
	  {
		  for(i=1;i<=b;i++)
		  {
			  produit=produit+a;
		  }
	  }
	  else
	  {
		  for(i=-1;i>=b;i--)
		  {
			  produit=produit-a;
		  }
	  }
	  Ecran.afficher("Le produit de ",a," par ",b," vaut ",produit);
	  Ecran.sautDeLigne();
  }
  }