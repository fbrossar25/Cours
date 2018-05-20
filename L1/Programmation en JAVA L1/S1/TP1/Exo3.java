public class Exo3{
public static void main(String[]args){
String Prenom;
int Age,an_nais,an_act;
Ecran.afficher("Quel est votre prénom ? ");
Prenom=Clavier.saisirString();
Ecran.sautDeLigne();
Ecran.afficher("Quel est votre année de naissance ? ");
an_nais=Clavier.saisirInt();
Ecran.sautDeLigne();
Ecran.afficher("Quel est l'année actuelle ? ");
an_act=Clavier.saisirInt();
Ecran.sautDeLigne();
Age=an_act-an_nais;
Ecran.afficher("L'age que ",Prenom,"aura cette année est : ",Age,"ans.");
Ecran.sautDeLigne;
  }
}

