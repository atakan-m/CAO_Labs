#include "simulator.h"
#include <iostream>

// Define the functions here
void Simulator::loadProgram(Program p) {
    program = p;
}

void Simulator::run() {
    program.execute(&regs);
    regs.print();
}