.data
  Saisir:	.asciiz	"\nSaisir un entier entre 0 et 15:\n"
  Affiche:	.asciiz	" = 0x"
.text

Saisie:	#saisie de n >= 0 ET < 16 puis sauvegarde de n dans $t0 sachant que n est garde temporairement dans $v0
	addi $v0,$zero,4
	la $a0, Saisir
	syscall
	addi $v0, $zero,5
	syscall
	add $a0,$zero,15
	sub $a0,$a0,$v0
	bltz $v0,Saisie
	bltz $a0,Saisie
	add $t0,$zero,$v0
	
forDigit:			#si n < 10 alors sortie = '0' + n sinon sortie = n - 10 + 'A'
	add $a0,$zero,$v0	#on stocke n dans $a0
	#$a0 : nombre, $v0 : caractere
	addi $v0,$a0,'0'	#$v0 <- n + '0'
	subi $a0,$a0,9		#n <- n-9 : pour tester si on doit rendre un chiffre ou un caractere
	add $t1,$v0,$zero
	blez $a0, Fin	#branchement au label si $a0 <= 0 : si oui le resultat a deja ete calcule dans $v0 sinon
			#on ajoute 7 a  $v0 et on le stock dans $a0
	addi $a0,$v0,7
	add $t1,$zero,$a0	#sauvegarde de $a0 dans $t1
Fin:
	#affichage de l'entier entre qui a  ete sauvegarde dans $t0
	add $a0,$zero,$t0
	addi $v0,$zero,1
	syscall
	#affichage de la chaine Affiche
	addi $v0,$zero,4
	la $a0, Affiche
	syscall
	#affichage du caractere de code ascii $a0
	add $a0,$zero,$t1
	addi $v0, $zero,11
	syscall
	#Fin du programme
	addi $v0, $zero ,10
	syscall
