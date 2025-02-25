#include "program.h"

void Program::execute(Registers *regs) {
    for (auto instr : instructions) {
        std::cout << "[DEBUG] Executing instruction at PC: " << regs->getPC() << std::endl;
        int newPC = instr->execute(regs);
        regs->setPC(newPC);
        std::cout << "[DEBUG] PC updated to: " << newPC << std::endl;
    }
}