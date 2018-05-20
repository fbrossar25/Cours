.data 
  Msg :		.asciiz "Fin du programme."
.text
main :
	#pseudo-instructions 1 : 
	lui $t0,0x1001		#affecte les 16 bits de poids forts avec 0x1001 et tout les autres avec 0
				#(opération $t0 <- (Imm16 << 16) & 0xff00) pour 32 bits
				
	ori $t0,$t0,0x100	#opération $t0 OU Imm16 (extension par des 0 sur les bits de rang supérieur)
	
	#pseudo-instructions 2 :
	lui $at,0xf0f0		#affecte $at avec 0xf0f00000
	ori $t1,$t1,0xf0f0	#affecte $t1 avec 0x0000f0f0 OU $t1
	add $t2,$t2,$at		#affecte $t2 avec $t2 + $at
	
	#pseudo-instructions 3 : donne la valeur absolue de $t0
	addi $t0,$zero,0x00000001
	#avec $t0 < 0 ($t0 = 1)
	sra $at,$t0,0x1f
	xor $t1,$at,$t0
	sub $t1,$t1,$at
	
	addi $t0,$zero,0xffffffff
	#avec $t0 > 0 ($t0 = -1)
	sra $at,$t0,0x1f
	xor $t1,$at,$t0
	sub $t1,$t1,$at
	
Fin :
	#affichage d'une chaine de caractere
	addi $v0, $zero , 4
	la $a0, Msg
	syscall
	#fermeture du programme
	addi $v0, $zero ,10
	syscall
