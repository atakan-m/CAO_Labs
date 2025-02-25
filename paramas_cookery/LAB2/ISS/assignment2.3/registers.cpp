#include <iostream>
#include "registers.h"

using namespace std;


void Registers::setRegister(int a, int b){
		reg[a] = Register(a,b);
}

int Registers::getRegister(int a){
		return reg[a].value;
}


void Registers::setPC (int a){
		PC.counter = a;
}

int Registers::getPC(){
		return PC.counter;
}

void Registers::print(){
		for (int i = 0; i < 31; i++) {
		std::cout << "register: " << i << " has regNum: " 
		<< reg[i].regNum << " and value: "<< reg[i].value << std::endl; 
		}
		std::cout << "PC is at: " << PC.counter << std::endl;
}
