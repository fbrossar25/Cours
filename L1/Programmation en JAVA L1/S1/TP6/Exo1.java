public class Exo1 {
public static void main(String[]args)
  {
  int a,b,reponse=0,resultat,points=0,nb_essais=0,tirage_operateur,n_questions=0;
  int continuer;
  //a et b sont les deux op�randes tir�es al�atoirement
  //resultat est le resultat de a operande b
  //point est le nombre de points gagn� par l'utilisateur
  //nb_essais est le nombre d'essais effectu�
  //tirage_operateur permet de tir� al�atoirement la variable op�rateur (caract�re)
  //reponse est la r�ponse donn�e par l'utilisateur
  //continuer est un bool�en pour un autre calcul ou non
  char operateur;
  Ecran.afficher("Toutes les r�ponses attendues sont des nombres entiers positifs non nul");
  Ecran.sautDeLigne();
  do
    {
    n_questions++;
    a=(int)((Math.random()*11)+10); //tirage de a entre 10 et 20
    b=(int)((Math.random()*11)+10); //tirage de b entre 10 et 20
    //tirage de la'op�rateur *; /; +; -
    tirage_operateur=(int)((Math.random()*4)+1);
    switch(tirage_operateur) //on calcul le r�sultat attendus
    {
    case 1:
      {
      operateur='*';
      resultat = a * b;
      }
    break;
    case 2:
      {
      operateur='/';
      resultat = a / b;
      }
    break;
    case 3:
      {
      operateur='-';
      resultat = a - b;
      }
    break;
    case 4:
      {
      operateur='+';
      resultat = a + b;
      }
    break;
    default :
      {
      operateur='+';
      resultat = a + b;
      }
    }
  while(reponse!=resultat && nb_essais <=2)
    {
    Ecran.afficher(a,operateur,b," = ? ");  //on demande la r�ponse � l'utilisateur
    reponse=Clavier.saisirInt();
    Ecran.sautDeLigne();
    nb_essais ++;
    if(reponse!=resultat)  //on v�rifie la r�ponse
    {
    Ecran.afficher("Mauvaise R�ponse !");
    Ecran.sautDeLigne();
    }
  }
switch(nb_essais)
  {
  case 1:
    {
    points=points+10;
    }
  break;
  case 2:
    {
    points=points+6;
    }
  break;
  case 3:
    {
    points=points+2;
    }
  break;
  default:
    {
    points=points+0;
    }
  break;
  }
if(reponse==resultat)
  {
  Ecran.afficher("Bonne R�ponse ! Avec ",nb_essais," essais. Votre moyenne est de ",points/n_questions," points sur 10."); //r�ussite
  Ecran.sautDeLigne();
  }
else
  {
  Ecran.afficher("Vous n'avez pas trouv� la bonne r�ponse au bout de trois essai"); //�chec
  Ecran.sautDeLigne();
  }
do
  {
  Ecran.afficher("Voulez-vous continuer ? (1 pour oui; 0 pour non)");
  continuer=Clavier.saisirInt();
  }while(continuer!=1 && continuer !=0);
nb_essais=0;
}while(continuer!=0);
}
}