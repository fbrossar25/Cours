//Sujet N°4 : développé par BROSSARD Florian et BEGUE Adrien, L1ST I1 A1
public class Sujet4_BEGUE_BROSSARD{
	static final double V_INIT=400.0;//vitesse initiale des billes lancées
	static final double T_AFFICHAGE=0.015; //temps avant le prochain affichage si aucun n'évenement ne se produit
	static final int R=9;//rayon des billes
	static final int Y=400;//largeur du billard (partie jouable) en Y
	static final int X=Y*2;//longueur du billard (partie jouable) en x
        /*
	type agrégé couleur
	r,v et b sont de type entier et représente respectivement les composantes rouge, verte et bleue de la couleur d'une bille
        */
	static class couleur{
		int r=255;
		int v=255;
		int b=255; 
	}
	/*
	type agrégé position 2D
	x et y sont de type réel (double) et représentent respectivement les coordonnées en abscisses (x) et ordonnées (y)
        */
	static class position2D{
		double x=0.0;
		double y=0.0;
	}
      
	/*
	type agrégé evenement
	//type et un entier représentant le type de l'évenement :
	
		0 => pas d'evenement : affichage
		1 => choc bille/bordure droite
		2 => choc bille/bordure gauche
		3 => choc bille/bordure superieure
		4 => choc bille/bordure inferieure
		5 => choc bille/bille
	
	time et de type double et représente la "date" à laquelle l'évenement auras lieu (le temps est relatif et non réaliste)
	b est de type entier et donne le numero de la bille impliquée dans l'évenement quel qu'il soit
	bc est de type entier et représente, dans le cas d'un choc entre deux billes, le numero de la bille bc avec laquelle la bille b entre en choc
        */
	static class evenement{
		int type=0;
		double time=Double.MAX_VALUE; 
		int b=-1;
		int bc=-1;
	}
	
	/*
	type agrégé bille
	numero est un entier représentant le numero de la bille
	d et c sont de type position2D et représentent respectivement la direction et la position du centre de la bille
	color est de type couleur et définis la couleur de la bille
	v est un réel de type double représentant la vitesse (elle aussi relative et non réaliste) de la bille
        */
	static class bille{
                int numero=0;
		position2D d = new position2D();
		position2D c = new position2D();
		couleur color = new couleur();
		double v = 0.0;
	}
	
	/*
        type agrégé parametre
	gestionChoc est un booleen représentant le fait de gérer les choc inter-billes ou non
	lancement est un booleen représentant le fait que l'on est bien parametré la simulation (que l'on ais choisis un des choix proposés dans le menu principale)
	placementTriangle est booleen représentant le fait qu'il faille placé les bille sous forme de triangle (true) ou sous forme de ligne (false)
	nbBille est un entier représentant le nombre de billes placées et utilisées pour la simulation
        */
	static class parametre{
		boolean gestionChoc = true;
		boolean lancement=false; //lancement de la simulation ?
		boolean placementTriangle=false; // placement de type une bile vers 15 en triangle
		int nbBille = 0; //nombre de bille entre 0 et 16 (0 pas de bille donc pas de simulation)
	}
	/*
	type agrégé table
	temps est un réel de type double représentant le temps (relatif) écoulé depuis le démarrage de la simulation
	p est de type parametre et représente le paramètrage choisis pour la simulation
	t est un tableau [16] de bille contenant les potentielles 16 billes utilisées lors de la simulation
	lng et lrg sont de type entier et représentent respectivement la longueur (axe x) et la largeur (axe y) de la table de billard (partie 'jouable'). Elles sont définies par les constantes X et Y
      */
	static class table{
		double temps = 0.0; //temps écoulé depuis le début de la simulation en seconde
		parametre p = new parametre();
		bille [] t = new bille [16]; //nombre de bille
		int lng = X; //longueur en pixels
		int lrg = Y; //largeur en pixels
	}
	
      
	/**
        *définis la fenêtre de dessin et dessine le billard sans bille
        *@param table billard variable de type table
        *@return aucun retour
        **/
	static void demarrageAffichage(table billard){
		String s="Temps : "+(float)(billard.temps);
		EcranGraphique.setClearColor(0,30,0);
		EcranGraphique.clear();
		EcranGraphique.init(100,50,X+90,Y+150,X+50,Y+50,"Billard"); //affiche de la partie noir du billard et ouvre la fenêtre de dessin
		EcranGraphique.setColor(0,130,0);
		EcranGraphique.fillRect(25,25,billard.lng,billard.lrg); //dessine la partie verte du billard
		EcranGraphique.setColor(255,0,0);
		EcranGraphique.drawString(0,Y+50,3,s); //affichage du temps
		EcranGraphique.flush(); //affiche l'image
	}
      
