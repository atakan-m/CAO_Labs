#include "instruction.h"
#include <iostream>

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
