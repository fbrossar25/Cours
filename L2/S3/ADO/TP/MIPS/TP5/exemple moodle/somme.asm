.data
	Lecture: .asciiz "Entrez un nombre ?\n"
	Somme: .asciiz "Somme("
	Egal: .asciiz ")=" 
.text	# <=> int res=1; for(int i=n;i==0;i--){res += i}
	addi $v0, $zero, 4 # Afficher chaine
	la $a0,Lecture
	syscall
	addi $v0, $zero, 5# Lire entier 
	syscall
	add $t1, $v0 , $zero # t1 <- v0 
	addi $t0, $zero, 1
TantQue:
	# $v0=0 a FinTantQue
	beq $v0,$zero, FinTantQue 
	add $t0,$t0, $v0 # $t0 <- $t0 + $v0
	addi $v0, $v0, -1 # $v0 <- $v0 - 1
	beq $zero,$zero,TantQue
FinTantQue:
	addi $v0, $zero, 4 # "Somme("
	la $a0, Somme
	syscall
	addi $v0, $zero, 1    # Afficher n
	add $a0, $t1, $zero
	syscall
	la $a0, Egal	
	addi $v0, $zero, 4    # Afficher ")="
	syscall
	addi $v0, $zero, 1    # Afficher n
	add $a0, $t0, $zero
	syscall
	addi $v0, $zero, 10  # Fin   
	syscall
