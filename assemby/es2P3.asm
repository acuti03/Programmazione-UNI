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

.globl main

main:

	jal do_match
	
	la $a0, string
	li $v0, 4
	syscall
	
	lw $a0, z
	li $v0, 1
	syscall
	
	li $v0, 10
    syscall


do_match:

	addi $sp, $sp, -12
	sw $t0, 0($sp)
	sw $t1, 4($sp)
	sw $s0, 8($sp)
	
#	carico nelle variabili i valori e li sommo
	lw $t0, a
	lw $t1, b
	add $t0, $t0, $t1
	add $s0, $s0, $t0

#	faccio la stessa cosa di prima continuando l'esercizio
	lw $t0, c
	lw $t1, d
	sub $t0, $t0, $t1
	add $s0, $s0, $t0
	
	lw $t0, e
	lw $t1, f
	add $t0, $t1, $t0
	add $s0, $s0, $t0
	
	lw $t0, a
	lw $t1, c
	sub $t0, $t0, $t1
	sub $s0, $s0, $t0
	
#	assegno il valore a z
	sw $s0, z
	
#	metto il valore di ritorno
	lw $v1, z
	
#	ripristino i registri
	lw $t0, 0($sp)
	lw $t1, 4($sp)
	lw $s0, 8($sp)

#	mando avanti lo stack pointer e ritorno ra
	addi $sp, $sp, 12
	jr $ra