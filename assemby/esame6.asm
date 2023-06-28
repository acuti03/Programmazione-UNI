.data
	arr1: .word  1 2 3 4 5
	arr2: .word 1 2 3 4 55
	str: .ascii "Viene "
	space: .ascii " "
	
.text
	li $a2, 5 # lenght
	
	la $a0, arr1 # X pointer
	la $a1, arr2 # Y pounter
	jal correlationCoefficient
	move $t0, $v0
	
	li $v0, 4
	la $a0, str
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
	
#	return
	li $v0, 10
	syscall
	
	
	
correlationCoefficient:
#	PUSH sullo stack dei registri che devo preservare
	addi $sp, $sp, -28
	sw $s0, 24($sp) # n
	sw $s1, 20($sp) # X pointer
	sw $s2, 16($sp) # Y pointer
	sw $s3, 12($sp) # sum_X
	sw $s4, 8($sp) # sum_Y
	sw $s5, 4($sp) # sum_XY
	sw $s6, 0($sp) # i
	
	move $s0, $a2 # n
	move $s1, $a0 # X pointer
	move $s2, $a1 # Y pointer
	
	li $s6, 0
	
for:
	beq $s6, $s0, endFor
	
	lw $t0, 0($s1) # X[i]
	lw $t1, 0($s2) # Y[i]
	
	add $s3, $s3, $t0
	add $s4, $s4, $t1
	mul $t0, $t0, $t1 # posso sovrascrivere perche tanto X[i] non mi servità più
	add $s5, $s5, $t0
	
	addi $s1, $s1, 4 # aumento il puntatore X di 4 cosi mi punterà alla prossima cella
	addi $s2, $s2, 4 # faccio la stessa cosa per Y
	addi $s6, $s6, 1
	j for
	
endFor:

#	print sum_X
	li $v0, 1
	move $a0, $s3
	syscall
	
#	print space
	li $v0, 4
	la $a0, space
	syscall
	
#	print sum_Y
	li $v0, 1
	move $a0, $s4
	syscall
	
#	print space
	li $v0, 4
	la $a0, space
	syscall

#	print sum_XY
	li $v0, 1
	move $a0, $s5
	syscall
	
#	print space
	li $v0, 4
	la $a0, space
	syscall
	
	mul $t0, $s0, $s5 # n * sum_XY
	mul $t1, $s3, $s4 # sum_X * sum_Y
	sub $v0, $t0, $t1 # return value
	
#	POP
	lw $s6, 0($sp)
	lw $s5, 4($sp)
	lw $s4, 8($sp)
	lw $s3, 12($sp)
	lw $s2, 16($sp)
	lw $s1, 20($sp)
	lw $s0, 24($sp)
	addi $sp, $sp, 28
	
	jr $ra