.data
	Lecture: .asciiz "Entrez un nombre ?\n"
	Somme: .asciiz "Somme("
	Egal: .asciiz ")=" 
.text
	addi $v0, $zero, 4  # Afficher chaine
	la $a0,Lecture
	syscall
	addi $v0, $zero, 5 # Lire entier  
	syscall
	add $a0, $v0, $zero  # Argument dans $a0
	add $t0, $a0, $zero  # t0 <- $a0
    la $t1,somme
	jalr $t1
	add $t1, $v0, $zero # Sauvergarde $v0 
	addi $v0, $zero, 4 # Afficher "Somme("
	la $a0, Somme
	syscall
	addi $v0, $zero, 1    # Afficher n
	add $a0, $t0, $zero
	syscall
	la $a0, Egal	
	addi $v0, $zero, 4    # Afficher ")="
	syscall
	addi $v0, $zero, 1    # Afficher n
	add $a0, $t1, $zero
	syscall
	addi $v0, $zero, 10  # Fin   
	syscall
#entree $a0, retour dans $v0
somme:
	addi $v0, $zero, 1   # Fact(0)=1
sommeTantQue:
	beq $a0, $zero, sommeFinTantQue
	add $v0, $v0, $a0
	addi $a0, $a0, -1
	beq $zero,$zero sommeTantQue
sommeFinTantQue:
	jr $ra # retour au programme appelant
