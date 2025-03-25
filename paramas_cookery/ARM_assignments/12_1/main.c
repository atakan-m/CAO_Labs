#include "LPC13xx.h"
void init_timer(void){
    LPC_TMR32B0->TCR = 0;
    LPC_TMR32B0->TC = 0;
    LPC_TMR32B0->PR = 0;
    LPC_TMR32B0->PC = 0;
    LPC_TMR32B0->MR0 = 0;
    LPC_TMR32BO->MR3 = 0;
    LPC_TMR32B0->MCR = 0;
}
void init_port(void){
        LPC_GPIO1->DIR &= ~(1<<6);
}

void pin_low (void){
}
void pin_high (void){
}
void timer_start (void){
}
void timer_stop (void){
}


int main (void)
{
	while (1) { }
}
