#!/bin/bash
if [ $# -eq 1 ] #si un seul argument
then	if [ -d $1 -a $# != 0 ] #si repertoire
		then	cd $1 #déplacement
				for i in *
				do
					if [ -d $i ]
					then 	echo "$i/"
						rmdir $i
						if [ $? -ne 0 ] #si erreur
						then $(./rec_rmdir.sh $i)
						fi
					fi
				done
		fi
else echo "Il faut un et un seul argument!"
fi
