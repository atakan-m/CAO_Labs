#include "derived_instructions.h"
#include <iostream>

AddInstruction::AddInstruction(int rd, int rs, int rt) : Instruction(rd, rs, rt) {}
void AddInstruction::disassemble() const {
    std::cout << "add $" << rd << ", $" << rs << ", $" << rt << "\n";
}
int AddInstruction::execute(Registers &regs) {
    regs.setRegister(rd, regs.getRegister(rs) + regs.getRegister(rt));
    return regs.getPC() + 1;
}

SubInstruction::SubInstruction(int rd, int rs, int rt) : Instruction(rd, rs, rt) {}
void SubInstruction::disassemble() const {
    std::cout << "sub $" << rd << ", $" << rs << ", $" << rt << "\n";
}
int SubInstruction::execute(Registers &regs) {
    regs.setRegister(rd, regs.getRegister(rs) - regs.getRegister(rt));
    return regs.getPC() + 1;
}

OriInstruction::OriInstruction(int rd, int rs, int imm) : Instruction(rd, rs, 0, imm) {}
void OriInstruction::disassemble() const {
    std::cout << "ori $" << rd << ", $" << rs << ", " << imm << "\n";
}
int OriInstruction::execute(Registers &regs) {
    regs.setRegister(rd, regs.getRegister(rs) | imm);
    return regs.getPC() + 1;
}

BrneInstruction::BrneInstruction(int rs, int rt, int offset) : Instruction(0, rs, rt, offset) {}
void BrneInstruction::disassemble() const {
    std::cout << "brne $" << rs << ", $" << rt << ", " << imm << "\n";
}
int BrneInstruction::execute(Registers &regs) {
    return (regs.getRegister(rs) != regs.getRegister(rt)) ? regs.getPC() + imm + 1 : regs.getPC() + 1;
}