# Test Program for SRA and JAL Instructions
# Using only decimal numbers for compatibility

main:
    # Test SRA instruction with various cases
    
    # Case 1: Positive number, small shift (240 >> 2 = 60)
    ori $t0, $zero, 240     # Load 240 (positive)
    sra $t1, $t0, 2         # Shift right by 2
    
    # Case 2: Positive number, large shift (15 >> 8 = 0)
    ori $t2, $zero, 15      # Load 15 (positive)
    sra $t3, $t2, 8         # Shift right by 8
    
    # Case 3: Negative number, small shift (-256 >> 3 = -32)
    lui $t4, 65535          # Upper bits of -256 (0xFFFF)
    ori $t4, $t4, 65280     # Complete -256 (0xFFFFFF00)
    sra $t5, $t4, 3         # Shift right by 3
    
    # Case 4: Negative number, large shift (-2147483648 >> 16 = -32768)
    lui $t6, 32768          # Load -2147483648 (0x80000000)
    sra $t7, $t6, 16        # Shift right by 16
    
    # Case 5: Zero value (0 >> 5 = 0)
    ori $t8, $zero, 0       # Load 0
    sra $t9, $t8, 5         # Shift right by 5
    
    # Test JAL instruction with various cases
    
    # Case 1: Simple jump and link
    jal test_function1       # Jump to function
    
    # Case 2: Nested jumps
    jal test_function2       # Jump to function with nested JAL
    
    # Case 3: Jump to different locations
    ori $a0, $zero, 1       # Set parameter to 1
    jal conditional_jump     # Jump based on parameter
    
    ori $a0, $zero, 2       # Set parameter to 2
    jal conditional_jump     # Jump based on parameter
    
    # End of test program
   j end

test_function1:
    jr $ra                  # Return to caller

test_function2:
    jal nested_function     # Nested jump
    jr $ra                  # Return to main

nested_function:
    jr $ra                  # Return to test_function2

conditional_jump:
    ori $t0, $zero, 1       # Load comparison value 1
    beq $a0, $t0, jump_target1
    ori $t0, $zero, 2       # Load comparison value 2
    beq $a0, $t0, jump_target2
    jr $ra                  # Default return
    
jump_target1:
    jr $ra
    
jump_target2:
    jr $ra

end:
	j end
