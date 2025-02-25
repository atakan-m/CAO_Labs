#include "instruction.h"
#include <iostream>

Instruction::Instruction(int rd, int rs, int rt, int imm) : rd(rd), rs(rs), rt(rt), imm(imm) {}
