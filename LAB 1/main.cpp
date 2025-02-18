    #include "computer.h"
    #include "program.h"
    #include <iostream>

    int main() {
        // 2 different computer specifications
        Computer comp1(1, 2, 3, 3, 4);
        Computer comp2(1.2, 2, 3, 4, 3);
        Computer comp3(2, 2, 2, 4, 6);

        Program prog1(2000, 100, 100, 50);
        Program prog2(0.1, 0.4, .25, 2.4);
        Program prog3(500, 100, 2000, 200);
        

        std::cout << "Computer 1:" << std::endl;
        comp1.printStats();
        std::cout << "Global CPI: " << comp1.calculateGlobalCPI() << "\n\n";

        std::cout << "Computer 2" << std::endl;
        comp2.printStats();
        std::cout << "Global CPI: " << comp2.calculateGlobalCPI() << "\n\n";

        std::cout << "Computer 2" << std::endl;
        comp3.printStats();
        std::cout << "Global CPI: " << comp3.calculateGlobalCPI() << "\n\n";

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
