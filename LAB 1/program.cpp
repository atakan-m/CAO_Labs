#include "program.h"
#include <iostream>

Program::Program(int numArith, int numStore, int numLoad, int numBranch)
    : numArith(numArith), numStore(numStore), numLoad(numLoad), numBranch(numBranch) {}
    
Program::Program(int numArith, double numStore, double numLoad, double numBranch)
    : numArith(numArith), numStore(numStore), numLoad(numLoad), numBranch(numBranch) {}

    
void Program::printStats(){
    std::cout << "Arith: " << numArith << " \n";
    std::cout << "Store: " << numStore << "\n";
    std::cout << "Load: " << numLoad << "\n";
    std::cout << "Branch: " << numBranch << "\n";
}

int Program::calculateNumTotal(){
    return ( numArith+  numStore+ numLoad  + numBranch ); //  Calculation
}

double Program::calculateNumTotaldouble(){
    return ( numArith+  numStore+ numLoad  + numBranch ); //  Calculation
}


