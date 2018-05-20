.data
	Lecture: .asciiz "Entrez un nombre ?\n"
	Egaux:	 .asciiz "Nombres egaux \n"
	Diff:     .asciiz "Nombre differents \n" 
.text
	addi $v0, $zero, 4    # Afficher chaine
	la $a0,Lecture
	syscall
	addi $v0, $zero, 5   # Lire un entier 
	syscall           
	add $t0, $v0, $zero
	addi $v0, $zero, 4    # Afficher chaine
	la $a0,Lecture
	syscall
	addi $v0, $zero, 5   # Lire entier 
	syscall           
	bne $t0, $v0, Sinon # rs!=rt aller à Sinon
	la $a0,Egaux # Adr chaine Egaux
	beq $zero,$zero,FinSi
Sinon:
	la $a0,Diff # Adr chaine Diff
FinSi:
	addi $v0, $zero, 4 # Afficher chaine
	syscall
	addi $v0, $zero, 10  # Terminer   
	syscall
