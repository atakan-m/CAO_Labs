#include "instruction.h"
#include <iostream>

// Add Instruction
class AddInstruction : public Instruction {
private:
    int dest, src1, src2;
public:
    AddInstruction(int d, int s1, int s2) : dest(d), src1(s1), src2(s2) {}
    
    void disassemble() override {
        std::cout << "add $" << dest << ", $" << src1 << ", $" << src2 << std::endl;
    }

    int execute(Registers *regs) override {
        regs->setRegister(dest, regs->getRegister(src1) + regs->getRegister(src2));
        return regs->getPC() + 1;
    }
};

// Subtract Instruction
class SubInstruction : public Instruction {
private:
    int dest, src1, src2;
public:
    SubInstruction(int d, int s1, int s2) : dest(d), src1(s1), src2(s2) {}
    
    void disassemble() override {
        std::cout << "sub $" << dest << ", $" << src1 << ", $" << src2 << std::endl;
    }

    int execute(Registers *regs) override {
        regs->setRegister(dest, regs->getRegister(src1) - regs->getRegister(src2));
        return regs->getPC() + 1;
    }
};

// OR Immediate Instruction
class OriInstruction : public Instruction {
private:
    int dest, src, imm;
public:
    OriInstruction(int d, int s, int i) : dest(d), src(s), imm(i) {}

    void disassemble() override {
        std::cout << "ori $" << dest << ", $" << src << ", " << imm << std::endl;
    }

    int execute(Registers *regs) override {
        regs->setRegister(dest, regs->getRegister(src) | imm);
        return regs->getPC() + 1;
    }
};

// Branch Not Equal Instruction
class BrneInstruction : public Instruction {
private:
    int src1, src2, offset;
public:
    BrneInstruction(int s1, int s2, int off) : src1(s1), src2(s2), offset(off) {}

    void disassemble() override {
        std::cout << "brne $" << src1 << ", $" << src2 << ", " << offset << std::endl;
    }

    int execute(Registers *regs) override {
        return (regs->getRegister(src1) != regs->getRegister(src2)) ? regs->getPC() + offset : regs->getPC() + 1;
    }
};