        /**
        *dessine le billard (partie verte de la fenêtre de dessin) afin d'avoir un support et affiche le temps de la simulation
        *@param table billard variable de type table
        *@return aucun retour
        **/
	static void tamponBillard(table billard){
		String s="Temps : "+(float)(billard.temps);
		EcranGraphique.clear();
		EcranGraphique.setColor(0,130,0);
		EcranGraphique.fillRect(25,25,billard.lng,billard.lrg); //dessine la partie verte du billard
		EcranGraphique.setColor(255,0,0);
		EcranGraphique.drawString(0,Y+50,3,s); //affichage du temps
	}
      
        /**
        *déclare toutes les billes du tableau de billes
        *@param table billard variable de type table
        *@return table billard retourne le billard une fois déclaré
        **/
	static table initBillard(table billard){//rend le billard utilisable
		int i;
		for(i=0;i<billard.t.length;i++){
			billard.t[i] = new bille();
		}
		return billard;
	}
	
	/**
        *menu du paramètrage de la simulation
        *@param table billard variable de type table
        *@return table billard retourne le billard une fois paramètré
        **/
	static table parametrageSimu (table billard){//on parametre notre simulation
		int i,choix=0;
		Ecran.afficher("\n SVP choisir : \n 1.Une Bille \n 2.n Bille en ligne avec gestion des chocs entre billes \n 3.n Bille en ligne sans gestion des chocs entre billes \n 4.Une Bille seule avec direction aléatoire vers 15 Billes diposés en triangle \n 5.Une Bille seule allant tout droit vers 15 Billes diposés en triangle \n");
		choix=Clavier.saisirInt();
		switch(choix){
			
			case 1:{//une bille seule
				billard.p.nbBille=1;
				billard=gestionCouleur(billard);
                                billard.t[0].numero=0;
				billard.t[0].c.x=(billard.lng/2)+25.0;
				billard.t[0].c.y=(billard.lrg/2)+25.0;
				billard=directionRandom(billard);
				affichage(billard);
			}break;
			
			case 2:{//n billes en ligne avec gestion des chocs bille/bille
				billard=placementBilleEnLigne(billard);
				affichage(billard);
				billard=directionRandom(billard);
			}break;
			
			case 3:{//n billes en ligne sans gestion des chocs bille/bille
				billard=placementBilleEnLigne(billard);
				billard.p.gestionChoc=false;
				affichage(billard);
				billard=directionRandom(billard);
			}break;
			
                        case 4:{//une bille seule avec un direction aléatoire vers 15 autres placées en triangle
                                billard.p.nbBille=16;
				billard.t[0].d.x=Math.sin((Math.random()*Math.PI));
				billard.t[0].d.y=Math.cos((Math.random()*Math.PI));
                                billard=placementBilleUneVersTriangle(billard);
                                affichage(billard);
                        }break;
			
			case 5:{//une bille seule allant tout droit vers les 15 autres placées en triangle
                                billard.p.nbBille=16;
				billard.t[0].d.x=1.0;
				billard.t[0].d.y=0.0;
                                billard=placementBilleUneVersTriangle(billard);
                                affichage(billard);
                        }break;
			
			default : {//erreur de saisie
				Ecran.afficherln("\nchoix = ",choix);
				Ecran.afficherln("\nErreur de saisie, arrêt du programme...");
				EcranGraphique.wait(1000);
				System.exit(0);
			}
		}
		Ecran.afficher("\n SVP choisir : \n 1.Lancement de la simulation \n Autre : abandon de la simulation\n");
		if(Clavier.saisirInt()==1) billard.p.lancement=true;
		else {
			Ecran.afficher("Abandon de la simulation...");
			EcranGraphique.wait(1000);
			System.exit(0);
		}
		return billard;
	}
      
	/**
        *place les billes sur la ligne horizontale centrale du billard
        *@param table billard variable de type table
        *@return table billard retourne le billard avec les billes placées
        **/
	static table placementBilleEnLigne(table billard){
		int i;
		do{
			Ecran.afficherln("\n Nombre de billes (de 2 à 16 inclus) ?");
			billard.p.nbBille=Clavier.saisirInt();
		}while(billard.p.nbBille<2 || billard.p.nbBille>16);
		for(i=0;i<billard.p.nbBille;i++){
			billard.t[i].numero=i;
			billard.t[i].c.x=((billard.lng/(billard.p.nbBille+1))*(i+1))+25;
			billard.t[i].c.y=(billard.lrg/2)+25.0;
		}
		billard=gestionCouleur(billard);
		return billard;
	}
        
