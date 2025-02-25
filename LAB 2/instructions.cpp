#include "instruction.h"
#include <iostream>

// Define AddInstruction
AddInstruction::AddInstruction(int d, int s1, int s2) : dest(d), src1(s1), src2(s2) {}

void AddInstruction::disassemble() {
    std::cout << "add $" << dest << ", $" << src1 << ", $" << src2 << std::endl;
}

int AddInstruction::execute(Registers *regs) {
    regs->setRegister(dest, regs->getRegister(src1) + regs->getRegister(src2));
    return regs->getPC() + 1;
}

// Define SubInstruction
SubInstruction::SubInstruction(int d, int s1, int s2) : dest(d), src1(s1), src2(s2) {}

void SubInstruction::disassemble() {
    std::cout << "sub $" << dest << ", $" << src1 << ", $" << src2 << std::endl;
}

int SubInstruction::execute(Registers *regs) {
    regs->setRegister(dest, regs->getRegister(src1) - regs->getRegister(src2));
    return regs->getPC() + 1;
}

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
    if (regs->getRegister(src1) != regs->getRegister(src2)) {
        return regs->getPC() + offset;  // Jump back to loop
    }
    return regs->getPC() + 1;  // Continue normally
}