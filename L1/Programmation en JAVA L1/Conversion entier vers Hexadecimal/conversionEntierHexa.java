public class conversionEntierHexa{
	
static int saisieEntier(){
	int n;
	Ecran.afficher("\n Veuillez Saisir un entier positif : ");
	do{
		n=Clavier.saisirInt();
	}while (n<0);
	Ecran.sautDeLigne();
	return n;
}

static String sousChaine(String s, int iInitial, int iFinal){
	String res="";
	int i;
	if(iInitial <= iFinal){
		for(i=iInitial;i<iFinal;i++){
			res+=s.charAt(i);
		}
	}
	return res;
}

static String concatener(String s1, String s2){
	return s1+s2;
}

static String inversionChaine(String st){
	String si="",s1,s2;
	int l1,lst;
	lst=st.length();
	if(lst==0 || lst==1) si=st;
	else{
		l1=lst/2;
		s1=inversionChaine(sousChaine(st,0,l1));
		s2=inversionChaine(sousChaine(st,l1,lst));
		si=concatener(s2,s1);
	}
	return si;
}

static void conversion(int n){
	String hex = "",bin = "";
	if(n>=0){
		hex = conversionHex(n);
		bin = conversionBin(hex);
	}
	if (!hex.equals(""))affichage(hex,bin);
	else Ecran.afficherln("\nErreur, n doit être >= 0");
}

static String conversionBin(String hex){
	String res = "";
	int i;
	for(i=0;i<hex.length();i++){
		res+=correspondanceBin(hex.charAt(i))+" ";
	}
	return res;
}

static String correspondanceBin(char c){
	String res="";
	if((c>='0' || c<='9') &&(c>='A' || c<='F')){
		switch(c){
			case '0':{res="0000";}break;
			case '1':{res="0001";}break;
			case '2':{res= "0010";}break;
			case '3':{res= "0011";}break;
			case '4':{res= "0100";}break;
			case '5':{res= "0101";}break;
			case '6':{res= "0110";}break;
			case '7':{res= "0111";}break;
			case '8':{res= "1000";}break;
			case '9':{res= "1001";}break;
			case 'A':{res= "1010";}break;
			case 'B':{res= "1011";}break;
			case 'C':{res= "1100";}break;
			case 'D':{res= "1101";}break;
			case 'E':{res= "1110";}break;
			case 'F':{res= "1111";}break;
			
		}
	}
	else{
		Ecran.afficherln("\nErreur");
		System.exit(0);
	}
	return res;
}

static String conversionHex(int n){
	String res="";
	int reste=0;
	do{
		reste=n%16;
		n=n/16;
		res+=Character.toString(correspondance(reste));
	}while(n!=0);
	return inversionChaine(res);
}

static char correspondance(int n){
	char c=' ';
	if(n>=0 && n<=15){
		switch(n){
			case 0:{c='0';}break;
			case 1:{c='1';}break;
			case 2:{c= '2';}break;
			case 3:{c= '3';}break;
			case 4:{c= '4';}break;
			case 5:{c= '5';}break;
			case 6:{c= '6';}break;
			case 7:{c= '7';}break;
			case 8:{c= '8';}break;
			case 9:{c= '9';}break;
			case 10:{c= 'A';}break;
			case 11:{c= 'B';}break;
			case 12:{c= 'C';}break;
			case 13:{c= 'D';}break;
			case 14:{c= 'E';}break;
			case 15:{c= 'F';}break;
			
		}
	}
	else{
		Ecran.afficherln("\nErreur");
		System.exit(0);
	}
	return c;
}

static void affichage(String hex, String bin){
	int i;
	Ecran.afficher("\n0x ");
	for(i=0;i<hex.length();i++){
		if((i+1)%4==0) Ecran.afficher(hex.charAt(i)+" ");
		else Ecran.afficher(hex.charAt(i));
	}
	Ecran.afficher("\n0b ");
	for(i=0;i<bin.length();i++){
		if(i+1%4==0) Ecran.afficher(bin.charAt(i)+" ");
		else Ecran.afficher(bin.charAt(i));
	}
}

 public static void main(String [] args) {
		conversion(saisieEntier());
	 Ecran.sautDeLigne();
	}	 
}