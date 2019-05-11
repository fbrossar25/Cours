public class Exo1e {
static void affichageEntierHexa(int a){
  char c1=' ',c2=' ';
  c1=conversionEntierHexa(a/16);
  c2=conversionEntierHexa(a%16);
  Ecran.afficher(a," en hexadécimal vaut : ",c1,c2,"\n");
  }

static char conversionEntierHexa(int a){
char c=' ';
switch(a){
  case 0 :{c='0';}break;
  case 1 :{c='1';}break;
  case 2 :{c='2';}break;
  case 3 :{c='3';}break;
  case 4 :{c='4';}break;
  case 5 :{c='5';}break;
  case 6 :{c='6';}break;
  case 7 :{c='7';}break;
  case 8 :{c='8';}break;
  case 9 :{c='9';}break;
  case 10 :{c='A';}break;
  case 11 :{c='B';}break;
  case 12 :{c='C';}break;
  case 13 :{c='D';}break;
  case 14 :{c='E';}break;
  case 15 :{c='F';}break;
}
return c;
}

public static void main(String[]args){
  
  int n;
  Ecran.afficher("SVP saisir un entier compris entre 0 et 255 :");
  n=Clavier.saisirInt();
  while(n<0||n>255) n=Clavier.saisirInt();
  affichageEntierHexa(n);
}
}