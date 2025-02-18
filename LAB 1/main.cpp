    #include "computer.h"
    #include "program.h"
    #include <iostream>

    int main() {
        // 2 different computer specifications
        Computer comp1(4.5, 2.0, 3.0, 2.5,3.7);
        Computer comp2(3, 2.5, 3.2, 2.6, 2.3);

        Program prog1(4, 2, 3, 2);
        Program prog2(3, 2.4, 3.5, 2.4);

        std::cout << "Computer 1:" << std::endl;
        comp1.printStats();
        std::cout << "Global CPI: " << comp1.calculateGlobalCPI() << "\n\n";

        std::cout << "Computer 2" << std::endl;
        comp2.printStats();
        std::cout << "Global CPI: " << comp2.calculateGlobalCPI() << "\n\n";

        std::cout << "Program 1:\n";
        prog1.printStats();
        std::cout << "NumTotal: " << prog1.calculateNumTotal()<< "\n";
        std::cout << "OverloadedNumTotal: " << prog1.calculateNumTotaldouble() << "\n""\n";


        std::cout << "Program 2:\n";
        prog2.printStats();
        std::cout << "NumTotal: " << prog2.calculateNumTotal()<< "\n";
        std::cout << "OverloadedNumTotal: " << prog2.calculateNumTotaldouble() << "\n""\n";

        
        return 0;
    }
