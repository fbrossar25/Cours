.data 
  Msg :		.asciiz "Fin du programme."
  Chaine:	.asciiz "Test"
.text
main :


AfficheChaine:
	#a0 : adr chaine
	add $t0,$zero,$a0
	la $a0, Chaine
	addi $v0,$zero,11

AfficheChaineBoucle:
	lb $a0,0($t0)
	beq $a0,$zero,AfficheChaineFin
	syscall #affichage car dans $a0
	addi $t0,$t0,1
	beq $zero,$zero,AfficheChaineBoucle

AfficheChaineFin:
	jr $ra

LectureChaineBoucle:
	#a0 : adr chaine
	#code ascci caractere return
	addi $v0,$zero,12
	syscall	#Lecutre car dans $v0
	beq $v0,$t0,LectureChaineFin
	sb $v0,0($a0)
	addi $a0,$a0,1
	beq $zero,$zero,LectureChaineBoucle
	
LectureChaineFin:
	sb $zero,0($a0)
	addi $a0, $zero , 4
	syscall
	jr $ra

Fin :
	#affichage d'une chaine de caractere
	addi $v0, $zero , 4
	la $a0, Msg
	syscall
	#fermeture du programme
	addi $v0, $zero ,10
	syscall
