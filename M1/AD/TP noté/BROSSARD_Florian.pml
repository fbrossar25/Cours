/*
Erreur de syntaxe avec le label_rand dans appli
*/

#define null 0

mtype = {ack, next, accept, data }
/*
ack : aquittement
data : donnée
next : donnée produite par la couche application
accept : donnée consommée par la couche application
*/

proctype protocole (chan inc, out, chin, chout)
{
	byte o, i, num, ns, nr;
	mtype type;
	/*
	o : donnée émise (output)
	i : donnée reçue (input)
	ns : numéro de donnée à émettre (modulo 2)
	nr : numéro de donnée à recevoir (modulo 2)
	num  :numéro de la donnée ou de l'acquittement reçue
	les message du protocole ont les champs type, donnee, numero
	null représent qu'il n'y a pas de donnée dans le messge d'acquittement
	*/
	ns = 0;
	nr = 0;
	do
	::	if
		:: (chin?ack(i,num)) ->
								if
								::(num == ns)-> ns = (ns + 1) % 2;
												if
												::inc?[next(o)] ->	inc?next(o); //si donnée produite par appli
																	chout!data(o,ns); //on l'envoie
												fi
								::(num != ns)->	chout!data(i,num);
								fi
		:: (chin?data(i,num)) ->
								if
								::(num == nr)->	out!accept(i); //on consomme i
												chout!data(i,num); //on renvoie num
												nr = (nr + 1) % 2;
								::(num != nr)-> chout!ack(i,num); //on ignore num
								fi
		fi
	od
}

proctype appli(chan ToProc, FromProc; int n1, n2)
{
	/*
	production de données représentées par des entiers compris
	entre n1 et n2
	*/
	
	rand_label:
	//entier tiré aléatoirement enter n1 et n2
	int rand = n1;
	do
	:: (rand >= n2) -> break;
	:: (rand < n2) -> rand++;
	:: (rand < n2) -> break;
	od
	
	/*
	consommation des données -> accept
	production des données -> next
	*/
	int i; //donnée reçu par protocole
	int o = rand; //donnée à envoyer à protocole
	do
	::	if
		::(FromProc?next(i)) -> 
									ToProc!next(o) //produit la donnée et l'envoie à protocole
									goto rand_label;
		::(FromProc?accept(i)) -> 	
									skip; //consomme la donnée
		fi
	od
}

init
{
	chan AtoB = [10] of {byte, byte, byte};
	chan BtoA = [10] of {byte, byte, byte};
	chan Ain = [10] of {byte, byte};
	chan Bin = [10] of {byte, byte};
	chan Aout = [10] of {byte, byte};
	chan Bout = [10] of {byte, byte};

	atomic
	{
		/*
		exemple de lancement
		*/
		
		run protocole(Ain, Aout, BtoA, AtoB);
		run protocole(Bin, Bout, AtoB, BtoA);
		run appli(Ain, Aout, 1, 3); //lancement appli A avec prodution des données 1 a 3
		run appli(Bin, Bout, 4, 5); //lancement appli B avec prodution des données 4 a 5
	};
}