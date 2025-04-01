main:
    # 1) Load 0x80000000 into $t0
    #    0x8000 = 32768 in decimal for LUI
    lui $t0 32768
    ori $t0 $t0 0        #  -2147483648 signed which is the most negative 32 bit

    # Arithmetic shift right by 2 bits
    sra $t2 $t0 2        # Should sign-extend. For -2147483648 the result = -536870912 (0xE0000000)

    # 3) Load 0x12345678 into $t3  0x1234 = 4660 decimal,  0x5678 = 22136 decimal
    lui $t3 4660         # $t3 upper half = 0x12340000
    ori $t3 $t3 22136    # $t3 = 0x12345678 (decimal 305419896 unsigned)

    # 4) Test 'jal' instruction
    jal function         # Jump and link (store PC+4 in $ra, jump to function)

    j end               # After returning from function, jump to 'end'

function:
    # 5) Show we arrived here: increment $t3 by 1
    addi $t3 $t3 1      # $t3 = 0x12345679 (decimal 305419897 unsigned)

    # Return to the caller 
    jr $ra

end:
    
    j end
