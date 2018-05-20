#!/bin/bash
if [ ! -e plaintext ]
then
	echo 'fichier plaintext inexistant'
	exit
fi

#on retire les accents
cat plaintext | sed 'y/áàâäçéèêëîïìôöóùúüñÂÀÄÇÉÈÊËÎÏÔÖÙÜÑ/aaaaceeeeiiiooouuunAAACEEEEIIOOUUN/' | tee plaintext
echo -e "\nsauvegarde du fichier 'plaintext' dans le fichier 'plaintextSave'\n"
cat plaintext > plaintextSave

KEY=0
until [ $KEY -eq 26 ]
do
	echo -e "cle = $KEY"
	./caesar_encrypt $KEY < plaintext > ciphertext
	./caesar_decrypt $KEY < ciphertext > plaintext
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

	REP=$(./caesar_break < ciphertext | tail -n1 | tr -d -c [:digit:])

	if [ $REP -eq $KEY ]
	then
		echo -e "cle trouve : $REP --> texte decrypte avec succes\n"
	else
		echo -e "cle trouve : $REP --> echec du decryptage (texte clair trop court ou non analysable ?)"
		exit
	fi
	KEY=$(($KEY + 1))
done

echo -e '\nSucces des tests sur toutes les clefs possibles'