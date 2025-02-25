#include "program.h"
#include "instruction.h"
#include <iostream>


int main() {
    Registers regs;
    Program program;

    // Load MIPS Program into C++ Simulator
    program.addInstruction(new OriInstruction(1, 0, 12));  // $1 = 12
    program.addInstruction(new OriInstruction(2, 0, 4));   // $2 = 4
    program.addInstruction(new OriInstruction(3, 0, 1));   // $3 = 1

    // Loop: 
    program.addInstruction(new AddInstruction(4, 4, 1));   // $4 += $1
    program.addInstruction(new SubInstruction(2, 2, 3));   // $2 -= $3
    program.addInstruction(new BrneInstruction(2, 0, -2)); // If $2 != 0, go back 2 instructions (loop)

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