.data
	str1: .asciiz "Enter the number of rows :"
	str2: .asciiz "Enter the number of columns :"
	aCapo: .ascii "\n"
	
.text
	li $v0, 4
	la $a0, str1
	syscall
	
	li $v0, 5
	syscall
	move $s0, $v0 # rows
	
	li $v0, 4
	la $a0, str2
	syscall
	
	li $v0, 5
	syscall
	move $s1, $v0 # columns
	
	li $s2, 1 # i
	li $s4, 1 # k
	
while1:
	bgt $s2, $s0, endWhile1
	
	li $s3, 1 # j
	
	while2:
		bgt $s3, $s1, endWhile2
		
		li $v0, 1
		move $a0, $s4
		syscall
		
		addi $s4, $s4, 1
		addi $s3, $s3, 1
		
		j while2
	endWhile2:
	
	addi $s2, $s2, 1
	
	li $v0, 4
	la $a0, aCapo
	syscall
	
	j while1
endWhile1:


li $v0, 10
syscall