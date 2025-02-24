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
	Register reg[31];


	void setRegister(int a, int b){
		reg[a] = Register(a,b);
		
	}

	int getRegister(int a){
		return reg[a].value;
	}

	class ProgramCounter{
		public: 
			int counter;
	};

	ProgramCounter PC;

	void setPC (int a){
		PC.counter = a;
	}

	int getPC(){
		return PC.counter;
	}

	void print(){
		for (int i = 0; i < 31; i++) {
		std::cout << "register: " << i << " has regNum: " 
		<< reg[i].regNum << " and value: "<< reg[i].value << std::endl; 
		}
		std::cout << "PC is at: " << PC.counter << std::endl;
	}


	//int getRegister(int regNum);
	//void setPC(int value);
	//int getPC();
	//void print();


};

#endif	/* _REGISTERS_H_ */
