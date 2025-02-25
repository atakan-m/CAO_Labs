#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

#include "program.h"

class Simulator {
private:
    Registers regs;
    Program program;

public:
    void loadProgram(Program p);  // Only declare here, no `{}`!
    void run();  // Only declare here, no `{}`!
};

#endif  /* _SIMULATOR_H_ */