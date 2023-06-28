.data
	str1: .asciiz "Inserire due numeri interi separandoli mediante CARRIAGE RETURN: "
	str2: .asciiz "Il minimo comune multiplo vale "

.text
#	print str1
	li $v0, 4
	la $a0, str1
	syscall
	

	li $v0, 5
	syscall
	move $a0, $v0 # num1
	
	li $v0, 5
	syscall
	move $a1, $v0 # num2
	
	jal minimoComuneMultiplo
	move $t0, $v0
	
#	print str2	
	li $v0, 4
	la $a0, str2
	syscall
	
#	print mcm
	li $v0, 1
	move $a0, $t0
	syscall
	
#	exit
	li $v0, 10
	syscall
	
minimoComuneMultiplo:
#	preservo $ra e i parametri
	addi $sp, $sp, -12
	sw $ra, 8($sp)
	sw $a1, 4($sp)
	sw $a0, 0($sp)
	
	jal massimoComunDivisore
	
	mul $t0, $a1, $a0
	div $t0, $v0
	mflo $v0
	
#	pop
	lw $ra, 8($sp)
	lw $a1, 4($sp)
	lw $a0, 0($sp)
	addi $sp, $sp, 12
	
	jr $ra

massimoComunDivisore:
	move $s0, $a0
	move $s1, $a1
	
while:
	ble $s1, $zero, endWhile
	
	div $s0, $s1
	mfhi $t0
	
	move $s0, $s1
	
	move $s1, $t0
	
	j while
	
endWhile:
	move $v0, $s0
	jr $ra