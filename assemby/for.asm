.data

	str1: .asciiz "Enter a positive integer : "
	str2: .asciiz "Sum = "
	
.text
#	print a string	
	li $v0, 4
	la $a0, str1
	syscall
	
#	scanf
	li $v0, 5
	syscall
	
#	for
	move $t0, $v0 # fine conteggio - num
	li $t1, 1 # inizio conteggio - count
	move $t2, $zero # sum
	
loopLabel:
	add $t2, $t2, $t1
	
#	aggiorno
	addi $t1, $t1, 1
	
#	verifica condizione
	ble $t1, $t0, loopLabel
	
# ritorno
	li $v0, 4
	la $a0, str2
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 10
	syscall

	