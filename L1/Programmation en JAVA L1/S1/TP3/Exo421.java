public class Exo421 {
public static void main(String[]args){
int d1,d2,d3,relance,n_d,n_relance1,n_relance2;
d1=(int)((Math.random()*6)+1);
d2=(int)((Math.random()*6)+1);
d3=(int)((Math.random()*6)+1);
Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
Ecran.sautDeLigne();
Ecran.afficher("Combien de dé voulez-vous relancer (0,1,2 ou 3) ? ");
Ecran.sautDeLigne();
relance=Clavier.saisirInt();
switch (relance){
1:{Ecran.afficher("Quel dé voulez-vous relancer ? (1,2 ou 3) ?");
Ecran.sautDeLigne();
n_d=Clavier.saisirInt();
if (n_d=1)
  {d1=(int)((Math.random()*6)+1);
  Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
  Ecran.sautDeLigne();
  }
else
  {if (n_d=2)
  {d2=(int)((Math.random()*6)+1);
  Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
  Ecran.sautDeLigne();
  }
else
  {d3=(int)((Math.random()*6)+1);
  Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
  Ecran.sautDeLigne();
  }
}
}
2:{Ecran.afficher("Quel dé voulez-vous relancer ? (1,2 ou 3) ?");
Ecran.sautDeLigne();
n_relance1=Clavier.saisirInt();
Ecran.afficher("Quel autre dé voulez-vous relancer ? (1,2 ou 3) ?");
Ecran.sautDeLigne();
n_relance2=Clavier.saisirInt();
if(n_relance1=1)
  {d1=(int)((Math.random()*6)+1);
  Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
  Ecran.sautDeLigne();
  }
else
  {if (n_relance1=2)
  {d2=(int)((Math.random()*6)+1);
  Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
  Ecran.sautDeLigne();
  }
else
  {d3=(int)((Math.random()*6)+1);
  Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
  Ecran.sautDeLigne();
  }
}
if(n_relance2=1)
  {d1=(int)((Math.random()*6)+1);
  Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
  Ecran.sautDeLigne();
  }
else
  {if (n_relance2=2)
  {d2=(int)((Math.random()*6)+1);
  Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
  Ecran.sautDeLigne();
  }
else
  {d3=(int)((Math.random()*6)+1);
  Ecran.afficher("Lancer : [",d1,"] [",d2,"] [",d3,"]");
  Ecran.sautDeLigne();
  }
}
}