        /**
        *place les billes de façon à ce que la blanche se dirige vers les 15 autres placés en forme de triangle
        *@param table billard variable de type table
        *@return table billard retourne le billard avec les billes placées
        **/
        static table placementBilleUneVersTriangle(table billard){
		int i,j,numeroBille=1;
                double x=X+25.0-(14*R);
                double y=(billard.lrg/2)+25.0;
                billard=gestionCouleur(billard);
		//placement de la bille Blanche
                billard.t[0].c.x=200.0;
                billard.t[0].c.y=y;
                for(i=0;i<billard.p.nbBille;i++){
                      billard.t[i].numero=i;
                }
		for(i=0;i<6;i++){//nombre de colonnes formées par le triangles en x
                      y=((billard.lrg/2)+25.0)-(R*(i));
			for(j=1;j<=i;j++){//nombre de billes à placés par ligne = i+1
			//pour évité des détections de chocs à l'arrêt on sépart les billes d'un peu plus que 2*r 
                            billard.t[numeroBille].c.x=x+(i*(2.001*R));
                            billard.t[numeroBille].c.y=y;
                            y=y+(2.001*R);
                            //Ecran.afficherln("\n bille ",billard.t[numeroBille].numero," numeroBille = ",numeroBille," cx , cy  ",billard.t[numeroBille].c.x,"  ",billard.t[numeroBille].c.y);
                            numeroBille++;
                        }
		}
		return billard;
	}
      
	/**
        *donne une direction tirées au hasard (point représentant la direction sur le périmètre d'un cercle trigonométrique)
        *@param table billard variable de type table
        *@return table billard retourne le billard une fois les directions aléatoires en x et y assignées à toutes les billes
        **/
	static table directionRandom(table billard){//donne une direction aléatoire à une bille
		int i;
		double d;
		for(i=0;i<billard.t.length;i++){
			d = Math.random()*2.0*Math.PI;
			billard.t[i].d.x=Math.sin(d);
			billard.t[i].d.y=Math.cos(d);
		}
		return billard;
	}

	/**
        *assigne les couleurs à chaque bille de la tables
        *@param table billard variable de type table
        *@return table billard retourne le billard une fois toutes les couleurs assignées (les couleurs sont toujours les même pour les billes 0 et 15 respectivement blanche et noire)
        **/
	static table gestionCouleur(table billard){ //donne les couleurs à toutes les billes du billard
		int i;
		int r,v,b;
		for(i=0;i<billard.p.nbBille;i++){
			if(i==0){ //bille blanche
				r=255;
				v=255;
				b=255;
			}
			else if(i==15){//bille noire
				r=0;
				v=0;
				b=0;
			}
			else{
				r=(int)(Math.random()*255);
				v=(int)(Math.random()*255);
				b=(int)(Math.random()*255);
			}
			billard.t[i].color.r=r;
			billard.t[i].color.v=v;
			billard.t[i].color.b=b;
		}
		return billard;
	}
	
        /**
        *lance la simulation, symbolisé par l'assignation de la vitesse de départ à toutes les bille où à la bille 1 (bille blanche) si le placement est en triangle
        *@param table billard variable de type table
        *@return table billard le billard une fois les vitesses assignées
        **/
	static table lancementSimu(table billard){//lancement de la simulation
		int i;
		if(billard.p.placementTriangle==false){
			for(i=0;i<billard.p.nbBille;i++){
			billard.t[i].v=V_INIT;
			}
		}
		else billard.t[0].v=V_INIT;
		return billard;
	}
	
