.data
	Msg:	.asciiz "Hello\n" #ne s'affichera pas correctement sur des valeurs 32bits
	Msg2:	.word	'H','e','l','l','o','\n',0
	Test:	.space 255	#on réserve une deuxieme chaine de 255 caractere maxi
.text
main:
	la $a0,Msg2
	jal AfficheChaine
	la $a0,Test
	jal LectureChaine
	la $a0,Test
	jal AfficheChaine
	
	beq $zero,$zero,main
	
	beq $zero,$zero,Exit

AfficheChaine:
	#a0 : adr chaine
	add $t0,$zero,$a0
	#addi $v0,$zero,11

AfficheChaineBoucle:
	lw $a0,0($t0)
	beq $a0,$zero,AfficheChaineFin
	lw $a0,0x7F0C($zero)
	#syscall #affichage car dans $a0
	addi $t0,$t0,4
	beq $zero,$zero,AfficheChaineBoucle

AfficheChaineFin:
	jr $ra

LectureChaine:
	#a0 : adr chaine
	#code ascii du return
	addi $t0,$zero,0xA
	
LectureChaineBoucle:
	#addi $v0,$zero,12
	#syscall #Lecture car en $v0
	lw $t0,0x7F00($zero)
	beq $v0,$zero,LectureChaineBoucle
	lw $t0,0x7F04($zero)
	beq $v0,$t0,LectureChaineFin
	sw $v0,0($a0)
	addi $a0,$a0,4
	beq $zero,$zero,LectureChaineBoucle
	
LectureChaineFin:
	sw $zero,0($a0)
	jr $ra

Exit:
	addi $v0,$zero,10
	syscall
