#include "computer.h"
#include "program.h"
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

double Computer::calculateMIPSSpecific(Program prog){
        double MIPS1 = (cpiArith * prog.getnumArith())/ clockRateGHz;
        double MIPS2 = (cpiStore * prog.getnumStore())/ clockRateGHz;
        double MIPS3 = (cpiLoad * prog.getnumLoad())/ clockRateGHz;
        double MIPS4 = (cpiBranch * prog.getnumBranch())/ clockRateGHz;
        return (MIPS1 + MIPS2 + MIPS3 + MIPS4);
    
}
     

double Computer::calculateExecutionTime(Program prog) {
    double globalCPI = calculateGlobalCPI();
    double totalInstructions = prog.getnumArith() + prog.getnumStore() + prog.getnumLoad() + prog.getnumBranch();

    double totalCycles = totalInstructions * globalCPI;
    return totalCycles / (clockRateGHz * 1e9);  // Convert GHz to Hz for execution time
}

double Computer::calculateMIPS(Program prog) {
    double globalCPI = calculateGlobalCPI();
    double totalInstructions = prog.getnumArith() + prog.getnumStore() + prog.getnumLoad() + prog.getnumBranch();

    double totalCycles = totalInstructions * globalCPI;
    double executiontime = totalCycles / (clockRateGHz * 1e9);  // Convert GHz to Hz for execution time
    return totalInstructions/ (executiontime * 1000000);
}

