#include "simulator.h"

void Simulator::run() {
    program.execute(&regs);
    regs.print();
}
