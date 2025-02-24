#ifndef _REGISTERS_H_
#define _REGISTERS_H_
#include <iostream>
class Registers
{
public:
	class Register{
		public:
			int regNum;
			int value;

			Register(int a = 0, int b = 0) : regNum(a), value(b) {}


			};
//private:
	//static const int totREGS = 31;
	Register reg[31];

//public:
	void fillRegs(){
		for (int i = 0; i < 31; i++) {
		reg[i] = Register(i,i);
		//std::cout << "iteration called:" << i << std::endl; 
		}	
	}
	void printRegnums(){
		for (int i = 0; i < 31; i++) {
		std::cout << reg[i].regNum << std::endl; 
		}	
	}


	//void setRegister(int regNum, int value);
	//int getRegister(int regNum);
	//void setPC(int value);
	//int getPC();
	//void print();


};

#endif	/* _REGISTERS_H_ */
