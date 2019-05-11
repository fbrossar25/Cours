public class Exo7 {

static class date
  {
  int j = 1; //jour
  int m = 1; //mois
  int a = 1; //année
  }
public static void main(String[]args)
  {
  date d1 = new date();
  Ecran.afficher("SVP saisir une date (jour puis mois puis année) :\n");
  d1.j = Clavier.saisirInt();
  d1.m = Clavier.saisirInt();
  d1.a = Clavier.saisirInt();
  switch(d1.m)
    {
    case 1:{if (d1.j == 31){d1.j=1; d1.m=2;}else{d1.j++;}}break; //31 jours
    case 3:{if (d1.j == 31){d1.j=1; d1.m=4;}else{d1.j++;}}break;
    case 5:{if (d1.j == 31){d1.j=1; d1.m=6;}else{d1.j++;}}break;
    case 7:{if (d1.j == 31){d1.j=1; d1.m=8;}else{d1.j++;}}break;
    case 8:{if (d1.j == 31){d1.j=1; d1.m=9;}else{d1.j++;}}break; 
    case 10:{if (d1.j == 31){d1.j=1; d1.m=11;}else{d1.j++;}}break; 
    case 12:{if (d1.j == 31){d1.j=1; d1.m=1; d1.a++;}else{d1.j++;}}break;
    case 2: //mois de fevrier
      {
      if((d1.a%400==0)||((d1.a%4==0)&&(d1.a%100!=0))) //si bissextile
        {
        if(d1.j == 29){d1.j=1; d1.m=3;}else{d1.j++;}
        }
      else  //si pas bissextile
        {
        if(d1.j == 28){d1.j=1; d1.m=3;}else{d1.j++;}
        }
      }break;
    case 4:{if (d1.j == 30){d1.j=1; d1.m=5;}else{d1.j++;}}break; //320 jours
    case 6:{if (d1.j == 30){d1.j=1; d1.m=7;}else{d1.j++;}}break;
    case 9:{if (d1.j == 30){d1.j=1; d1.m=10;}else{d1.j++;}}break;
    case 11:{if (d1.j == 30){d1.j=1; d1.m=12;}else{d1.j++;}}break;
    }
  Ecran.afficher("\nDemain, nous serons le ",d1.j,"/",d1.m,"/",d1.a,".\n");  
}
}