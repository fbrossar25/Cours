#!/bin/bash
MAX=100
ESSAI=0
NESSAI=6
REP=0
N=$((($RANDOM % $MAX)+1))
echo "L'ordinateur a choisi une valeur entre 1 et $MAX"
until [ $REP -eq $N -o $ESSAI -gt $NESSAI ]
do
	echo "Quelle est votre proposition ? "
	read REP
	if test $REP -gt $N
	then 	echo "La valeur est plus petite."
	else 	if test $REP -lt $N
		then echo "La valeur est plus grande."
		fi
	fi
	ESSAI=$(($ESSAI + 1))
done
if test $REP -eq $N
then echo "Bravo! Vous avez trouvé la valeur en $ESSAI essai(s)."
else echo "Perdu! La réponse était $N."
fi
