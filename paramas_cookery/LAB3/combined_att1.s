		.text
		j	main			# Jump to main-routine

		.data
str1:		.asciiz "Insert the array size \n"
str2:		.asciiz "Insert the array elements,one per line  \n"
str3:		.asciiz "The sorted array is : \n"
str5:		.asciiz "\n"

		.text
		.globl	main
main: 
		la	$a0, str1		# Print of str1
		li	$v0, 4			#
		syscall				#

		li	$v0, 5			# Get the array size(n) and
		syscall				# and put it in $v0
		move	$s2, $v0		# $s2=n
		sll	$s0, $v0, 2		# $s0=n*4
		sub	$sp, $sp, $s0		# This instruction creates a stack
						# frame large enough to contain
						# the array
		la	$a0, str2		#
		li	$v0, 4			# Print of str2
		syscall				#
            
		move	$s1, $zero		# i=0
for_get:	bge	$s1, $s2, exit_get	# if i>=n go to exit_for_get
		sll	$t0, $s1, 2		# $t0=i*4
		add	$t1, $t0, $sp		# $t1=$sp+i*4
		li	$v0, 5			# Get one element of the array
		syscall				#
		sw	$v0, 0($t1)		# The element is stored
						# at the address $t1
		la	$a0, str5
		li	$v0, 4
		syscall
		addi	$s1, $s1, 1		# i=i+1
		j	for_get
exit_get:	move	$a0, $sp		# $a0=base address af the array
		move	$a1, $s2		# $a1=size of the array
		jal	isort			# isort(a,n)
						# In this moment the array has been 
						# sorted and is in the stack frame 
		la	$a0, str3		# Print of str3
		li	$v0, 4
		syscall

		move	$s1, $zero		# i=0
for_print:	bge	$s1, $s2, exit_print	# if i>=n go to exit_print
		sll	$t0, $s1, 2		# $t0=i*4
		add	$t1, $sp, $t0		# $t1=address of a[i]
		lw	$a0, 0($t1)		#
		li	$v0, 1			# print of the element a[i]
		syscall				#

		la	$a0, str5
		li	$v0, 4
		syscall
		addi	$s1, $s1, 1		# i=i+1
		j	for_print
exit_print:	add	$sp, $sp, $s0		# elimination of the stack frame 
              
		li	$v0, 10			# EXIT
		syscall				#



#_________________________isort_____________________________

# Arguments: $a0 = base address of array, $a1 = length
# because this function is a callee to main, and caller to the indexMinimum function and to the swap function, we need to store the values of the s registers used here into 
# the stack and restore it after. This is such that whatever s registers used in main will not be affected
isort:
	addi $sp, $sp, -24 #make room on the stack to save 4 registers
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $s4, 16($sp)
	sw $ra, 20($sp)


	move $s0, $a0 # move base adress to s0 for a sec
	move $s1, $a1 # move length array to s1 for a sec
	
    	move $s2, $zero # i = 0
loop_condition:
    	subi $s3, $s1, 1 # length - 1
    	ble $s2, $s3, loop_body
    	j end_sort

loop_body:
	#Call indexMinimumm with (first, last, base adress)
    	move $a0, $s2 # pass i as 'first'
    	move $a1, $s3 # pass length - 1 (which is stored in t1) as 'last'
    	move $a3, $s0 # pass base adress of the array
    	jal indexMinimum # Call indexMinimum
    	move $s4, $v0 # mini = return value

    	# Call swap function with (base adress array, i, mini)
    	move $a0, $s0 # pass base adress of array
    	move $a1, $s2 # pass i
    	move $a2, $s4 # pass mini
    	jal swap

    	addi $s2, $s2, 1 # i++

end_sort:
    	jr $ra
    	#lets restore the s registers from the stack
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	lw $ra, 20($sp)
	addi $sp, $sp, 24





#________________________________swap______________
# Function: swap(int v[], int i, int j)
# Arguments:
# $a0 = base address of array v
# $a1 = index i
# $a2 = index j
swap:
    	sll $t1, $a1, 2       # $t1 = i * 4
    	sll $t2, $a2, 2       # $t2 = j * 4

    	add $t1, $a0, $t1     # $t1 = address of v[i]
    	add $t2, $a0, $t2     # $t2 = address of v[j]

    	#Load values from memory
    	lw  $t3, 0($t1)       # $t3 = v[i]
    	lw  $t4, 0($t2)       # $t4 = v[j]

    	#Store values to swap them
    	sw  $t4, 0($t1)       # v[i] = v[j]
    	sw  $t3, 0($t2)       # v[j] = tmp (old v[i])

    	jr  $ra                       



#________________________________indexmin_________
#Function; indexMinimum(mini, last, base addressa array)
indexMinimum:
	move $t1, $a0 #(assuming a0 is int first) #mini = first -> $t1 = mini
	move $t2, $a1 #(assuming a1 is int last, which corresponds to length array - 1 -> the last index)
	move $t3, $a2 #(assuming a3 is the base adress of the array)
	#we will change a1, a2, a3 later once we assemble every codes into 1 file, for now I just want to work out the logic
	
	move $sp, $t3 #move the stack pointer to the base adress of the array
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
