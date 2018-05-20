public class JDLV_V3{
static final int N=256;
static final int T=(int)((1000/N)-1.25);//900 pour hauteur de mon ecran (1050) - 150 de marge d'affichage (barre des tâches windows, bordure de la fenêtre)
static final int X=1+N*(T+1);
static final int Y=X+50;
static final int Z=Y+50;
/*
	3 lois :
	-2 cellules voisines (diagonales comprises) : rien
	-3 cellules voisines (diagonales comprises) : la cellule passe à vrai
	-tout autres nombres : la cellules passe à faux
*/

//////////////////////////////////////////////
	
//fonction d'initialisation de la fenêtre de dessin
static void initAffichage(){
	int x,y,z;
	if(T<1){
		x=N;
		y=x+50;
		z=y+50;
	}
	else{
		x=X;
		y=Y;
		z=Z;
	}
	EcranGraphique.setClearColor(0,0,0);
	EcranGraphique.setColor(0,0,0);
	EcranGraphique.clear();
	EcranGraphique.init(0,0,y,z,x,x,"Jeu De La Vie");
}

//////////////////////////////////////////////

static void dessinCellule(int l, int c){
	int W,x,y;
	if(T<1){
		W=0;
		x=l;
		y=c;
	}
	else{
		W=T;
		x=1+l*(W+2);
		y=1+c*(W+2);
	}
	EcranGraphique.setColor(255,255,255);
	EcranGraphique.drawRect(x,y,W,W);
}

/////////////////////////////////////////////

static void affichage(boolean [][] m){
	int l,c;
	for(l=0;l<m.length;l++){
		for(c=0;c<m[0].length;c++){
			if(m[l][c]){
				dessinCellule(l,c);
			}
			else{
			}
		}
	}
	EcranGraphique.flush();
	EcranGraphique.clear();
}

//////////////////////////////////////////////

static boolean[][] random(){
	boolean [][] m = new boolean [N][N];
	int n,l,c;
	do{
		Ecran.afficherln("\nCombien de cellule (entre 0 et ",N*N,") ? ");
		n=Clavier.saisirInt();
	}while((n<0) || (n>(N*N)));
	for(int i=0;i<n;i++){
		l=(int)(Math.random()*N);
		c=(int)(Math.random()*N);
		if(m[l][c])i--;
		else m[l][c]=true;
	}
	affichage(m);
	return m;
}

//////////////////////////////////////////////

static boolean[][] galaxie(){
	boolean [][] m = new boolean [N][N];
	if(N>40){
		m[30][30] = true;
		m[30][31] = true;
		m[30][32] = true;
		m[30][33] = true;
		m[30][34] = true;
		m[30][35] = true;
		m[31][30] = true;
		m[31][31] = true;
		m[31][32] = true;
		m[31][33] = true;
		m[31][34] = true;
		m[31][35] = true;
		m[30][27] = true;
		m[31][27] = true;
		m[32][27] = true;
		m[33][27] = true;
		m[34][27] = true;
		m[35][27] = true;
		m[30][28] = true;
		m[31][28] = true;
		m[32][28] = true;
		m[33][28] = true;
		m[34][28] = true;
		m[35][28] = true;
		m[37][27] = true;
		m[37][28] = true;
		m[37][29] = true;
		m[37][30] = true;
		m[37][31] = true;
		m[37][32] = true;
		m[38][27] = true;
		m[38][28] = true;
		m[38][29] = true;
		m[38][30] = true;
		m[38][31] = true;
		m[38][32] = true;
		m[33][34] = true;
		m[34][34] = true;
		m[35][34] = true;
		m[36][34] = true;
		m[37][34] = true;
		m[38][34] = true;
		m[33][35] = true;
		m[34][35] = true;
		m[35][35] = true;
		m[36][35] = true;
		m[37][35] = true;
		m[38][35] = true;
		affichage(m);
	}
	else Ecran.afficherln("La constante N (définie dans le code source à ",N," n'a pas une assez grande valeur (40 minimum) pour afficher une galaxie.");
	return m;
}

//////////////////////////////////////////////

static int valVoisin(boolean [][] m, int l, int c){
	if((l<0) || (l>=m.length) || (c<0) || (c>=m[0].length)) return 0;
	else {
		if(m[l][c]) return 1;
		else return 0;
	}
}

//////////////////////////////////////////////

static int nbCelluleVraiVoisines(boolean [][] m,int l,int c){
	int n=0;
	n += valVoisin(m,l+1,c);
	n += valVoisin(m,l+1,c+1);
	n += valVoisin(m,l,c+1); 
	n += valVoisin(m,l-1,c+1); 
	n += valVoisin(m,l-1,c); 
	n += valVoisin(m,l-1,c-1); 
	n += valVoisin(m,l,c-1); 
	n += valVoisin(m,l+1,c-1); 
	return n;
}

//////////////////////////////////////////////

static boolean[][] evolution(boolean [][] m){
	boolean [][] evo = new boolean [m.length][m[0].length];
	int n,l,c;
	for(l=0;l<evo.length;l++){
		for(c=0;c<evo[0].length;c++){
			switch(nbCelluleVraiVoisines(m,l,c)){
				case 2:{
					evo[l][c]=m[l][c];
				}break;
				
				case 3:{
					evo[l][c]=true;
				}break;
				
				default:{
					evo[l][c]=false;
				}
			}
		}
	}
	return evo;
}

//////////////////////////////////////////////

static void jeu(boolean [][] m){
	int i=0,j,t;
	boolean run=true;
	boolean infinite=false;
	do{
		Ecran.afficher("\nCombien d'itération (entrer 0 pour infinis) ? ");
		j=Clavier.saisirInt();
	}while(j<0);
	if(j==0)infinite=true;
	do{
		Ecran.afficher("\nTemps entre chaque itération (en ms et >=0) ? ");
		t=Clavier.saisirInt();
	}while(t<0);
	Ecran.afficherln("\n Vous pouvez stoper la simulation en appuyant sur 's' à tout moment");
	EcranGraphique.wait(1500);
	do{
		EcranGraphique.wait(t);
		m=evolution(m);
		affichage(m);
		if( ((i == j-1) && !infinite) || (EcranGraphique.getKey()=='s' || EcranGraphique.getKey()=='S') ){
			run=false;
			infinite=false;
		}
		else i++;
	}while(run || infinite);
	Ecran.afficherln("\nArrêt à ",i+1," itération(s)");
}

//////////////////////////////////////////////

static void jeuRandSpawn(boolean [][] m){
	int i=0,j,n,x,t;
	boolean run=true;
	boolean infinite=false;
	do{
		Ecran.afficher("\nCombien d'itération (entrer 0 pour infinis) ? ");
		j=Clavier.saisirInt();
	}while(j<0);
	if(j==0)infinite=true;
	do{
		Ecran.afficher("\nTemps entre chaque itération (en ms et >=0) ? ");
		t=Clavier.saisirInt();
	}while(t<0);
	do{
		Ecran.afficher("\nCombien d'itérations avant le spawn aléatoire ? ");
		n=Clavier.saisirInt();
	}while(n<1);
	do{
		Ecran.afficher("\nCombien de case à spawner (entre 1 et ",N*N,") ? ");
		x=Clavier.saisirInt();
	}while(x<1);
	Ecran.afficherln("\n Vous pouvez stoper la simulation en appuyant sur 's' à tout moment");
	EcranGraphique.wait(1500);
	do{
		EcranGraphique.wait(t);
		if((i!=0) && (i%n==0)){
			spawnRandom(m,x);
		}
		m=evolution(m);
		affichage(m);
		if( ((i == j-1) && !infinite) || (EcranGraphique.getKey()=='s' || EcranGraphique.getKey()=='S') ){
			run=false;
			infinite=false;
		}
		else i++;
	}while(run || infinite);
	Ecran.afficherln("\nArrêt à ",i+1," itération(s)");
}

//////////////////////////////////////////////

static void spawnRandom(boolean [][] m, int n){
	int l,c;
	for(int i=0;i<n;i++){
		l=(int)(Math.random()*N);
		c=(int)(Math.random()*N);
		if(m[l][c])i--;
		else m[l][c]=true;
	}
}

//////////////////////////////////////////////

static void jeuSmiley(boolean [][] m){
	int i=0,j,t;
	boolean run=true;
	boolean infinite=false;
	Ecran.afficherln("\nLe smiley apparaitras à la 557ème itération.");
	do{
		Ecran.afficher("\nCombien d'itération (entrer 0 pour infinis) ? ");
		j=Clavier.saisirInt();
	}while(j<0);
	if(j==0)infinite=true;
	do{
		Ecran.afficher("\nTemps entre chaque itération (en ms et >=0) ? ");
		t=Clavier.saisirInt();
	}while(t<0);
	Ecran.afficherln("\n Vous pouvez stoper la simulation en appuyant sur 's' à tout moment");
	EcranGraphique.wait(1500);
	do{
		if(i!=0 && i%8==0){
			m=smiley(m);
		}
		EcranGraphique.wait(t);
		m=evolution(m);
		affichage(m);
		if( ((i == j-1) && !infinite) || (EcranGraphique.getKey()=='s' || EcranGraphique.getKey()=='S') ){
			run=false;
			infinite=false;
		}
		else i++;
	}while(run || infinite);
	Ecran.afficherln("\nArrêt à ",i+1," itération(s)");
}

//////////////////////////////////////////////

static int menu(){
	Ecran.sautDeLigne();
	Ecran.afficherln("0. lancer le jeu de la vie");
	Ecran.afficherln("1. Aléatoire");
	Ecran.afficherln("2. Galaxie");
	Ecran.afficherln("3. Vaisseau");
	Ecran.afficherln("4. Clown");
	Ecran.afficherln("5. Smiley");
	Ecran.afficherln("6. Manuelle (Non fonctionnelle si N>=512)");
	Ecran.afficherln("7. Quitter");
	Ecran.afficher("Votre choix :  ");
	int choix = Clavier.saisirInt();
	Ecran.sautDeLigne();
	return choix;
}

//////////////////////////////////////////////

static boolean[][] smiley(boolean [][] n){
	boolean [][] m = new boolean [N][N];
	int l,c;
	if(N==64){
		m[0][28] = true;
		m[0][29] = true;
		m[1][29] = true;
		m[1][30] = true;
		m[1][31] = true;
		m[1][32] = true;
		m[2][30] = true;
		m[2][31] = true;
		m[3][29] = true;
		m[3][32] = true;
		m[0][33] = true;
		m[0][34] = true;
	///////////////////////////////////
		m[63][28] = true;
		m[63][29] = true;
		m[62][29] = true;
		m[62][30] = true;
		m[62][31] = true;
		m[62][32] = true;
		m[61][30] = true;
		m[61][31] = true;
		m[60][29] = true;
		m[60][32] = true;
		m[63][33] = true;
		m[63][34] = true;
		for(l=0;l<N;l++){
			for(c=0;c<N;c++){
				if(m[l][c] || n[l][c]) m[l][c] = true;
				else m[l][c] = false;
			}
		}
	}
	else{
		Ecran.afficherln("\nImpossible car la constante N n'est pas définies à 64");
		System.exit(0);
	}
	return m;
}

//////////////////////////////////////////////

static boolean[][] vaisseau(){
	boolean [][] m = new boolean [N][N];
	if(N>34){
		m[5][30] = true;
		m[8][30] = true;
		m[9][31] = true;
		m[9][32] = true;
		m[9][33] = true;
		m[8][33] = true;
		m[7][33] = true;
		m[6][33] = true;
		m[5][32] = true;
		affichage(m);
	}
	else Ecran.afficherln("La constante N (définie dans le code source à ",N," n'a pas une assez grande valeur (35 minimum) pour afficher le vaisseau.");
	return m;
}

//////////////////////////////////////////////

static boolean[][] clown(){
	boolean [][] m = new boolean [N][N];
		m[32][34] = true;
		m[33][34] = true;
		m[31][34] = true;
		m[31][35] = true;
		m[33][35] = true;
		m[31][36] = true;
		m[33][36] = true;
		affichage(m);
		Ecran.afficherln("\nLe 'clown' apparaitras, si la constante N est assez grande, à la 110ème itération.");
	return m;
}

//////////////////////////////////////////////

static boolean[][] reInit(boolean [][] m){
	int i,j;
	for(i=0;i<m.length;i++){
		for(j=0;j<m[0].length;j++){
			m[i][j]=false;
		}
	}
	return m;
}

//////////////////////////////////////////////

static void surbrillance(boolean [][] m, int l,int c){
	int i,j;
	for(i=0;i<m.length;i++){
		for(j=0;j<m[0].length;j++){
			if(m[i][j]){
				dessinCellule(i,j);
			}
		}
	}
	if(m[l][c]){
		dessinCellule(l,c,0,255,0);
	}
	else{
		dessinCellule(l,c,255,0,0);
	}
	EcranGraphique.flush();
	EcranGraphique.clear();
	
}

//////////////////////////////////////////////

static void dessinCellule(int l, int c, int r, int v, int b){
	int W,x,y;
	if(T<1){
		W=0;
		x=l;
		y=c;
	}
	else{
		W=T;
		x=1+l*(W+2);
		y=1+c*(W+2);
	}
	EcranGraphique.setColor(r,v,b);
	EcranGraphique.drawRect(x,y,W,W);
}

//////////////////////////////////////////////

static boolean[][] manuelle(){
	boolean [][] m = new boolean [N][N];
	int l,c;
	boolean run=true;
	Ecran.afficherln("\nMaintenez v pour mettre à vrai des cellules à la chaîne.");
	Ecran.afficherln("\nMaintenez f pour mettre à faux des cellules à la chaîne.");
	Ecran.afficherln("\nEffectuez un clic gauche pour inverser l'état d'une cellule.");
	Ecran.afficherln("\nPour  confirmer la saisie, effectuez un clic droit.");
	while(run){
		if(EcranGraphique.getMouseButton()==3) run = false;
		else{
			l=(int)((EcranGraphique.getMouseX()-1)/(T+2));
			c=(int)((EcranGraphique.getMouseY()-1)/(T+2));
			surbrillance(m,l,c);
			if(EcranGraphique.getMouseState()==2){
				m[l][c] = !m[l][c];
			}
			if(EcranGraphique.getKey()=='v'){
				m[l][c] = true;
			}
			if(EcranGraphique.getKey()=='f'){
				m[l][c] = false;				 
			}							
		}
	}
	affichage(m);
	return m;
}

//////////////////////////////////////////////

 public static void main(String [] args) {
	boolean [][] m = new boolean [N][N];
	initAffichage();
	while(true){
		switch(menu()){
			case 0:{
				int c;
				do{
					Ecran.afficherln("\n Voulez-vous un spawn aléatoire de cases durant le jeu (1 pour oui, 0 pour non) ? ");
					c=Clavier.saisirInt();
				}while(c!=1 && c!=0);
				if(c==1){
					jeuRandSpawn(m);
				}
				else{
					jeu(m);
				}
			}break;
			
			case 1:{
				m=random();
				int c;
				boolean randomSpawn=false;
				do{
					Ecran.afficherln("\n Voulez-vous un spawn aléatoire de cellules durant le jeu (1 pour oui, 0 pour non) ? ");
					c=Clavier.saisirInt();
				}while(c!=1 && c!=0);
				if(c==1){
					jeuRandSpawn(m);
				}
				else{
					jeu(m);
				}
			}break;
			
			case 2:{
				m=galaxie();
				jeu(m);
			}break;
			
			case 3:{
				m=vaisseau();
				jeu(m);
			}break;
			
			case 4:{
				m=clown();
				jeu(m);
			}break;
			
			case 5:{
				m=reInit(m);
				m=smiley(m);
				affichage(m);
				jeuSmiley(m);
			}break;
			
			case 6:{
				m=manuelle();
				int c;
				boolean randomSpawn=false;
				do{
					Ecran.afficherln("\n Voulez-vous un spawn aléatoire de cellules durant le jeu (1 pour oui, 0 pour non) ? ");
					c=Clavier.saisirInt();
				}while(c!=1 && c!=0);
				if(c==1){
					jeuRandSpawn(m);
				}
				else{
					jeu(m);
				}
			}break;
			
			case 7:{
				System.exit(0);
			}break;
			
			default:{
				Ecran.afficherln("\nErreur de saisie, arrêt du programme...");
				System.exit(1);
			}
		}
	}
}
}
