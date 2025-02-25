#include "instruction.h"
#include <iostream>

// Define AddInstruction
AddInstruction::AddInstruction(int d, int s1, int s2) : dest(d), src1(s1), src2(s2) {}

void AddInstruction::disassemble() {
    std::cout << "add $" << dest << ", $" << src1 << ", $" << src2 << std::endl;
}

int AddInstruction::execute(Registers *regs) {
    regs->setRegister(dest, regs->getRegister(src1) + regs->getRegister(src2));
    return regs->getPC() + 1;  // ✅ Ensure it increments properly!
}
// Define SubInstruction
SubInstruction::SubInstruction(int d, int s1, int s2) : dest(d), src1(s1), src2(s2) {}

void SubInstruction::disassemble() {
    std::cout << "sub $" << dest << ", $" << src1 << ", $" << src2 << std::endl;
}

int SubInstruction::execute(Registers *regs) {
    regs->setRegister(dest, regs->getRegister(src1) - regs->getRegister(src2));
    return regs->getPC() + 1;  // ✅ Must correctly increment PC!
}