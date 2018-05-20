main:
	#saisie de n
	addi $v0, $zero,5
	syscall
	
	la $a0($v0)
	jal puissance10
	
	#affichage de 10 puissance n
	
	addi $v0,$zero,1
	syscall

puissance10:#retourne 10 puissance argument dans $t8
	bgtz $a0,bouclePuissance10
	addi $t9,$zero,1
	beq $zero,$zero,finPuissance10
bouclePuissance10:
	mul $t9,$a0,10
	beq $a0,$zero,bouclePuissance10
	subi $a0,$a0,1
	beq $zero,$zero,bouclePuissance10
finPuissance10:
	jr $ra
	
Fin:
	addi $v0,$zero,10
	syscall