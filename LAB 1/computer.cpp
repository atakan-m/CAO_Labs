#include "computer.h"
#include <iostream>


Computer::Computer(double clockRate, double arithCPI, double storeCPI, double loadCPI, double branchCPI)
    : clockRateGHz(clockRate), cpiArith(arithCPI), cpiStore(storeCPI), cpiLoad(loadCPI), cpiBranch(branchCPI) {}

void Computer::printStats(){
    std::cout << "Clock Rate: " << clockRateGHz << " GHz\n";
    std::cout << "CPI Arithmetic: " << cpiArith << "\n";
    std::cout << "CPI Store: " << cpiStore << "\n";
    std::cout << "CPI Load: " << cpiLoad << "\n";
    std::cout << "CPI Branch: " << cpiBranch << "\n";
}

double Computer::calculateGlobalCPI(){
    return (cpiArith + cpiStore + cpiLoad + cpiBranch) / 4; //  Calculation
}
