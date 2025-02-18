#include "computer.h"
#include <iostream>

int main() {
    // Create two Computer objects with different specifications
    Computer comp1(3.5, 2.0, 3.0, 2.5, 1.8);
    Computer comp2(2.8, 2.2, 3.2, 2.6, 2.0);

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
