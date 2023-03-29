.data
	a: .word 15
	b: .word 10
	c: .word 7
	d: .word 2
	e: .word 18
	f: .word -3
	z: .word 0
	string: .asciiz "il risultato vale: "

.text
	lui $t0, 0x1001
	lw $t1, 0($t0)
	lw $t2 4($t0)
	
	add $s0, $t1, $t2
	
	lw $t1, 8($t0)
	lw $t2, 12($t0)
	
	sub $t3, $t1, $t2
	add $s0, $s0, $t3
	
	lw $t1, 16($t0)
	lw $t2, 20($t0)
	
	add $t3, $t1, $t2
	add $s0, $s0, $t3
	
	lw $t1, 0($t0)
	lw $t2, 8($t0)
	
	sub $t3, $t1, $t2
	sub $s0, $s0, $t3
	
	
	sw $s0, 24($t0) # carico dentro z il valore di s0
	
#	stampa stringa
	la $a0, string
	addi $v0, $zero, 4
	syscall
	
#	stampa il numero
	lw $a0, 24($t0)
	addi $v0, $zero, 1
	
	syscall
	
	