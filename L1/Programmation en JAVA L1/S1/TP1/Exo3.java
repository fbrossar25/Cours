public class Exo3{
public static void main(String[]args){
String Prenom;
int Age,an_nais,an_act;
Ecran.afficher("Quel est votre pr�nom ? ");
Prenom=Clavier.saisirString();
Ecran.sautDeLigne();
Ecran.afficher("Quel est votre ann�e de naissance ? ");
an_nais=Clavier.saisirInt();
Ecran.sautDeLigne();
Ecran.afficher("Quel est l'ann�e actuelle ? ");
an_act=Clavier.saisirInt();
Ecran.sautDeLigne();
Age=an_act-an_nais;
Ecran.afficher("L'age que ",Prenom,"aura cette ann�e est : ",Age,"ans.");
Ecran.sautDeLigne;
  }
}

