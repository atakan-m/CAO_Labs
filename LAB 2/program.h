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

    void Program::execute(Registers *regs) {
        for (auto instr : instructions) {
            int newPC = instr->execute(regs);  // ✅ Capture the new PC from execute()
            regs->setPC(newPC);  // ✅ Properly update PC
        }
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
