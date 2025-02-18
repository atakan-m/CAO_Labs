#include "computer.h"
#include <iostream>

// Constructor: initializes all member variables
Computer::Computer(double clockRate, double arithCPI, double storeCPI, double loadCPI, double branchCPI)
    : clockRateGHz(clockRate), cpiArith(arithCPI), cpiStore(storeCPI), cpiLoad(loadCPI), cpiBranch(branchCPI) {}

// Function to print all attributes of the Computer object
void Computer::printStats() const {
    std::cout << "Clock Rate: " << clockRateGHz << " GHz\n";
    std::cout << "CPI Arithmetic: " << cpiArith << "\n";
    std::cout << "CPI Store: " << cpiStore << "\n";
    std::cout << "CPI Load: " << cpiLoad << "\n";
    std::cout << "CPI Branch: " << cpiBranch << "\n";
}

double Computer::calculateGlobalCPI() const {
    return (cpiArith + cpiStore + cpiLoad + cpiBranch) / 4; //  Calculation
}
