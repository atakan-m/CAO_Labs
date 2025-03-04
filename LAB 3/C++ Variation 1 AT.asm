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