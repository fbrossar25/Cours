/* jeu de Nim (allumettes) */
#define N 15 
mtype = {joue, fin }
byte allumettes_retire;
byte allumettes_restant = N;

proctype joueur (byte proc; chan outc, inc)
{
 
byte var;
byte allumettes;
do
::inc?joue(var) -> 
	if
	:: allumettes = 1;
	:: allumettes = 2;
	:: allumettes = 3;
	fi;
	if
	:: (var - allumettes <= 0) -> 
	  atomic {allumettes_retire = allumettes_retire + var;
		  allumettes_restant=0;
		  outc!fin(proc)};
	:: else -> 
	  atomic {outc!joue(var-allumettes);
		  allumettes_retire = allumettes_retire + allumettes;
		  allumettes_restant = allumettes_restant - allumettes};
	fi;
::inc?fin(var) -> printf("(%d) : le gagnant est %d\n",proc,var);
	if
	:: var != proc -> outc!fin(var);
	:: else -> skip;
	fi;
	break;
od;
}

proctype verif()
{
	assert(allumettes_retire + allumettes_restant == N)
}

init
{	
	chan from1to2 = [1] of {mtype,byte};
	chan from2to3 = [1] of {mtype,byte};
	chan from3to1 = [1] of {mtype,byte};
    	atomic
	{	
		run joueur(1,from1to2,from3to1);
		run joueur(2,from2to3,from1to2);
		run joueur(3,from3to1,from2to3);
		from3to1!joue(N);
	}
}
