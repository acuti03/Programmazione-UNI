.data
	a: .word 15
	b: .word 10
	c: .word 7
	d: .word 2
	e: .word 18
	f: .word -3
	z: .word 0
	str: .asciiz "il risultato è: "
	
.text
#	leggo a e b dalla memoria e li sommo
	lw $t0, a
	lw $t1, b
	add $s0, $t0, $t1
	
#	da qui faccio lo stesso con le altre variabili
	lw $t0, c
	lw $t1, d
	sub $t0, $t0, $t1
	add $s0, $s0, $t0
	
	lw $t0, e
	lw $t1, f
	add $t0, $t0, $t1
	add $s0, $s0, $t0
	
	lw $t0, a
	lw $t1, c
	sub $t0, $t0, $t1
	sub $s0, $s0, $t0
	
#	carico il risultato contenuto in s0 nell'area di memoria: z
	sw $s0, z
	
#	syscall per stampare la stringa
	la $a0, str
	li $v0, 4
	syscall
	
#	syscall per stampare il risultato
	lw $a0, z
	li $v0, 1
	syscall
	
#	chiudo il programma
	li $v0, 10
	syscall