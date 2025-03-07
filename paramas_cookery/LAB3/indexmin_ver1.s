IndexMinimum:
	move $t1, $a0 #(assuming a0 is int first) #mini = first -> $t1 = mini
	move $t2, $a1 #(assuming a1 is int last, which corresponds to length array - 1 -> the last index)
	move $t3, $a3 #(assuming a3 is the base adress of the array)
	#we will change a1, a2, a3 later once we assemble every codes into 1 file, for now I just want to work out the logic
	
	move $sp, $t3 #move the stack pointer to the basea adress of the array
	add $t4, $sp, $t1 #index of v[first]
	lw $t5,  0($t4) #min = v[first] -> $t5 = min
	
	
for_loop: 
	move $t0, $zero #i=0 
	addi $t0, $t1, 1 #i=first +1 -> $t0 = i
for_condition: 
	ble $t0, $t2, forBody
	j forEnd
forBody: 
	move $sp, $t3 #rest our stack pointer position to the base adress of the array
	sll $t6, $t0, 2 #everytime for is called, shift our stack pointer by 4*i
	add $t7, $t6, $sp
	lw $t8, 0($t7)#give me the value of v at that stack pointer
	ble $t7, $t5, ifBody #branch to ifBody if v[i] < min
	j for_condition
ifBody:
	move $t1, $t0 #overwrite mini with i
	move $t5, $t7 #overwrite min with v[i]

forEnd:
	jr $ra
