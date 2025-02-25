
// File: instruction.h
#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "registers.h"

class Instruction {
protected:
    int rd, rs, rt, imm;
public:
    Instruction(int rd, int rs, int rt, int imm = 0);
    virtual ~Instruction() {}
    virtual void disassemble() const = 0;
    virtual int execute(Registers &regs) = 0;
};

#endif // INSTRUCTION_H