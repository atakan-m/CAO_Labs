#include "computer.h"
#include "program.h"
#include <iostream>

Computer::Computer(double clockRate, double arithCPI, double storeCPI, double loadCPI, double branchCPI)
    : clockRateGHz(clockRate), cpiArith(arithCPI), cpiStore(storeCPI), cpiLoad(loadCPI), cpiBranch(branchCPI) {}

void Computer::printStats()  {
    std::cout << "Clock Rate: " << clockRateGHz << " GHz\n"
              << "CPI Arithmetic: " << cpiArith << "\n"
              << "CPI Store: " << cpiStore << "\n"
              << "CPI Load: " << cpiLoad << "\n"
              << "CPI Branch: " << cpiBranch << "\n";
}

// GLOBAL CPI CALC
double Computer::calculateGlobalCPI()  {
    return (cpiArith + cpiStore + cpiLoad + cpiBranch) / 4.0;  
}

// GLOBAL MIPS
double Computer::calculateMIPS() {
    double globalCPI = calculateGlobalCPI();
    return (clockRateGHz * 1e9) / (globalCPI * 1e6);  // Convert Hz to MIPS
}

// Program Specific Mips
double Computer::calculateMIPS( Program prog)  {
    double totalInstructions = prog.getTotalInstructions();
    if (totalInstructions == 0) return 0;

    // Weighted CPI
    double weightedCPI =
        ((prog.getNumArith() * cpiArith) +
         (prog.getNumStore() * cpiStore) +
         (prog.getNumLoad() * cpiLoad) +
         (prog.getNumBranch() * cpiBranch)) / totalInstructions;

    // Compute execution time using weighted CPI
    double totalCycles = totalInstructions * weightedCPI;
    double executionTime = totalCycles / (clockRateGHz * 1e9); // Convert GHz to Hz

    if (executionTime == 0) return 0;

    return totalInstructions / (executionTime * 1e6);
}

// Execution time 
double Computer::calculateExecutionTime( Program prog)  {
    double totalInstructions = prog.getTotalInstructions();
    if (totalInstructions == 0) return 0;  

    double globalCPI = calculateGlobalCPI();
    double totalCycles = totalInstructions * globalCPI;
    return totalCycles / (clockRateGHz * 1e9);  // Convert GHz to Hz
}