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
#	carico i valori nelle varabili da passare nelle funzioni
	lw $a0, a
	lw $a1, b
	lw $a2, c
	lw $a3, d
	
#	riservo 8 byte sullo stack
	addi $sp, $sp, -8
	sw $s0, 4($sp) # e sullo stack
	sw $s1, 0($sp) # f sullo stack
	
	jal do_match
	
#	devo liberare lo stack
	addi $sp, $sp, 8
	move $t0, $v0
	
	la $a0, string
	li $v0, 4
	syscall
	
	move $a0, $t0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	


do_match:
	# gestiamo Z direttamente nei registri del processore
	# alloco un frame per la push di $s0 e $s1, che
	# userò per le variabili E ed F, nonchè per la push del frame pointer
	addi $sp, $sp, -12
	sw $fp, 8($sp) # salvo il frame pointer
	sw $s0, 4($sp) # salvo s0 
	sw $s1, 0($sp) # salvo s1
	addi $fp, $sp, 8 # resizing frame pointer (prima parola del nuovo frame)

	add $t0, $a0, $a1
	sub $t1, $a2, $a3
	lw $s0, 8($fp) # E in $s0
	lw $s1, 4($fp) # F in $s1
	add $t2, $s0, $s1 # E + F
	sub $t3, $a0, $a2 # A - C

	add $t0, $t0, $t1
	add $t0, $t0, $t2
	sub $v0, $t0, $t3 # allochiamo il risultato in v0

#	rimetto a posto tutto >:(
	lw $s1, 0($sp)
	lw $s0, 4($sp)
	lw $fp, 8($sp)
	addi $sp, $sp, 12 # ripristino il frame pointer
	jr $ra
	