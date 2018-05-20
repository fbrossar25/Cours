main:
	addi $a0,$zero,0x2000	#4 caractere, on bosse en 16bits
	addi $a1,$zero,0x200C	#le 4eme caractere seras en 0x200C donc fin de la saisie
	addi $a2,$zero,0xA
	jal saisieHexa		#$v0 devient l'adresse du dernier caractere enregistre en memoire
	
	addi $a1,$zero,0x200C
	beq $v0,$a1,jump
	
	addi $a0,$zero,0x2000
	addi $a1,$zero,0x200C
	jal completeWithZeros	
jump:
	addi $a0,$zero,0x2000	#adresse de debut de lecture
	addi $a1,$zero,0x200C	#adresse du dernier carac en memoire
	add $a2,$zero,$zero
	jal affichageHexMemoire

	beq $zero,$zero,Fin

completeWithZeros:
	sub $v1,$a1,$a0
	bltz $v1,finCompleteWithZeros
	lw $v0,0($a1)
	bne $v0,$zero,finCompleteWithZeros
	addi $v0,$zero,'0'
	sw $v0,0($a1)
	addi $a1,$a1,-4
	beq $zero,$zero,completeWithZeros
	
finCompleteWithZeros:
	jr $ra

affichageHexMemoire:
	addi $v0,$zero,'0'
	sw $v0,0x7F0C($zero)
	addi $v0,$zero,'x'
	sw $v0,0x7F0C($zero)
boucleAffichageHexMemoire:
	sub $v1,$a1,$a0
	bltz $v1,finAffichageHexMemoire
	lw $v0,0($a1)
	sw $v0,0x7F0C($zero)
	###################################################
	addi $a1,$a1,-4
	###################################################
	beq $zero,$zero,boucleAffichageHexMemoire
	
finAffichageHexMemoire:
	jr $ra
	
saisieHexa:
	lw $t0,0x7F00($zero)
	beq $t0,$zero,saisieHexa
	lw $t0,0x7F04($zero)
	beq $t0,$a2,finSaisieHexa	#$t0 == caractere enter
	addi $v1,$zero,'0'
	sub $v1,$t0,$v1
	bltz $v1,saisieHexa	#$t0 < '0'
	addi $v1,$zero,'F'
	sub $v1,$t0,$v1
	bgtz $v1,saisieHexa	#$t0 > 'F' ?
	
	#$t0 > '9' && $t0 < 'A' ?
	addi $v0,$zero,'9'
	addi $v1,$zero,'A'
	
boucleVerif:
	beq $v0,$v1,finBoucleVerif
	addi $v0,$v0,1
	beq $t0,$v0,saisieHexa
	beq $zero,$zero,boucleVerif
	
finBoucleVerif:
	sw $t0,0($a0)
	addi $a0,$a0,4
	sub $v0,$a1,$a0
	bgez $v0,saisieHexa	#tant qu'on a pas entre 4 caractere ou le caractere enter
	
finSaisieHexa:
	addi $v0,$a0,-4
	jr $ra

Fin:
	nop
	beq $zero,$zero,Fin
