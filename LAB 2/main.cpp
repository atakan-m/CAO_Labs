#include "program.h"
#include "instruction.h"  // Only include header file, NOT CPP file
#include <iostream>

int main() {
    Registers regs;
    Program program;

    // Manually setting initial register values
    regs.setRegister(2, 10);
    regs.setRegister(3, 5);

    // Add instructions to the program
    program.addInstruction(new AddInstruction(1, 2, 3));  // $1 = $2 + $3 (10 + 5)
    program.addInstruction(new SubInstruction(4, 2, 3));  // $4 = $2 - $3 (10 - 5)

    // Debugging: Print PC before execution
    std::cout << "Before Execution, PC: " << regs.getPC() << std::endl;

    // Disassemble to check instruction loading
    std::cout << "Disassembly:" << std::endl;
    program.disassemble();

    // Execute program
    std::cout << "\nExecution:" << std::endl;
    program.execute(&regs);

    // Debugging: Print PC after execution
    std::cout << "After Execution, PC: " << regs.getPC() << std::endl;

    // Print register values to verify updates
    regs.print();

    return 0;
}