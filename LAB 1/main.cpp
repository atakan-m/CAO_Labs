#include "computer.h"
#include "program.h"
#include <iostream>

int main() {
    // ✅ Create computers based on Table 2.3 specifications
    Computer comp1(1.0, 2, 2, 3, 4);    // 1 GHz
    Computer comp2(1.2, 2, 3, 4, 3);    // 1.2 GHz
    Computer comp3(2.0, 2, 2, 4, 6);    // 2 GHz

    // ✅ Create programs based on Table 2.4
    Program progA(2000, 100, 100, 50);       // Program A
    Program progB(200, 800, 500, 500);     // Program B (fractions-based)
    Program progC(500, 100, 2000, 200);      // Program C

    // ✅ Display computer specifications & global MIPS
    std::cout << "=== Computer Specifications ===\n\n";

    std::cout << "Computer 1:\n";
    comp1.printStats();
    std::cout << "Global CPI: " << comp1.calculateGlobalCPI() << "\n";
    std::cout << "MIPS (Global): " << comp1.calculateMIPS() << "\n\n";

    std::cout << "Computer 2:\n";
    comp2.printStats();
    std::cout << "Global CPI: " << comp2.calculateGlobalCPI() << "\n";
    std::cout << "MIPS (Global): " << comp2.calculateMIPS() << "\n\n";

    std::cout << "Computer 3:\n";
    comp3.printStats();
    std::cout << "Global CPI: " << comp3.calculateGlobalCPI() << "\n";
    std::cout << "MIPS (Global): " << comp3.calculateMIPS() << "\n\n";

    // ✅ Display execution time & MIPS per program on each computer
    std::cout << "=== Execution Time & MIPS for Programs ===\n\n";

    // Loop through all programs for each computer
    for (int i = 0; i < 3; ++i) {
        Computer* currentComputer;
        if (i == 0) currentComputer = &comp1;
        else if (i == 1) currentComputer = &comp2;
        else currentComputer = &comp3;

        std::cout << "Computer " << (i + 1) << " running Program A:\n";
        std::cout << "Execution Time: " << currentComputer->calculateExecutionTime(progA) << " seconds\n";
        std::cout << "MIPS: " << currentComputer->calculateMIPS(progA) << "\n\n";

        std::cout << "Computer " << (i + 1) << " running Program B:\n";
        std::cout << "Execution Time: " << currentComputer->calculateExecutionTime(progB) << " seconds\n";
        std::cout << "MIPS: " << currentComputer->calculateMIPS(progB) << "\n\n";

        std::cout << "Computer " << (i + 1) << " running Program C:\n";
        std::cout << "Execution Time: " << currentComputer->calculateExecutionTime(progC) << " seconds\n";
        std::cout << "MIPS: " << currentComputer->calculateMIPS(progC) << "\n\n";
    }

    return 0;
}