	/**
        *boucle infinie représentant le fait que la simulation de s'arrête jamais sauf en cas de fermeture de la fenêtre
        *@param table billard variable de type table
        *@return pas de retour
        **/
	static void simulation(table billard){//simulation en fonctionnement
		double d1=0.0;//date de départ
		double d2=T_AFFICHAGE;//date de l'instant 't+1'
		int i;
		while(true){
			evenement e1 = new evenement();//évenement futur le plus proche que l'on recalcule à chaque itérations
			for(i=0;i<billard.p.nbBille;i++){//on cherche l'évenement les plus proche
				evenement e2 = new evenement();
				e2=prochainEvenement(billard.t[i], billard);
				if(e2.time<e1.time) e1=e2; //si e1 survient avant e2
			}
			if(e1.time+d1>d2){ //si le prochain évenement survient après le temps d'affichage on affiche l'image
				deplacementBille(billard , (d2-d1));
				d1=d2;
				d2+=T_AFFICHAGE;
                                billard.temps=d1;
				affichage(billard);
			}
			else{//si e1 intervient avant l'affichage prévu
				deplacementBille(billard , e1.time);
				d1+=e1.time;
                               //Ecran.afficherln("Choc de type ",e1.type," à t = ",d1);
				switch (e1.type){//dans le cas de 0 on ne fait rien
					case 0:{}
					break;
					
					case 1:{
						billard.t[e1.b].d.x=-billard.t[e1.b].d.x;
					}break;
						
					case 2:{
						billard.t[e1.b].d.x=-billard.t[e1.b].d.x;
					}break;
					
					case 3:{
						billard.t[e1.b].d.y=-billard.t[e1.b].d.y;
					}break;
					
					case 4:{
						billard.t[e1.b].d.y=-billard.t[e1.b].d.y;
					}break;
					
					case 5:{
						calculChocEntreBille(billard.t[e1.b],billard.t[e1.bc]);
					}break;
				}
			}
		}
	}
	
	static table deplacementBille(table billard , double t){
		int i;
		for(i=0;i<billard.p.nbBille;i++){
			billard.t[i].c.x+=t*billard.t[i].v*billard.t[i].d.x;
			billard.t[i].c.y+=t*billard.t[i].v*billard.t[i].d.y;
		}
		return billard;
	}
	
	/**
        *dessine les billes à leurs emplacement actuelles et affiche le billard
        *@param table billard variable de type table
        *@return pas de retour
        **/
	static void affichage(table billard){//affiche l'état du billard et des billes à l'instant t
		int i;
		tamponBillard(billard);
		for(i=0;i<billard.p.nbBille;i++){
			EcranGraphique.setColor((int)(billard.t[i].color.r),(int)(billard.t[i].color.v),(int)(billard.t[i].color.b));
			EcranGraphique.fillCircle((int)(billard.t[i].c.x),(int)(billard.t[i].c.y),(int)(R));
                        //Ecran.afficherln("bille ",billard.t[i].numero," cx,cy ",billard.t[i].c.x,"  ",billard.t[i].c.y);
                }
		EcranGraphique.flush();
	}
	
	
	/**
	*fonction de calcul du prochain évenement le plus proche pour a bille b
	*@param bille b variable de type bille
	*@param table billard variable de type table
	*@return evenement e1 le prochaine évenement
	**/
	static evenement prochainEvenement(bille b , table billard){//retourne l'evenement dans lequel la bille b seras seras impliquée 
		double d=0.0;
                evenement e1=new evenement();
                e1.b=b.numero;

		if(billard.p.gestionChoc){//si on geres les chocs inter-billes
			int i;
			for(i=0;i<billard.p.nbBille;i++){
				if(i!=b.numero){
					d=dateChoc(b,billard.t[i]);
					if(d>1.0E-6 && d<e1.time){//marge d'erreur
						e1.time=d;
						e1.type=5;
						e1.bc=i;
					}
				}
			}
		}
              
              if(b.v*b.d.y!=0.0){
                //temps avant choc entre bille et bande droite
                d=(X+25.0-b.c.x-R)/(b.d.x*b.v);
                if(d<e1.time && d>0.0){
                  e1.time=d;
                  e1.type=1;
                }
              
                //temps avant choc entre bille et bande gauche
                d=(25.0-b.c.x+R)/(b.d.x*b.v);
                if(d<e1.time && d>0.0){
                  e1.time=d;
                  e1.type=2;
                }
              
              }
            
              if(b.v*b.d.y!=0.0){
                //temps avant choc entre bille et bande supérieur
                d=(25.0-b.c.y+R)/(b.d.y*b.v);
                if(d<e1.time && d>0.0){
                  e1.time=d;
                  e1.type=3;
                }
              
                //temps avant choc entre bille et bande inférieur
                d=(Y+25.0-b.c.y-R)/(b.d.y*b.v);
                if(d<e1.time && d>0.0){
                  e1.time=d;
                  e1.type=4;
                }
              }
               // Ecran.afficherln("\nEvenement bille ",e1.b," avec bille ",e1.bc,"  type : ",e1.type," date : ",e1.time);
		return e1;
	}
	
