#include "computer.h"
#include <iostream>

int main() {
    // 2 different computer specifications
    Computer comp1(4.5, 2.0, 3.0, 2.5, 2);
    Computer comp2(3, 2.5, 3.2, 2.6, 2.3);

    std::cout << "Computer 1:\n";
    comp1.printStats();
    std::cout << "Global CPI: " << comp1.calculateGlobalCPI() << "\n\n";

    std::cout << "Computer 2:\n";
    comp2.printStats();
    std::cout << "Global CPI: " << comp2.calculateGlobalCPI() << "\n";

    return 0;
}
