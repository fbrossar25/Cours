#!/bin/bash
#Script shell développé par Florian BROSSARD
#Génère un Makefile permettant de compiler un programme name à partir des fichiers du dossier directory (ou courant si non renseigné)
#prend en compte les dépendances locales
#ATTENTION !!!! TOUS LES FICHIERS NÉCESSAIRE AU PROGRAMMES DOIVENT ÊTRE DANS LE MÊME DOSSIER

#Affiche l'aide
usage () {
	echo "Usage: generateMakefile.sh name [directory]";
	echo "Where:";
	echo "	name is the name of the program";
	echo "	directory is the source directory";
}

#Renvois tout les fichier .h inclus dans les fichiers donnés en paramètres
getFilesDeps(){
	echo $(grep -h include $* | grep -v '<' | sed -e 's/#include //g' | sed -e 's/\"//g' | tr '\n' ' ');
}

#Renvois la liste des dépendances sans doublons
removeDoubles(){
	echo "$(echo $* | tr ' ' '\n' | sort | uniq | tr '\n' ' ')";
}

#Renvois les dépendances du projet
getDeps(){
	A=$(echo $*);
	DEPS=$(getFilesDeps $A);
	B=$(echo $A $DEPS);
	UNIQ_DEPS=$(removeDoubles $B);
	if [ "$(echo $UNIQ_DEPS)" != "$(echo $A)" ]
	then
		getDeps $UNIQ_DEPS;
	else
		echo $UNIQ_DEPS;
	fi
}

if [ $# -gt 0 ]
then
	PROGRAM=$1
	#si on donne un second argument
	if [ $# -gt 1 ]
	then
		#si c'est un répertoire existant
		if [ -d $2 ]
		then
			ROOTDIR=$2
		else
			echo "Error : Could not open directory '$2'"
			usage
			exit
		fi
	else
		ROOTDIR=$(pwd)
	fi
	cd "$ROOTDIR"
else
	usage
	exit
fi

#Vérification de la présence de fichier .c
if [ "$(ls *.c)" == "" ]
then
	echo "Error : C file not found"
	usage
	exit
fi

#Récuperation des noms des fichiers objets
OBJ=$(ls *.c | sed -e 's/\.c/\.o/')
OBJ=$(echo $OBJ | tr '\n' ' ')

#Option de compilation par défaut
if [ ! -e CFLAGS ]
then
	CFLAGS="-Wall -std=c99 -o2 -g"
fi

echo -e "# Generated by generateMakefile.sh\n" > Makefile
echo "CC=gcc" >> Makefile
echo "TARGET=$PROGRAM" >> Makefile
echo "CFLAGS=$CFLAGS" >> Makefile
echo "LDFLAGS=$LDFLAGS" >> Makefile
#Règle all
echo -e "\nall: \${TARGET}\n" >> Makefile
echo -e "\nremake: mrproper all\n" >> Makefile
#Règle de construction du programme final
echo "\${TARGET}: $OBJ" >> Makefile
echo -e "\t\${CC} \${CFLAGS} \${LDFLAGS} -o \$@ \$^\n" >> Makefile

#Génération des règles de compilations des fichiers c en fichiers objets
for i in $OBJ
do
	CFILE=$(echo $i | sed -e 's/\.o/\.c/')
	echo "$i: $(getDeps $CFILE)" >> Makefile
	echo -e "\t\${CC} \${CFLAGS} \${LDFLAGS} -o \$@ -c $CFILE\n" >> Makefile
done

#Règle clean
echo "clean:" >> Makefile
echo -e "\t rm -f *.o\n" >> Makefile

#Règle mrproper
echo "mrproper: clean" >> Makefile
echo -e "\t rm -f \${TARGET}" >> Makefile
echo -e "\t rm -f core" >> Makefile

#Affichage du fichier généré dans le terminal
cat Makefile