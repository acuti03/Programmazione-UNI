.data
	
	enter: .asciiz "input a number larger than 1: "
	prime: .asciiz " is a prime number "
	
	
.text

	li $t2, 1 # z
	addi $t1, $t1, 2 # y
	
	li $v0, 4
	la $a0, enter
	syscall
	
	li $v0, 5
	syscall
	move $s0, $v0 # x
	
loop:
	beq $t1, $s0, endLoop
	beq $t2, $zero, return
	
	div $s0, $t1
	mfhi $t2
	
	addi $t1, $t1, 1
	j loop
	
endLoop:
	li $v0, 1
	move $a0, $s0
	syscall
	
	li $v0, 4
	la $a0, prime
	syscall
	
return:
	li $v0, 10
	syscall