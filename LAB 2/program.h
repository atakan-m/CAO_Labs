#ifndef _PROGRAM_H_
#define _PROGRAM_H_

#include <vector>
#include "instruction.h"

class Program {
private:
    std::vector<Instruction*> instructions;

public:
    void addInstruction(Instruction* instr) {
        instructions.push_back(instr);
    }

    void disassemble() {
        for (auto instr : instructions) {
            instr->disassemble();
        }
    }

    void execute(Registers *regs) {
        for (auto instr : instructions) {
            regs->setPC(instr->execute(regs));
        }
    }
};

#endif  /* _PROGRAM_H_ */
