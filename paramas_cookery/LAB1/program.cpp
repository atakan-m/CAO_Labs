#include "program.h"
#include <iostream>

//Program::Program(int arith, int store, int load, int branch){
//    numTotal = numArith + numStore + numLoad + numBranch;
//}

Program::Program(int total, double fracArith, double fracStore, double fracLoad) {
    numArith = total * fracArith;
    numStore = total * fracStore;
    numLoad  = total * fracLoad;
    numBranch = total - (numArith + numStore + numLoad); // calculations for branch toatl
    numTotal = total;
}

int Program::getNumArith() { return numArith; }
int Program::getNumStore() { return numStore; }
int Program::getNumLoad() { return numLoad; }
int Program::getNumBranch() { return numBranch; }
int Program::getTotalInstructions() { return numTotal; }

void Program::printStats()  {
    std::cout << "Arith: " << numArith << "\n"
              << "Store: " << numStore << "\n"
              << "Load: " << numLoad << "\n"
              << "Branch: " << numBranch << "\n"
              << "Total: " << numTotal << "\n";
}
