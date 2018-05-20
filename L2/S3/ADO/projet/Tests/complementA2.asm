main:
	addi $a0,$zero,0x2000	#4 caractere, on bosse en 16bits
	addi $a1,$zero,0x200C	#le 4eme caractere seras en 200C donc fin de la saisie
	addi $a2,$zero,0xA
	jal saisieHexa		#$v0 devient l'adresse du dernier caractere enregistre en memoire
	
	addi $a0,$zero,0x2000	#adresse de debut de lecture
	add $a1,$zero,$v0	#adresse du dernier carac en memoire
	add $a2,$zero,$zero
	jal memToInt		#$v0 resultat
	
	add $a0,$zero,$v0
	jal complementA2	#$v0 resultat cpl2($a0)
	
	add $a0,$zero,$v0	#nombre a enregistrer en memoire
	addi $a1,$zero,0x2000	#adresse de debut de l'enregistrement
	addi $a2,$zero,0x200C	#derniere adresse ou enregistrer un caractere
	jal intToMem
	
	addi $a0,$zero,0x2000
	addi $a1,$zero,0x200C
	jal affichageMem
	
BoucleNull:
	nop
	beq $zero,$zero,BoucleNull


affichageMem:
	lw $v0,0($a1)
	sw $v0,0x7F0C($zero)
	addi $a1,$a1,-4
	add $a3,$zero,$a0
	add $a0,$zero,$v0
	addi $v0,$zero,11
	syscall
	add $a0,$zero,$a3
	sub $v1,$a0,$a1
	bgtz $v1,affichageMem
finAffichageMem:
	jr $ra


intToMem:
	andi $v0,$a0,0xF
	sw $v0,0($a1)
	addi $a1,$a1,4
	sub $v1,$a1,$a2
	srl $a0,$a0,4
	bgtz $v1,intToMem
finIntToMem:
	jr $ra
	


complementA2:
	ori $v1,$zero,0xFFFF
	nor $v0,$a0,$v1
	addi $v0,$v0,1
	jr $ra

memToInt:
	lw $v0,0($a1)
	add $a3,$zero,$v0	#sauvegarde de $v0 dans $a3
	addi $v1,$zero,'9'
	sub $v1,$v0,$v1
	addi $t8,$zero,'0'
	sub $v0,$v0,$t8
	blez $v1,convertit	#$v0 = valeur du caractere charge $v1 sert de verif $v0 caracter alphabétique ou décimal
	addi $v1,$zero,'A'
	sub $v0,$a3,$v1	
	addi $v0,$v0,10
convertit:
	addi $a1,$a1,-4
	bltz $a1,memToInt
finMemToInt:
	jr $ra	#resultat dans $v0




	
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
	bne $a0,$a1,saisieHexa	#tant qu'on a pas entre 4 caractere ou le caractere enter
	
finSaisieHexa:
	addi $v0,$a0,-4
	jr $ra

