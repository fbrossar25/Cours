.data 
  Msg :		.asciiz "Fin du programme."
  Eq :		.asciiz "Equivalence\n"
  Diff:		.asciiz "Différence\n"
.text
main :
	#pseudo-instructions move :
	addi $t0,$zero,0xf #$t0 <- 0xF
	move $t1,$t0
	#<=>
	addi $t2,$t0,0
	#<=>
	add $t3,$t0,$zero
	
	#pseudo-instruction not :
	not $t4,$t0
	#<=>
	nor $t5,$t0,$zero
	
	#pseudo-instruction beq $t1,Imm16, etiquette
TestBeqImm16:
	beq $t0,0xf,Vrai	#Si $t0 == 0xf va à Vrai
	beq $zero,$zero,Faux	#Sinon  va à Faux
	
	#beq $t0,Imm16<=>
TestSansPseudoIns:
	addi $t0,$t0,0xff
	addi $at,$zero,0xfff	#on peut affecter une Imm16 dans $at ici : $at <- 0xff
	beq $t0,$at,Vrai	#Si $t0 == $at	//(0xff)// on va à Vrai
	beq $zero,$zero,Faux	#Sinon on va à faux
	
Vrai:
	addi $v0, $zero , 4
	la $a0, Eq
	syscall
	add $t0,$zero,0xff
	beq $zero,$zero,TestBeqImm16
Faux:
	addi $v0, $zero , 4
	la $a0, Diff
	syscall
	beq $t0,0xff,TestSansPseudoIns
	beq $zero,$zero,Fin
	
Fin :
	#affichage d'une chaine de caractere
	addi $v0, $zero , 4
	la $a0, Msg
	syscall
	#fermeture du programme
	addi $v0, $zero ,10
	syscall