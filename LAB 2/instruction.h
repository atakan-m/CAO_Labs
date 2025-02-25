#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include "registers.h"

class Instruction {
public:
    virtual ~Instruction() {}
    virtual void disassemble() = 0;
    virtual int execute(Registers *regs) = 0;
};

// Declare AddInstruction
class AddInstruction : public Instruction {
private:
    int dest, src1, src2;
public:
    AddInstruction(int d, int s1, int s2);
    void disassemble() override;
    int execute(Registers *regs) override;
};

// Declare SubInstruction
class SubInstruction : public Instruction {
private:
    int dest, src1, src2;
public:
    SubInstruction(int d, int s1, int s2);
    void disassemble() override;
    int execute(Registers *regs) override;
};

// Declare OriInstruction
class OriInstruction : public Instruction {
private:
    int dest, src, imm;
public:
    OriInstruction(int d, int s, int i);
    void disassemble() override;
    int execute(Registers *regs) override;
};

// Declare BrneInstruction
class BrneInstruction : public Instruction {
private:
    int src1, src2, offset;
public:
    BrneInstruction(int s1, int s2, int off);
    void disassemble() override;
    int execute(Registers *regs) override;
};

#endif  /* _INSTRUCTION_H_ */