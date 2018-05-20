#!/bin/bash
#on ne prend en compte que le premier argument
if test -e $1 #si argument
then	
	if  test -d $1 #si c'est un dossier
	then
		if test $# != 0 #si le nom de l argument n'est pas vide
		then
			cd $1      #on se déplace
		fi
	#sinon on reste dans le repertoire courant
	for i in *     #on affiche tout les fichiers et dossiers
	do
		if test -d $i
		then
			echo "$i/" #on ajoute un / a la fin du nom des dossier pour les signalés
		else
			echo $i
		fi
	done
	elif test -f $1 #sinon si c'est un fichier
	then
		echo $(basename $1) #on affiche juste le nom du fichier sans le chemin absolu ou relatif
	fi
else
	echo "Erreur : pas de fichier ou dossier $1 existant" #message d'erreur si pas de fichier
fi
