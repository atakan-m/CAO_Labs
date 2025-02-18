#include "computer.h"
#include <iostream>

int main() {
    // Create two Computer objects with different specifications
    Computer comp1(3.5, 16, 512, 15.6, 2.1, 200, 150, 300, 100);
    Computer comp2(2.8, 8, 256, 14.0, 1.8, 180, 120, 280, 90);

    // Print stats and calculate Global CPI for first computer
    std::cout << "Computer 1:\n";
    comp1.printStats();
    std::cout << "Global CPI: " << comp1.calculateGlobalCPI() << "\n\n";

    // Print stats and calculate Global CPI for second computer
    std::cout << "Computer 2:\n";
    comp2.printStats();
    std::cout << "Global CPI: " << comp2.calculateGlobalCPI() << "\n";

    return 0;
}