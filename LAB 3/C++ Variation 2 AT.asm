.data
array:  .word 4, 2, 3, 1   # Array: [4, 2, 3, 1]
message: .asciiz "Number of elements smaller than a[i]: "

.text
.globl main
.globl countLessThan

main:
    # Load the base address of array into $a0
    la $a0, array      # $a0 = base address of a[]

    # Load length of array into $a1
    li $a1, 4          # $a1 = length of array (4 elements)

    # Load index i into $a2 (testing i = 2)
    li $a2, 2          # $a2 = index of the element to compare (a[2] = 3)

    # Call countLessThan
    jal countLessThan  # Result will be stored in $v0

    # Print message
    li $v0, 4
    la $a0, message
    syscall

    # Print return value (the count)
    li $v0, 1
    move $a0, $v0  # Move return value into $a0 for printing
    syscall

    # Exit program
    li $v0, 10
    syscall


#-----Count Less Than----
.text
.globl countLessThan  
#   $a0 = a[]
#   $a1 = length
#   $a2 = index i 
#   $v0 = count of elements smaller than a[i]
countLessThan:
    li $t0, 0       # $t0 =  stores the number of elements smaller than a[i] in other words count
    li $t1, 0       # $t1 = loop going through array = j

countLoop:
    # If j >= length, exit the loop
    bge $t1, $a1, countReturn

    # Compute the address of a[j] and load its value into $t3
    sll $t2, $t1, 2       # $t2 = index to byte offset
    add $t2, $t2, $a0     # $t2 = address of a[j] which is calculated through base address + offset
    lw $t3, 0($t2)        # $t3 = a[j] 

    # Compute the address of a[i] and load its value into $t5
    sll $t4, $a2, 2       # $t4 = i * 4 (convert index to byte offset)
    add $t4, $t4, $a0     # $t4 = base address + offset (address of a[i])
    lw $t5, 0($t4)        # $t5 = a[i] (load value from memory)

    # If a[j] < a[i], increase count
    blt $t3, $t5, incrementCount  

    # If a[j] == a[i], check if i < j
    beq $t3, $t5, checkIndex  
    j continueLoop  # Otherwise, move to next j

checkIndex:
    # If i < j, increase count (to handle duplicates correctly)
    blt $a2, $t1, incrementCount
    j continueLoop

incrementCount:
    addi $t0, $t0, 1  # increases by one

continueLoop:
    addi $t1, $t1, 1  # next element
    j countLoop       # Repeat loop

countReturn:
    move $v0, $t0  # Move count into $v0 (return value)
    jr $ra         # Return to caller