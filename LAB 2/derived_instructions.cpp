#include "derived_instructions.h"
#include <iostream>
#include <memory>

AddInstruction::AddInstruction(int rd, int rs, int rt) : Instruction(rd, rs, rt) {}
void AddInstruction::disassemble() const {
    std::cout << "add $" << rd << ", $" << rs << ", $" << rt << "\n";
}
int AddInstruction::execute(Registers &regs) {
    regs.setRegister(rd, regs.getRegister(rs) + regs.getRegister(rt));
    return regs.getPC() + 1;
}
