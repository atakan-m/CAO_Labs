#ifndef PROGRAM_H
#define PROGRAM_H


class Program {
    private:
        
        double numArith; // Clock rate in GHz
        double numStore;     // CPI of arithmetic instructions
        double numLoad;     // CPI of store instructions
        double numBranch;      // CPI of load instructions
        double numTotal;    // CPI of branch instructions
    
    public:
        Program(int, int, int, int);

        Program(int, double, double, double);

        double calculateNumTotaldouble(); 

        int getnumArith() ;

        int getnumStore() ;

        int getnumLoad() ;

        int getnumBranch() ;
        
        void printStats() ;
        
        int calculateNumTotal() ;


    };
 #endif