public class Calculatrice_Florian_Brossard {
public static void main(String[]args){
float nb1,nb2,result;                     //nb1 est le premier nombre saisis, nb2 est le second, result est le resultat de l'op�ration
char operateur;                        
result=0;
Ecran.afficher("saisissez un premier nombre : ");                      //on demande � l'utilisateur de saisir un premier nombre entier
nb1=Clavier.saisirInt();
Ecran.sautDeLigne();
Ecran.afficher("saisissez une op�ration (+,-,* ou /) � effectuer : "); //on demande � l'utilisateur de saisir un op�rateur
operateur=Clavier.saisirChar();
Ecran.sautDeLigne();
Ecran.afficher("saisissez un deuxi�me nombre : ");                     //on demande � l'utilisateur de saisir un second nombre entier
nb2=Clavier.saisirInt();
Ecran.sautDeLigne();
switch(operateur){                                                     //on change de cas en fonction de l'op�rateur saisie
case '+':             //addition
  {result=nb1+nb2;
  }
break;
case '-':             //soustraction
  {result=nb1-nb2; 
  }
break;
case '*':            //multiplication
  {result=nb1*nb2;
  }  
  break;
case '/':            //division
  {if (nb2==0)
  {Ecran.afficher("Division par 0 impossible");
  Ecran.sautDeLigne();
  }
  else
  { 
  result=nb1/nb2;
  }
}
  break;
default :
  {
  Ecran.afficher("Erreur de saisie");  //si on saisie autre chose que ces 4 op�rateur, le message d'erreur suivant est affich�
  Ecran.sautDeLigne();
  }
}
if(nb2<0)
  {
  switch(operateur){
  case'-':
    {nb2=nb2*(-1);
    Ecran.afficher(nb1,"+",nb2,"=",result);  //si nb2 est n�gatif on en remplace "--" dans l'op�ration par "+" seulement
    Ecran.sautDeLigne();
    }
  break;
  case'+':
    {
    Ecran.afficher(nb1,nb2,"=",result);  //si nb2 est n�gatif on en remplace "+-" dans l'op�ration par "-" seulement
    Ecran.sautDeLigne();
    }
  break;
  }
}
else
  {Ecran.afficher(nb1,operateur,nb2,"=",result); //on affiche l'op�ration et son r�sultat
  Ecran.sautDeLigne();
  }
}  //fin du programme
}
