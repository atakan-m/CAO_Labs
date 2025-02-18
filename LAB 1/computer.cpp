#include "computer.h"
#include "program.h"
#include <iostream>


Computer::Computer(double clockRate, double arithCPI, double storeCPI, double loadCPI, double branchCPI)
    : clockRateGHz(clockRate), cpiArith(arithCPI), cpiStore(storeCPI), cpiLoad(loadCPI), cpiBranch(branchCPI) {}

Program::Program(int numArith, int numStore, int numLoad, int numBranch)
    : numArith(numArith), numStore(numStore), numLoad(numLoad), numBranch(numBranch) {}
    
Program::Program(int numArith, double numStore, double numLoad, double numBranch)
    : numArith(numArith), numStore(numStore), numLoad(numLoad), numBranch(numBranch) {}

    

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

double Computer::calculateExecutionTime(Program){
    return ( (numStroe * cpiStore) );
}
