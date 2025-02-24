#ifndef COMPUTER_H
#define COMPUTER_H

#include "program.h"

class Computer {
private:
    double clockRateGHz;
    double cpiArith, cpiStore, cpiLoad, cpiBranch;

public:
    Computer(double, double, double, double, double);

    void printStats() ;
    
    double calculateGlobalCPI() ;
    double calculateExecutionTime(Program prog) ;
    double calculateMIPS() ;
    double calculateMIPS(Program prog) ;
};

#endif