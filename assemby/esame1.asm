.data
	str1: .asciiz "Enter a number to check whether prime or not: "
	str2: .asciiz " is a prime number."
	str3: .asciiz " is not a prime number."

.text
#	print the first string
	li $v0, 4
	la $a0, str1
	syscall
#	read num
	li $v0, 5
	syscall
	
	move $s0, $v0 # num
	
# if(num == 0 || num == 1)
	beq $s0, $zero, flagTo1
	beq $s0, 1, flagTo1
	j flagNot1
	
flagTo1:
	li $s1, 1 # flag
	
flagNot1:
	addi $s2, $s2, 2 # i
	
	li $t0, 2
	div $s0, $t0
	mflo $t0 # num/2
	
loop:
	bgt $s2, $t0, endLoop
	
	div $s0, $s2
	mfhi $t1 # num % i
	
	bne $t1, $zero, continue # (num % i) == 0
	li $s1, 1
	j endLoop
	
continue:
	addi $s2, $s2, 1
	j loop
	
endLoop:
	bne $s1, $zero, notPrime
	
	li $v0, 1
	move $a0, $s0
	syscall
	
	li $v0, 4
	la $a0, str2
	syscall
	
j end
	 
notPrime:
	li $v0, 1
	move $a0, $s0
	syscall
	
	li $v0, 4
	la $a0, str3
	syscall

end:
	li $v0 10
	syscall
	