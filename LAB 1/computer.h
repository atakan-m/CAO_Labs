// computer.h - Header File
// This file contains the definition of the Computer class
// It includes private data members and public member functions

#ifndef COMPUTER_H
#define COMPUTER_H

// Define the Computer class
class Computer {
private:
    // Private data members (only accessible within the class)
    double cpuSpeed;   // CPU speed in GHz
    double ramSize;    // RAM size in GB
    double storage;    // Storage size in GB
    double screenSize; // Screen size in inches
    double weight;     // Weight of the computer in kg
    int numArith;      // Number of arithmetic instructions
    int numStore;      // Number of store instructions
    int numLoad;       // Number of load instructions
    int numBranch;     // Number of branch instructions
    int numTotal;      // Total number of instructions

public:
    // Constructor to initialize all attributes
    Computer(double, double, double, double, double, int, int, int, int);
    
    // Member function to print statistics of the computer
    void printStats() const;
    
    // Member function to calculate the global CPI
    double calculateGlobalCPI() const;
};

#endif // COMPUTER_H
