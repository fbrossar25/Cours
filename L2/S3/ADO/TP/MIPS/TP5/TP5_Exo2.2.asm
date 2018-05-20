.data
  End:		.asciiz "Fin du programme !!"
.text
forDigit:
	#$a0 : nombre, $v0 : cractere
	addi $a0,$zero,0xA
	addi $v0,$a0,'0'
	addi $a0,$a0,-9
	blez $a0, forDigitChiffre
	add $v0,$v0,7
forDigitChiffre:
	jr $ra
digit:
	#$a0 : caractere, $v0 : nombre
	addi $v0,$a0,'0'
	addi $a0,$a0,-'0'
	blez $a0, digitChiffre
	addi $a0,$a0,...
digitChiffre:
	jr $ra
#Sans appel de fonction
#$a0 : nombre, $a0 : caractere
	addi $a0,$a0,-9
	blez $a0, Chiffre1
	addi $a0,$a0,7
Chiffre1:
	addi $a0,$a0,...
	#$a0 : caractere, $a0 : nombre
	addi $a0,$a0,-0x39
	blez $a0, Chiffre2
	addi $a0,$a0,...
Chiffre2:
	addi $v0,$a0,...
		

Fin:
	addi $v0, $zero,4
	la $a0, End
	syscall
	addi $v0, $zero ,10
	syscall
