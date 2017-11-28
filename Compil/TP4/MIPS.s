	.data
temp0:	.word 4
a:	.word 8
b:	.word 16
temp1:	.word 20
c:	.word 24

	.text
main:
	# UOP_MINUS
	li $t0, 1
	neg $t0, $t0
	sw $t0, temp0

	# COPY
	lw $t0, temp0
	sw $t0, a

	# COPY
	li $t0, 2
	sw $t0, b

	# BOP_MULT
	lw $t0, a
	lw $t1, b
	mul $t0, $t0, $t1
	sw $t0, temp1

	# COPY
	lw $t0, temp1
	sw $t0, c

	# CALL_PRINT
	li $v0, 1
	lw $a0, c
	syscall

	# EXIT
	li $v0, 10
	syscall

