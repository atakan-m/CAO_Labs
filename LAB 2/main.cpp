#include "program.h"
#include <iostream>

int main() {
    Registers regs;
    Program program;

    program.addInstruction(new AddInstruction(1, 2, 3));
    program.addInstruction(new SubInstruction(4, 5, 6));

    std::cout << "Disassembly:" << std::endl;
    program.disassemble();

    std::cout << "\nExecution:" << std::endl;
    program.execute(&regs);
    regs.print();

    return 0;
}
