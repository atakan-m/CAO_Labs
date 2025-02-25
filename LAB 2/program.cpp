#include "program.h"
#include <iostream>
#include <memory>

void Program::appendInstruction(std::unique_ptr<Instruction> instr) {
    instructions.push_back(std::move(instr));
}
void Program::disassemble() const {
    for (const auto &instr : instructions) {
        instr->disassemble();
    }
}
void Program::execute(Registers &regs) {
    while (regs.getPC() < instructions.size()) {
        regs.setPC(instructions[regs.getPC()]->execute(regs));
    }
}
