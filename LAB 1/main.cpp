#include "computer.h"
#include "program.h"
#include <iostream>

int main() {
    // ✅ Create computers based on Table 2.3 specifications
    Computer comp1(1.0, 2, 2, 3, 4);    // 1 GHz
    Computer comp2(1.2, 2, 3, 4, 3);    // 1.2 GHz
    Computer comp3(2.0, 2, 2, 4, 6);    // 2 GHz

    // ✅ Create programs based on Table 2.4
    Program progA(2000, 100, 100, 50);
    Program progB(2000, 0.1, 0.4, 0.25);
    Program progC(500, 100, 2000, 200);

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

    // ✅ Display execution time & MIPS for each program (without loop)
    std::cout << "=== Execution Time & MIPS for Programs ===\n\n";

    // ✅ Computer 1 with Programs
    std::cout << "Computer 1 running Program A:\n";
    std::cout << "Execution Time: " << comp1.calculateExecutionTime(progA) << " seconds\n";
    std::cout << "MIPS: " << comp1.calculateMIPS(progA) << "\n\n";

    std::cout << "Computer 1 running Program B:\n";
    std::cout << "Execution Time: " << comp1.calculateExecutionTime(progB) << " seconds\n";
    std::cout << "MIPS: " << comp1.calculateMIPS(progB) << "\n\n";

    std::cout << "Computer 1 running Program C:\n";
    std::cout << "Execution Time: " << comp1.calculateExecutionTime(progC) << " seconds\n";
    std::cout << "MIPS: " << comp1.calculateMIPS(progC) << "\n\n";

    // ✅ Computer 2 with Programs
    std::cout << "Computer 2 running Program A:\n";
    std::cout << "Execution Time: " << comp2.calculateExecutionTime(progA) << " seconds\n";
    std::cout << "MIPS: " << comp2.calculateMIPS(progA) << "\n\n";

    std::cout << "Computer 2 running Program B:\n";
    std::cout << "Execution Time: " << comp2.calculateExecutionTime(progB) << " seconds\n";
    std::cout << "MIPS: " << comp2.calculateMIPS(progB) << "\n\n";

    std::cout << "Computer 2 running Program C:\n";
    std::cout << "Execution Time: " << comp2.calculateExecutionTime(progC) << " seconds\n";
    std::cout << "MIPS: " << comp2.calculateMIPS(progC) << "\n\n";

    // ✅ Computer 3 with Programs
    std::cout << "Computer 3 running Program A:\n";
    std::cout << "Execution Time: " << comp3.calculateExecutionTime(progA) << " seconds\n";
    std::cout << "MIPS: " << comp3.calculateMIPS(progA) << "\n\n";

    std::cout << "Computer 3 running Program B:\n";
    std::cout << "Execution Time: " << comp3.calculateExecutionTime(progB) << " seconds\n";
    std::cout << "MIPS: " << comp3.calculateMIPS(progB) << "\n\n";

    std::cout << "Computer 3 running Program C:\n";
    std::cout << "Execution Time: " << comp3.calculateExecutionTime(progC) << " seconds\n";
    std::cout << "MIPS: " << comp3.calculateMIPS(progC) << "\n\n";

    return 0;
}