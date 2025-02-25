#ifndef _REGISTERS_H_
#define _REGISTERS_H_

#include <iostream>

class Registers {
public:
    class Register {
    public:
        int regNum;
        int value;
        Register(int a = 0, int b = 0) : regNum(a), value(b) {}
    };

    Register reg[31];

    void setRegister(int a, int b);
    int getRegister(int a);

    class ProgramCounter {
    public:
        int counter;
    };

    ProgramCounter PC;
    void setPC(int a);
    int getPC();
    void print();
};

#endif  /* _REGISTERS_H_ */
