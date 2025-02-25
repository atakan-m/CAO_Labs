#ifndef PROGRAM_H
#define PROGRAM_H
#include "derived_instructions.h"
#include <vector>
#include <memory>

class Program {
private:
    std::vector<std::unique_ptr<Instruction>> instructions;
public:
    void appendInstruction(std::unique_ptr<Instruction> instr);
    void disassemble() const;
    void execute(Registers &regs);
};

#endif // PROGRAM_H