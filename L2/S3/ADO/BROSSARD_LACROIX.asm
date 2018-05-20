#Programme créer par BROSSARD Florian et LACROIX Antoine, L2 Info TD2 groupe B
#Ce programme permet de saisir jusqu'as 4 caractere hexadecimaux (lettre majuscule et chiffre uniquement)
#Si l'on saisie moins de 4 caractère, les caractere suivant seront remplace par des caractere '0'
#sinon on affiche la chaine "0x" puis la chaine forme par la nombre
#exemple : 1234 affiche 0x1234 et FF affiche 0xFF00
#le but etait de faire un bit extender (donc d'afficher 0x00FF et pas 0xFF00)
#mais nous n'avons pas trouve de solution, les nombre s'affichait dans le desordre
main:
	addi $a0,$zero,0x2000	#Adresse de début de la saisie
	addi $a1,$zero,0x200C	#On souhaite saisir 4 caractères uniquement donc la 4ème caractere seras en 0x200C
	addi $a2,$zero,0xA
	jal saisieHexa			#$v0 devient l'adresse du dernier caractere enregistre en memoire
	
	addi $a1,$zero,0x200C	#On modifie $a1 dans saisieHexa donc on le reaffecte avec 0x200C
	beq $v0,$a1,jump		#Si le dernier caractere saisie est enregistre en 0x200C, pas besoin de completer avec des '0'
	
	addi $a0,$zero,0x2000
	addi $a1,$zero,0x200C
	jal completeWithZeros	#Fonctionne qui 'ajoute' des '0' à la fin du nombre saisie si necessaire
jump:
	addi $a0,$zero,0x2000	#adresse de debut de lecture
	addi $a1,$zero,0x200C	#adresse de fin de lecture (doit etre superieur a $a0)
	jal affichageHexMemoire #Fonction qui affiche les caractere en memoire entre deux adresse en arguments

	beq $zero,$zero,Fin 	#Fin du programme
################################################################################################################
saisieHexa:
	lw $t0,0x7F00($zero)
	beq $t0,$zero,saisieHexa
	lw $t0,0x7F04($zero)
	beq $t0,$a2,finSaisieHexa	#$t0 == caractere enter
	addi $v1,$zero,'0'
	sub $v1,$t0,$v1
	bltz $v1,saisieHexa			#$t0 < '0'
	addi $v1,$zero,'F'
	sub $v1,$t0,$v1
	bgtz $v1,saisieHexa			#$t0 > 'F' ?

	addi $v0,$zero,'9'
	addi $v1,$zero,'A'
boucleVerif:					#Boucle verifiant $t0 > '9' && $t0 < 'A'
	beq $v0,$v1,finBoucleVerif
	addi $v0,$v0,1
	beq $t0,$v0,saisieHexa
	beq $zero,$zero,boucleVerif
finBoucleVerif:
	sw $t0,0($a0)
	addi $a0,$a0,4
	sub $v0,$a1,$a0
	bgez $v0,saisieHexa			#On continue la saisie tant que la touche entrer n'est pas appuyer et que l'on a pas saisie 4 caractere
finSaisieHexa:
	addi $v0,$a0,-4
	jr $ra
################################################################################################################
completeWithZeros:
	sub $v1,$a1,$a0
	bltz $v1,finCompleteWithZeros	#tant que $a1 - $a0 < 0
	lw $v0,0($a1)
	bne $v0,$zero,finCompleteWithZeros 	#si on lit un caractere alors on a finis
	addi $v0,$zero,'0'
	sw $v0,0($a1)
	addi $a1,$a1,-4						#on passe a l'adresse suivante
	beq $zero,$zero,completeWithZeros 	#tant qu'on a pas 'scanne' toute la plage memoire
finCompleteWithZeros:
	jr $ra
################################################################################################################
affichageHexMemoire:
	addi $v0,$zero,'0'				#on affiche d'abord la chaine "0x" puis les caracteres en memoire
	sw $v0,0x7F0C($zero)
	addi $v0,$zero,'x'
	sw $v0,0x7F0C($zero)
boucleAffichageHexMemoire:
	sub $v1,$a1,$a0
	bltz $v1,finAffichageHexMemoire
	lw $v0,0($a0)					#on charge le caractere
	sw $v0,0x7F0C($zero)			#on affiche le caractere
	addi $a0,$a0,4					#on passe a l'adresse suivante
	beq $zero,$zero,boucleAffichageHexMemoire
finAffichageHexMemoire:
	jr $ra
################################################################################################################
Fin:
	nop								#'Fin' du programme
	beq $zero,$zero,Fin
