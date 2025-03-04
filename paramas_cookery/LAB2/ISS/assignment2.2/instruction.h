#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include "registers.h"

using namespace std;

class Instruction{
public:
	int adress1;
	int adress2;
	int adress3;
	virtual void disassemble (){};
	virtual int execute (Registers*){
	return 0;
	};
	Instruction(int a = 0, int b = 0, int c = 0) : adress1(a), adress2(b), adress3(c) {
	}
	
	//why would we need a virtual instruction?
	virtual ~Instruction(){}
};

class AddInstruction : public Instruction{
	//do I need to initialize again
	AddInstruction(int adr1, int adr2, int adr3) : Instruction(adr1, adr2, adr3){}
	int execute (Registers *registor) {
		registor->setRegister(adress1, registor->getRegister(adress2) + registor->getRegister(adress3));
		int newPC = registor->getPC() + 1;
		registor->setPC(newPC);
		return newPC;
		}
	void dissasemble (){
		std::cout << "add" << "$" << adress1 << ", "<< "$" << adress2 << ", " << "$ "<< adress3 <<std::endl;
		}
};

class SubInstruction : public Instruction{
	SubInstruction(int adr1, int adr2, int adr3) : Instruction (adr1, adr2, adr3) {}
	int execute (Registers *registor) {
		registor->setRegister(adress1, registor->getRegister(adress2) - registor->getRegister(adress3));		
		int newPC = registor->getPC() + 1;
		registor->setPC(newPC);
		return newPC;
		}	
	void dissasemble (){
		std::cout << "sub" << "$" << adress1 << ", "<< "$" << adress2 << ", " << "$ "<< adress3 <<std::endl;
		}
};

class OriInstruction : public Instruction{
	OriInstruction(int adr1, int adr2, int adr3) : Instruction (adr1, adr2, adr3) {}
	int execute (Registers *registor) {
		registor->setRegister(adress1 ,registor->getRegister(adress2) || adress3);
		int newPC = registor->getPC() + 1;
		registor->setPC(newPC);
		return newPC;
		}	
	void dissasemble (){
		std::cout << "ori" << "$" << adress1 << ", "<< "$" << adress2 << ", " << "$ "<< adress3 <<std::endl;
		}
};

class BrneInstruction : public Instruction{
	BrneInstruction(int adr1, int adr2, int adr3) : Instruction (adr1, adr2, adr3) {}
	int execute (Registers *registor) {
		int Brne = 0;
		if (adress1 == adress2){
			Brne = registor->getPC() +1;
			registor->setPC(Brne);
		}
		else{
			Brne = registor->getPC() + 1 + -4;
			registor->setPC(Brne);
		}
		return Brne;

		}
	void dissasemble (){
		std::cout << "ori" << "$" << adress1 << ", "<< "$" << adress2 << ", " << "$ "<< adress3 <<std::endl;
		}
};



#endif /* _INSTRUCTION_H_ */
