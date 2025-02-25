#include "instruction.h"
#include <iostream>

// Define OriInstruction
OriInstruction::OriInstruction(int d, int s, int i) : dest(d), src(s), imm(i) {}

void OriInstruction::disassemble() {
    std::cout << "ori $" << dest << ", $" << src << ", " << imm << std::endl;
}

int OriInstruction::execute(Registers *regs) {
    regs->setRegister(dest, regs->getRegister(src) | imm);
    return regs->getPC() + 1;
}

// Define BrneInstruction
BrneInstruction::BrneInstruction(int s1, int s2, int off) : src1(s1), src2(s2), offset(off) {}

void BrneInstruction::disassemble() {
    std::cout << "brne $" << src1 << ", $" << src2 << ", " << offset << std::endl;
}

int BrneInstruction::execute(Registers *regs) {
    return (regs->getRegister(src1) != regs->getRegister(src2)) ? regs->getPC() + offset : regs->getPC() + 1;
}