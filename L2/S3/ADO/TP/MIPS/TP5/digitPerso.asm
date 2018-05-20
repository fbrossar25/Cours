.data
  Saisir:	.asciiz	"\n\nSaisir un caractere hexadecimal (chiffre ou majuscule):"
  Hex:		.asciiz "\n\n0x"
  Egal:		.asciiz	" = "
.text

Saisie:	#$v0 <- c
	addi $v0,$zero,4
	la $a0, Saisir
	syscall
	addi $v0, $zero,12
	syscall
	subi $a0,$v0,'0'
	bltz $a0,Saisie		#si c < '0'
	addi $a0,$zero,'F'
	sub $a0,$a0,$v0
	bltz $a0,Saisie		#si c > 'F'
	
	
	#(c < 'A') && (c > '9')  <=>  (c - '9' < 7) && ('A' - c < 7) <=> (c - '9' - 7 < 0) && ('A' - c - 7 < 0)
	#'A' - '9' = 7
	subi $a0,$v0,'9'	#$a0 <- (c - '9' - 7)
	addi $a0,$a0,-7
	bltz $a0,Saisie		#(c - '9' - 7 < 0)
	subi $a0,$zero,'A'	#$a0 <- (c - 'A' + 7)
	sub $a0,$a0,$v0
	addi $a0,$a0,-7
	bltz $a0,Saisie		#('A' - c - 7 < 0)
	
	
	add $t8,$zero,$v0
	#affichage du caractere
	addi $v0,$zero,4
	la $a0, Hex
	syscall
	add $a0,$zero,$t8
	addi $v0, $zero,11
	syscall
	addi $v0,$zero,4
	la $a0, Egal
	syscall
	add $v0,$zero,$t8

digit:
	subi $a0,$v0,'9'
	subi $v0,$v0,'0'
	blez $a0, Fin
	subi $v0,$t8,'A'
	addi $v0,$v0,10
	
Fin:
	#affichage de l'entier dans $v0
	add $a0,$zero,$v0
	addi $v0,$zero,1
	syscall
	#Fin du programme
	addi $v0, $zero ,10
	syscall