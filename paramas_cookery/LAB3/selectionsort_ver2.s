
# Arguments: $a0 = base address of array, $a1 = length
# because this function is a callee to main, and caller to the indexMinimum function and to the swap function, we need to store the values of the s registers used here into 
# the stack and restore it after. This is such that whatever s registers used in main will not be affected
selectionSort:
	addi $sp, $sp, -16 #make room on the stack to save 4 registers
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $ra, 12($sp)

    	move $s0, $zero # i = 0
loop_condition:
    	subi $s1, $a1, 1 # length - 1
    	ble $s0, $s1, loop_body
    	j end_sort

loop_body:
    	move $a0, $s0 # Pass i as 'first'
    	move $a1, $s1 # pass length - 1 (which is stored in t1) as 'last'
    	jal indexMinimum # Call indexMinimum
    	move $s2, $v0 # mini = return value

    	# Call swap function with (array, i, mini)
    	move $a0, $s0 # i
    	move $a1, $s2 # mini
    	jal swap

    	addi $s0, $s0, 1 # i++

end_sort:
    	jr $ra
    	#lets restore the s registers from the stack
    	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $ra, 12($sp)
	addi $sp, $sp, 16
