#!/bin/bash
if [ ! -e plaintext ]
then
	echo 'fichier plaintext inexistant'
	exit
fi

if [ ! -e keyList ]
then
	echo 'fichier keyList inexistant'
	exit
fi

if [ ! -e vigenere_encrypt -o  ! -e vigenere_decrypt -o ! -e vigenere_break ]
then 
	if [ -e Makefile ]
	then
		make
	else
		echo 'pas de Makefile ou executable manquant'
		exit
	fi
fi

#on retire les accents
#cat plaintext | sed 'y/áàâäçéèêëîïìôöóùúüñÂÀÄÇÉÈÊËÎÏÔÖÙÜÑ/aaaaceeeeiiiooouuunAAACEEEEIIOOUUN/' | tee plaintext > /dev/null
echo -e "\nsauvegarde du fichier 'plaintext' dans le fichier 'plaintextSave'\n"
cat plaintext > plaintextSave

COUNT=1
NUMBEROFKEY=$(wc -w keyList | tr -d -c [:digit:])
until [ $COUNT -gt $NUMBEROFKEY ]
do
	KEY=$(cat keyList | head -n$COUNT | tail -n1 | tr -d -c [:alpha:])
	echo -e "cle = $KEY"
	./vigenere_encrypt $KEY < plaintext > ciphertext
	./vigenere_decrypt $KEY < ciphertext > plaintext
	diff plaintext plaintextSave > /dev/null

	if [ $? -eq 0 ]
	then
		echo -e 'Texte dechiffre equivalent au texte choisis : reussite'
	elif [ $? -eq 1 ]
	then
		echo -e 'Texte dechiffre different du texte choisis : echec'
		exit
	else
		echo "erreur de la commande 'diff'\n"
		exit
	fi

	REP=$(./vigenere_break < ciphertext | tr -d -c [:alpha:])

	if [ $REP = $KEY ]
	then
		echo -e "cle trouve : $REP --> texte decrypte avec succes\n"
	else
		echo -e "cle trouve : $REP --> echec du decryptage (texte clair trop court ou non analysable ?)"
		exit
	fi
	COUNT=$(($COUNT + 1))
done

echo -e '\nSucces des tests sur toutes les clefs possibles'