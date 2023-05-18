.data

	a: .word 12 11 13 5 6
	dim: .word 5
	str: .asciiz " "

.text

	la $a1, a
	lw $a2, dim
	jal insertionSort
	
	la $a1, a
	lw $a2, dim
	jal printArray
	
	li $v0, 10
	syscall


insertionSort:
	li $t0, 1 # i
	addi $a1, $a1, 4
	add $t1, $t1, $zero # key
	add $t2, $t2, $zero # j

forInsertionSort:
	beq $t0, $a2, endInsertionSort

	lw $t1,($a1) # key
	subi $t2, $t0, 1
	
	addi $t3, $a1, -4
	lw $t4, ($t3) # arr[j]

while:
	blt $t2, $zero, continue
	ble $t4, $t1, continue

	sw $t4, 4($t3) # arr[j+1] = arr[j]
	subi $t2, $t2, 1
	subi $t3, $t3, 4
	lw $t4, ($t3)
	j while

continue:
	sw $t1, 4($t3) # arr[j+1] = key

	addi $a1, $a1, 4
	addi $t0, $t0, 1
	j forInsertionSort

endInsertionSort:
	jr $ra
	
	
printArray:
	li $t0, 0 # i
	
forPrintArray:
	beq $t0, $a2, endPrintArray
	
	li $v0, 1
	lw $a0, ($a1) # arr[i]
	syscall
	
	li $v0, 4
	la $a0, str
	syscall
	
	addi $t0, $t0, 1
	addi $a1, $a1, 4
	j forPrintArray
	
endPrintArray:
	jr $ra