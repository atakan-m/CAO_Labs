#include "program.h"


class Computer {
private:
    
    double clockRateGHz; // Clock rate in GHz
    double cpiArith;     // CPI of arithmetic instructions
    double cpiStore;     // CPI of store instructions
    double cpiLoad;      // CPI of load instructions
    double cpiBranch;    // CPI of branch instructions

public:
    Computer(double, double, double, double, double);
    
    void printStats() ;
    
    double calculateGlobalCPI() ;

    double calculateExecutionTime(Program);
};
