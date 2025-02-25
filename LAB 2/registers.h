#ifndef REGISTERS_H
#define REGISTERS_H
#include <iostream>
#include <memory>

class Registers {
private:
    int reg[32] = {0};
    int PC = 0;
public:
    Registers();
    void setRegister(int regNum, int value);
    int getRegister(int regNum) const;
    void setPC(int value);
    int getPC() const;
    void print() const;
};

#endif