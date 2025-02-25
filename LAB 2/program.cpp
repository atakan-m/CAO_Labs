#include "program.h"

void Program::execute(Registers *regs) {
    for (auto instr : instructions) {
        int newPC = instr->execute(regs);
        regs->setPC(newPC);
    }
}
