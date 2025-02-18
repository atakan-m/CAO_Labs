// computer.cpp - Implementation File
// This file implements the functions of the Computer class

#include "computer.h"
#include <iostream>

// Constructor: initializes all member variables
Computer::Computer(double cpu, double ram, double storage, double screen, double weight, int arith, int store, int load, int branch)
    : cpuSpeed(cpu), ramSize(ram), storage(storage), screenSize(screen), weight(weight),
      numArith(arith), numStore(store), numLoad(load), numBranch(branch) {
    numTotal = numArith + numStore + numLoad + numBranch; // Compute total instructions
}

// Function to print all attributes of the Computer object
void Computer::printStats() const {
    std::cout << "CPU Speed: " << cpuSpeed << " GHz\n";
    std::cout << "RAM Size: " << ramSize << " GB\n";
    std::cout << "Storage: " << storage << " GB\n";
    std::cout << "Screen Size: " << screenSize << " inches\n";
    std::cout << "Weight: " << weight << " kg\n";
    std::cout << "Arithmetic Instructions: " << numArith << "\n";
    std::cout << "Store Instructions: " << numStore << "\n";
    std::cout << "Load Instructions: " << numLoad << "\n";
    std::cout << "Branch Instructions: " << numBranch << "\n";
    std::cout << "Total Instructions: " << numTotal << "\n";
}

// Function to calculate the Global CPI (Cycles Per Instruction)
double Computer::calculateGlobalCPI() const {
    return static_cast<double>(numTotal) / 4; // Example calculation (change as needed)
}
