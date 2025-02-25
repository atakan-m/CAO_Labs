#include "simulator.h"

void Simulator::loadProgram(Program p) {
    program = p;
}

void Simulator::run() {
    program.execute(&regs);
    regs.print();
}
