.data 
  Msg :		.asciiz "Hello World ! \n\n"
  Truc:		.asciiz "TRUC ! \n"
.text
main :
	addi $v0, $zero , 4
	la $a0, Msg
	syscall
	la $a0, Truc
	syscall
	addi $v0, $zero ,10
	syscall
