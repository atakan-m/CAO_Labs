#ifndef DERIVED_INSTRUCTIONS_H
#define DERIVED_INSTRUCTIONS_H
#include "instruction.h"

class AddInstruction : public Instruction {
public:
    AddInstruction(int rd, int rs, int rt);
    void disassemble() const override;
    int execute(Registers &regs) override;
};

class SubInstruction : public Instruction {
public:
    SubInstruction(int rd, int rs, int rt);
    void disassemble() const override;
    int execute(Registers &regs) override;
};

class OriInstruction : public Instruction {
public:
    OriInstruction(int rd, int rs, int imm);
    void disassemble() const override;
    int execute(Registers &regs) override;
};

class BrneInstruction : public Instruction {
public:
    BrneInstruction(int rs, int rt, int offset);
    void disassemble() const override;
    int execute(Registers &regs) override;
};

#endif // DERIVED_INSTRUCTIONS_H