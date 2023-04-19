.data
	i: .word 3
	j: .word 6
	k: .word 0
	
.text
	lui $t0, 0x1001
	lw $s0, 0($t0)
	lw $s1, 4($t0)
	lw $s2, 8($t0)
	
	slt $t1, $s0, $s1 # t1 vale 1 se i < j
	# quando non ho il ramo else posso evitare di fare una jump
	beq $t1, $zero, false
	
	addi $s2, $zero, 1
	
false:
	li $v0, 1
	move $a0, $s2
	syscall
	
	li $v0, 10
	syscall