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


# =======================
# SELECTION SORT FUNCTION (isort)
# =======================
isort:
    addi $sp, $sp, -24   # Make room on the stack to save registers
    sw $s0, 0($sp)
    sw $s1, 4($sp)
    sw $s2, 8($sp)
    sw $s3, 12($sp)
    sw $s4, 16($sp)
    sw $ra, 20($sp)

    move $s0, $a0       # Base address of array
    move $s1, $a1       # Length of array

    li $s2, 0           # i = 0

loop_condition:
    subi $s3, $s1, 1    # last index = length - 1
    bge $s2, $s3, end_sort  # If i >= length-1, exit

loop_body:
    # Call indexMinimum(a, i, length-1)
    move $a0, $s0       # Base address of array
    move $a1, $s2       # First index
    move $a2, $s3       # Last index
    jal indexMinimum
    move $s4, $v0       # mini = indexMinimum return value

    # Call swap(a, i, mini)
    move $a0, $s0       # Base address of array
    move $a1, $s2       # i
    move $a2, $s4       # mini
    jal swap

    addi $s2, $s2, 1    # i++
    j loop_condition

end_sort:
    # Restore saved registers
    lw $s0, 0($sp)
    lw $s1, 4($sp)
    lw $s2, 8($sp)
    lw $s3, 12($sp)
    lw $s4, 16($sp)
    lw $ra, 20($sp)
    addi $sp, $sp, 24
    jr $ra

# =======================
# SWAP FUNCTION (swap)
# =======================
swap:
    # Arguments:
    # $a0 = base address of array
    # $a1 = index i
    # $a2 = index j

    sll $t1, $a1, 2     # i * 4 (convert to byte offset)
    sll $t2, $a2, 2     # j * 4 (convert to byte offset)

    add $t1, $a0, $t1   # Address of v[i]
    add $t2, $a0, $t2   # Address of v[j]

    # Load values
    lw $t3, 0($t1)      # t3 = v[i]
    lw $t4, 0($t2)      # t4 = v[j]

    # Swap values
    sw $t4, 0($t1)      # v[i] = v[j]
    sw $t3, 0($t2)      # v[j] = old v[i]

    jr $ra              # Return

# =======================
# FIND MINIMUM INDEX FUNCTION (indexMinimum)
# =======================
indexMinimum:
    # Arguments:
    # $a0 = base address of array
    # $a1 = first index
    # $a2 = last index
    # Returns: $v0 = index of minimum element

    move $t1, $a1       # mini = first
    move $t2, $a2       # last index
    move $t3, $a0       # Base address of array

    sll $t4, $t1, 2     # Convert index to byte offset
    add $t4, $t3, $t4   # Address of v[first]
    lw $t5, 0($t4)      # min = v[first]

    addi $t0, $t1, 1    # i = first + 1

for_loop:
    bgt $t0, $t2, forEnd  # If i > last, exit loop

    sll $t6, $t0, 2     # Convert index to byte offset
    add $t6, $t3, $t6   # Address of v[i]
    lw $t7, 0($t6)      # Load v[i]

    bge $t7, $t5, next_iteration  # If v[i] >= min, skip

    move $t1, $t0       # mini = i
    move $t5, $t7       # min = v[i]

next_iteration:
    addi $t0, $t0, 1    # i++
    j for_loop

forEnd:
    move $v0, $t1       # Return mini
    jr $ra              # Return to caller