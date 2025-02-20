#include "program.h"
#include <iostream>

Program::Program(int arith, int store, int load, int branch)
    : numArith(arith), numStore(store), numLoad(load), numBranch(branch) {
    numTotal = numArith + numStore + numLoad + numBranch;
}

Program::Program(int total, double fracArith, double fracStore, double fracLoad) {
    numArith = total * fracArith;
    numStore = total * fracStore;
    numLoad  = total * fracLoad;
    numBranch = total - (numArith + numStore + numLoad);
    numTotal = total;
}

int Program::getNumArith() const { return numArith; }
int Program::getNumStore() const { return numStore; }
int Program::getNumLoad() const { return numLoad; }
int Program::getNumBranch() const { return numBranch; }
int Program::getTotalInstructions() const { return numTotal; }

void Program::printStats() const {
    std::cout << "Arith: " << numArith << "\n"
              << "Store: " << numStore << "\n"
              << "Load: " << numLoad << "\n"
              << "Branch: " << numBranch << "\n"
              << "Total: " << numTotal << "\n";
}