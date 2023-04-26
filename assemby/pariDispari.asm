.data

	str1: .asciiz "Inserisci un numero: "
	str2: .asciiz "Il numero è pari"
	str3: .asciiz "Il numero è dispari"
	
.text

#	print "Inserisci un numero"
	li $v0, 4
	la $a0, str1
	syscall
	
#	scanf
	li $v0, 5
	syscall

#	chiamata a funzione
	move $a0, $v0
	jal pariodispari
	move $t0, $v0

#	guardo il resto
	beq $t0, $zero vero
	
	# ramo false
	li $v0, 4
	la $a0, str3
	syscall
	j exit
	
	#ramo true
vero:
	li $v0, 4
	la $a0, str2
	syscall

exit:
#	program ended
	li $v0, 10
	syscall
	
	
pariodispari:
	li $t0, 2
	div $a0, $t0
	mfhi $v0
	
	jr $ra