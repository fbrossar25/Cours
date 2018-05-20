public class Exo2{
public static void main(String[]args){
int a,b,c;
c=0;
Ecran.afficher("saisir un nombre entier a ");
a=Clavier.saisirInt();
Ecran.sautDeLigne();
Ecran.afficher("saisir un nombre entier b ");
b=Clavier.saisirInt();
Ecran.sautDeLigne();
c=a;
a=b;
b=c;
Ecran.afficher("Un échange entre a et b s'est produit : a=",a," et b=",b);
Ecran.sautDeLigne();  
  }  
}