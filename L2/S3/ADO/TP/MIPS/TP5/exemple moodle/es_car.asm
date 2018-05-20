main:
	lw $t0,0x7F00($zero)
	beq $t0,$zero,boucleLecture
	lw $t0,0x7F04($zero)
	sw $t0,0x7F0C($zero)
	beq $zero,$zero,boucleLecture
