.data
  Saisir:	.asciiz	"\nSaisir un entier (entier negatif permis) :\n"
  Hex:		.asciiz	"\n0x"
.text
	addi $v0,$zero,4
	la $a0, Saisir
	syscall
	addi $v0, $zero,5
	syscall
	add $t0,$zero,$v0
	#affichage de la chaine Affiche
	addi $v0,$zero,4
	la $a0,Hex
	syscall
	addi $t3,$zero,7	#limite compteur

FaireTantQue:
	srl $a0,$t0,28
	addi $v0,$a0,'0'	#$v0 <- n + '0'
	subi $a0,$a0,9
	add $t1,$v0,$zero
	blez $a0,Affichage
	add $t1,$v0,7
	
Affichage:
	#affichage du caractere de code ascii $t1
	add $a0,$zero,$t1
	addi $v0, $zero,11
	syscall
	beq $t2,$t3,Arret	#condition d'arret : si compteur == 7
	addi $t2,$t2,1		#compteur++
	sll $t0,$t0,4
	beq $zero,$zero,FaireTantQue 
	
Arret:
	#Fin du programme
	addi $v0, $zero ,10
	syscall
