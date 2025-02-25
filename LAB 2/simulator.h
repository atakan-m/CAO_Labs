#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include "program.h"

class Simulator {
private:
    Registers regs;
    Program program;

public:
    void loadProgram(Program p) {
        program = p;
    }
    void run() {
        program.execute(&regs);
        regs.print();
    }
};

#endif  /* _SIMULATOR_H_ */
