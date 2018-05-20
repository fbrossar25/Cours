#BROSSARD-Florian_TP2B_Sujet4
.data
	n1:	.asciiz "Saisir n1 : "
	n2:	.asciiz "Saisir n2 : "
	sdl:	.asciiz "\n\n"
	EqSign:	.asciiz	"n1 et n2 sont de meme signe"
	DiffSign: .asciiz "n1 et n2 sont de signe different"
.text
	addi $t8,$zero,9
Do:
	addi $v0,$zero,4
	la $a0,n1
	syscall
	addi $v0,$zero,5
	syscall
	add $t0,$zero,$v0	#n1 dans $t0
	addi $v0,$zero,4
	la $a0,sdl
	syscall
	addi $v0,$zero,4
	la $a0,n2
	syscall
	addi $v0,$zero,5
	syscall
	add $t1,$zero,$v0	#n2 dans $t1
	addi $v0,$zero,4
	la $a0,sdl
	syscall
	sra $t0,$t0,31
	sra $t1,$t1,31
	beq $t0,$t1,signEqual
	addi $v0,$zero,4
	la $a0,DiffSign
	syscall
	beqz $zero,While
signEqual:
	addi $v0,$zero,4
	la $a0,EqSign
	syscall
While:
	addi $v0,$zero,4
	la $a0,sdl
	syscall
	addi $t2,$t2,1
	bne $t2,$t8,Do
	addi $v0,$zero,10
	syscall