	/**
	*fonction de calcul de la date du choc entre les billes b1 et b2 si il y a choc entre ces deux billes
	*@param bille b1 variable de type bille
	*@param bille b2 variable de type bille
	*@return double t1 la date du choc 
	**/
	static double dateChoc(bille b1 , bille b2){//calcul de la date du choc entre b1 et b2 s'il existe
		double t1 = Double.MAX_VALUE; //t                  retourne cette valeur s'il n'y a pas de choc
		double t2 = b1.d.x*b1.v-b2.d.x*b2.v;//E
		double t3 = b1.d.y*b1.v-b2.d.y*b2.v;//F
		double t4 = t2*t2+t3*t3;//J   et    a  donc doit être !=0
		//marge d'erreur en tenant compte des erreur de précision
		//erreure d'une µ seconde tolérée
		if(t4>0.0){
			double t5 = b1.c.x - b2.c.x;//C
			double t6 = b1.c.y - b2.c.y;//D
			double t7 = t5*t5+t6*t6 - 4*R*R;//c = H - 4r²
			double t8 = 2.0*(t5*t2 + t6*t3);//b = 2I
			double t9 = t8*t8 - 4.0*t4*t7;//discriminant delta b² - 4*a*c
			double t10;
			//à l'erreur de précision d'une µ seconde près
			if(t9>=0.0 && t9<=1.0E-6){
				//cas de delta = 0.0
				//une solution : x = -b / (2*a)
				t10 = -t8 / (2.0*t4);
				//on considère uniquement les temps t > 0.0
				if(t10>1.0E-6){
					t1 = t10;
				}
			}
			else if(t9>1.0E-6){
				//cas de delta > 0.0
				//deux solutions : x1 = (-b - racine(delta)) / (2*a)    OU    x2 = (-b + racine(delta)) / (2*a)
				//on prend la plus petite valeurs pour déterminer t
				t10 = (-t8 - Math.sqrt(t9)) / (2.0*t4);
				if(t10>1.0E-6){
					t1=t10;
				}
				t10 = (-t8 + Math.sqrt(t9)) / (2.0*t4);
				if(t10>1.0E-6 && t10<t1){
					t1=t10;
				}
			}
		}
		return t1;
	}
      
	/**
	*retourne les deux billes b1 et b2 subissant un choc entre elles avec leurs directions et vitesses modifiées
	*@param bille b1 bille 1
	*@param bille b2 bille 2
	*@return pas de retour
	**/
	static void calculChocEntreBille(bille b1 , bille b2){
		int i;
		double nx = (b2.c.x-b1.c.x)/2.0/R;
		double ny = (b2.c.y-b1.c.y)/2.0/R;
		double gx = -ny;
		double gy = nx;
		double v1n = nx*b1.d.x*b1.v + ny*b1.d.y*b1.v;
		double v1g = gx*b1.d.x*b1.v + gy*b1.d.y*b1.v;
		double v2n = nx*b2.d.x*b2.v + ny*b2.d.y*b2.v;
		double v2g = gx*b2.d.x*b2.v + gy*b2.d.y*b2.v;
		b1.d.x = nx*v2n+gx*v1g;
		b1.d.y = ny*v2n+gy*v1g;
		b2.d.x = nx*v1n+gx*v2g;
		b2.d.y = ny*v1n+gy*v2g;
		b1.v = Math.sqrt(b1.d.x*b1.d.x+b1.d.y*b1.d.y);
		if ( b1.v != 0.0 ) {
			b1.d.x = b1.d.x/b1.v;
			b1.d.y = b1.d.y/b1.v; 
			}
		else {
			b1.d.x = 1.0;
			b1.d.y = 0.0;
			}
		b2.v = Math.sqrt(b2.d.x*b2.d.x+b2.d.y*b2.d.y);
		if ( b2.v != 0.0 ) {
			b2.d.x = b2.d.x/b2.v;
			b2.d.y = b2.d.y/b2.v;
			}
		else {
			b2.d.x = 1.0;
			b2.d.y = 0.0; 
			}
                //Ecran.afficherln("\n tBille[0] : cx,cy,dx,dy,v ",tBille[0].c.x," ",tBille[0].c.y," ",tBille[0].d.x," ",tBille[0].d.y," ",tBille[0].v," ");
                //Ecran.afficherln("\n tBille[0] : cx,cy,dx,dy,v ",tBille[0].c.x," ",tBille[0].c.y," ",tBille[0].d.x," ",tBille[0].d.y," ",tBille[0].v," ");
	}
	
public static void main (String [] args){
	table billard = new table();
	billard=initBillard(billard);
	demarrageAffichage(billard);
	billard=parametrageSimu(billard);
	if(billard.p.lancement==true){
		billard=lancementSimu(billard);
		while(true){
			simulation(billard);
		}
	}
        Ecran.sautDeLigne();
	EcranGraphique.exit();
}
}