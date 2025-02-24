#ifndef PROGRAM_H
#define PROGRAM_H

class Program {
private:
    int numArith, numStore, numLoad, numBranch, numTotal;

public:
    // Constructor for direct instruction counts
    Program(int, int, int, int);
    // Overloaded constructor: total instructions and fractions for arith, store, load (branch is remainder)
    Program(int, double, double, double);

    int getNumArith() ;
    int getNumStore() ;
    int getNumLoad() ;
    int getNumBranch() ;
    int getTotalInstructions() ;

    void printStats() ;
};

#endif
