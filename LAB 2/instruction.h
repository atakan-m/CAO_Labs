#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include "registers.h"

class Instruction {
public:
    virtual ~Instruction() {}
    virtual void disassemble() = 0;
    virtual int execute(Registers *regs) = 0;
};

#endif  /* _INSTRUCTION_H_ */
