.data
	a: .word 1
	b: .word 8
	c: .word 190
	str1: .asciiz "BINGOOOO"
	str2: .asciiz "NO >:("
	
.text
	lw $s0, a
	lw $s1, b
	lw $s2, c
	
	
	beq $s0, 1, bTrue
	beq $s0, 2, bTrue
	beq $s0, 4, bTrue
	beq $s0, 6, bTrue
	j False
	
bTrue:
	beq $s1, 8, cTrue
	j False
	
cTrue:
	bne $s2, 10, False
	
	# vero
	li $v0, 4
	la $a0, str1
	syscall
	j Exit
	
False:
	# falso
	li $v0, 4
	la $a0, str2
	syscall

Exit:
	li $v0, 10
	syscall