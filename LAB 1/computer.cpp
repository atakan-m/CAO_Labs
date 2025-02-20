#include "computer.h"
#include "program.h"
#include <iostream>

Computer::Computer(double clockRate, double arithCPI, double storeCPI, double loadCPI, double branchCPI)
    : clockRateGHz(clockRate), cpiArith(arithCPI), cpiStore(storeCPI), cpiLoad(loadCPI), cpiBranch(branchCPI) {}

void Computer::printStats() const {
    std::cout << "Clock Rate: " << clockRateGHz << " GHz\n"
              << "CPI Arithmetic: " << cpiArith << "\n"
              << "CPI Store: " << cpiStore << "\n"
              << "CPI Load: " << cpiLoad << "\n"
              << "CPI Branch: " << cpiBranch << "\n";
}

// ✅ Fix: Ensures correct global CPI calculation
double Computer::calculateGlobalCPI()  {
    return (cpiArith + cpiStore + cpiLoad + cpiBranch) / 4.0;  // Ensure division by double
}

// ✅ Fix: Correct formula for global MIPS
double Computer::calculateMIPS() {
    double globalCPI = calculateGlobalCPI();
    return (clockRateGHz * 1e9) / (globalCPI * 1e6);  // Convert Hz to MIPS
}

// ✅ Fix: Correct formula for program-specific MIPS
double Computer::calculateMIPS( Program prog)  {
    double totalInstructions = prog.getTotalInstructions();
    if (totalInstructions == 0) return 0;

    // Compute weighted CPI based on the program's instruction mix
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

// ✅ Correct execution time calculation
double Computer::calculateExecutionTime( Program prog)  {
    double totalInstructions = prog.getTotalInstructions();
    if (totalInstructions == 0) return 0;  

    double globalCPI = calculateGlobalCPI();
    double totalCycles = totalInstructions * globalCPI;
    return totalCycles / (clockRateGHz * 1e9);  // Convert GHz to Hz
}