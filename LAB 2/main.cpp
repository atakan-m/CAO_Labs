#include <iostream>
#include <memory>
#include "program.h"
#include "derived_instructions.h"
#include "registers.h"

int main() {
    Registers regs;
    Program prog;

    prog.appendInstruction(std::make_unique<OriInstruction>(1, 0, 12));
    prog.appendInstruction(std::make_unique<OriInstruction>(2, 0, 4));
    prog.appendInstruction(std::make_unique<OriInstruction>(3, 0, 1));
    prog.appendInstruction(std::make_unique<AddInstruction>(4, 4, 1));
    prog.appendInstruction(std::make_unique<SubInstruction>(2, 2, 3));
    prog.appendInstruction(std::make_unique<BrneInstruction>(2, 0, -4));
    
    std::cout << "Disassembling Program:\n";
    prog.disassemble();
    
    std::cout << "\nExecuting Program:\n";
    prog.execute(regs);
    
    std::cout << "\nFinal Register State:\n";
    regs.print();

    return 0;
}
