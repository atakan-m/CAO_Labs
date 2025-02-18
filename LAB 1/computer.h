// computer.h - Header File
// This file contains the definition of the Computer class

#ifndef COMPUTER_H
#define COMPUTER_H

// Define the Computer class
class Computer {
private:
    // Private data members (only accessible within the class)
    double clockRateGHz; // Clock rate in GHz
    double cpiArith;     // CPI of arithmetic instructions
    double cpiStore;     // CPI of store instructions
    double cpiLoad;      // CPI of load instructions
    double cpiBranch;    // CPI of branch instructions

public:
    // Constructor to initialize all attributes
    Computer(double, double, double, double, double);
    
    // Member function to print statistics of the computer
    void printStats() const;
    
    // Member function to calculate the global CPI
    double calculateGlobalCPI() const;
};

#endif // COMPUTER_H
