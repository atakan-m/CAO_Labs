#include "registers.h"

void Registers::setRegister(int regNum, int value) {
    if (regNum != 0)
        reg[regNum] = value;
}

int Registers::getRegister(int regNum) const {
    return reg[regNum];
}

void Registers::setPC(int value) {
    PC = value;
}

int Registers::getPC() const {
    return PC;
}

void Registers::print() const {
    std::cout << "PC: " << PC << "\nRegisters:\n";
    for (int i = 0; i < 32; i++)
        std::cout << "$" << i << ": " << reg[i] << "\n";
}
