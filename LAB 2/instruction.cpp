#include "instruction.h"
#include <memory>

Instruction::Instruction(int rd, int rs, int rt, int imm) : rd(rd), rs(rs), rt(rt), imm(imm) {}
