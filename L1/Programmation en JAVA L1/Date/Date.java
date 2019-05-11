public class Date {
static class date {
	int a = 0;
	int m = 0;
	int j =0;
}
public static void main (String [] args) {
	date date = new date();
	Ecran.afficher("Entrer date (j m a) : \n");
	date.j = Clavier.saisirInt();
	date.m = Clavier.saisirInt();
	date.a = Clavier.saisirInt();
	switch(date.m)
	{
		case 1:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break; //mois 31 jours
		case 3:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break;
		case 5:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break;
		case 7:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break;
		case 8:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break;
		case 10:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break;
		case 12:{if(date.j==31){date.j=1;date.m=1;date.a++;}else{date.j++;}}break;
		case 4:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break; //mois 30 jours
		case 6:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break;
		case 9:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break;
		case 11:{if(date.j==31){date.j=1;date.m++;}else{date.j++;}}break;
		case 2:
			{  												//fevrier
				if((date.a%400==0)||(date.a%4==0&&date.a%100!=0)) //bissextile
					{
						if(date.j==29){date.j=1;date.m++;}else{date.j++;}
					}
				else
					{
						if(date.j==28){date.j=1;date.m++;}else{date.j++;}
					}
			}break;
	}
Ecran.afficher("Demain nous serons le :",date.j,"/",date.m,"/",date.a);
Ecran.sautDeLigne();
}
}