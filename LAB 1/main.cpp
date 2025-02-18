#include "computer.h"
#include "program.h"
#include <iostream>

int main() {
    // 3 different computer specifications
    Computer comp1(1, 2, 3, 3, 4);
    Computer comp2(1.2, 2, 3, 4, 3);
    Computer comp3(2, 2, 4, 6, 6);

    Program prog1(2000, 100, 100, 50);
    Program prog2(200, 800, 500, 500);
    Program prog3(500, 100, 2000, 200);

    std::cout << "Computer 1:" << std::endl;
    comp1.printStats();
    std::cout << "Global CPI: " << comp1.calculateGlobalCPI() << "\n";
    std::cout << "Mips Prog 1: " << comp1.calculateMIPS(prog1) <<"\n";
    std::cout << "Mips Prog 2: " << comp1.calculateMIPS(prog2) <<"\n";
    std::cout << "Mips Prog 3: " << comp1.calculateMIPS(prog3) <<"\n";
    std::cout << "Mips Specific 1: " << comp1.calculateMIPSSpecific(prog1) <<"\n";
    std::cout << "Execution time Comp 1: " << comp1.calculateExecutionTime(prog1) << " Seconds" "\n\n";
    

    std::cout << "Computer 2:" << std::endl;
    comp2.printStats();
    std::cout << "Global CPI: " << comp2.calculateGlobalCPI() << "\n";
    std::cout << "Mips Prog 1: " << comp2.calculateMIPS(prog1) <<"\n";
    std::cout << "Mips Prog 2: " << comp2.calculateMIPS(prog2) <<"\n";
    std::cout << "Mips Prog 3: " << comp2.calculateMIPS(prog3) <<"\n";
    std::cout << "Mips Specific 1: " << comp2.calculateMIPSSpecific(prog1) <<"\n";
    std::cout << "Execution time Comp 1: " << comp2.calculateExecutionTime(prog1) << " Seconds" "\n\n";

    std::cout << "Computer 3:" << std::endl;
    comp3.printStats();
    std::cout << "Global CPI: " << comp3.calculateGlobalCPI() << "\n";
    std::cout << "Mips Prog 1: " << comp3.calculateMIPS(prog1) <<"\n";
    std::cout << "Mips Prog 2: " << comp3.calculateMIPS(prog2) <<"\n";
    std::cout << "Mips Prog 3: " << comp3.calculateMIPS(prog3) <<"\n";
    std::cout << "Mips Specific 1: " << comp3.calculateMIPSSpecific(prog1) <<"\n";
    std::cout << "Execution time Comp 1: " << comp3.calculateExecutionTime(prog1) << " Seconds" "\n\n";
    
    std::cout << "Program 1:\n";
    std::cout << "NumTotal: " << prog1.calculateNumTotal() << "\n";
    std::cout << "OverloadedNumTotal: " << prog1.calculateNumTotaldouble() << "\n\n";

    std::cout << "Program 2:\n";
    std::cout << "NumTotal: " << prog2.calculateNumTotal() << "\n";
    std::cout << "OverloadedNumTotal: " << prog2.calculateNumTotaldouble() << "\n\n";

    return 0;
    }
