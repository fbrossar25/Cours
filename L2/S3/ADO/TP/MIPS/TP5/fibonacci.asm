.data
	Saisir:	.asciiz "\n\nSaisir un entier > 1 :"
	fib:	.asciiz "\n\nfib("
	eq:	.asciiz	") = "
.text

Saisie:
	#affichage de la chaine Saisir
	addi $v0,$zero,4
	la $a0, Saisir
	syscall
	#saisie de n
	addi $v0, $zero,5
	syscall
	#verif de n
	addi $v0,$v0,-2
	bltz $v0,Saisie		#si n - 2 < 0 alors on relance la Saisie
	add $t3,$v0,$zero	#compteur de boucle restantes $t3 <- (n - 2)  car on a deja F0 et F1
	addi $t1,$zero,1	#$t0 = F0 = 0, $t1 = F1 = 1
	addi $t8,$v0,2
	
Boucle:
	add $t2,$t0,$t1
	beq $t3,$zero, Fin
	add $t0,$zero,$t1
	add $t1,$zero,$t2
	addi $t3,$t3,-1
	beq $zero,$zero, Boucle

Fin:	
	#affichage de la chaine fib
	addi $v0,$zero,4
	la $a0,fib
	syscall
	#affichage de n
	add $a0,$zero,$t8
	addi $v0,$zero,1
	syscall
	#affichage de la chaine eq
	addi $v0,$zero,4
	la $a0,eq
	syscall
	#affichage de fib(n)
	add $a0,$zero,$t2
	addi $v0,$zero,1
	syscall
	addi $v0,$zero,10
	syscall