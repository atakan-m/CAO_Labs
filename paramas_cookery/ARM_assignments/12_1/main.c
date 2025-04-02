#include "LPC13xx.h"
void pin_low (void){
    LPC_GPIO1->DATA &= ~(1<<6);
}
void pin_high (void){
    LPC_GPIO1->DATA |= (1<<6);
}
void timer_start (void){
    //LPC_TMR32B0-> TCR &= ~(1<<0);
    //LPC_TMR32B0-> TCR |= (1<<1);
    LPC_TMR32B0-> TCR = (0<<1)|(1<<0);
}
void timer_stop (void){
    //LPC_TMR32B0-> TCR |= (1<<0);
    //LPC_TMR32B0-> TCR &= ~(1<<1);
    LPC_TMR32B0-> TCR = (1<<1)|(0<<0);

}
void init_timer(void){
    int dt = 800;
    int T = 1000;

    LPC_SYSCON-> SYSAHBCLKCTRL |= (1<<9);

    LPC_TMR32B0->PR = 720;
    LPC_TMR32B0->MR0 = dt;
    LPC_TMR32B0->MR3 = T;
    LPC_TMR32B0->MCR |= (1<<9);
    LPC_TMR32B0->MCR |= (1<<10);
    LPC_TMR32B0->MCR |= (1<<0);
    NVIC_EnableIRQ(TIMER_32_0_IRQn);
}
void init_port(void){
        LPC_GPIO1->DIR |= (1<<6);
}

void TIMER_32_0_Handler(void){
        while ((LPC_TMR32B0->IR & ((1<<0)|(1<<3))) == 0) {
            }
        if((LPC_TMR32B0->IR &= (1<<3)) == (1<<3)){
            pin_high();
            LPC_TMR32B0->IR = (1<<3); //clear flag
        }
        else if((LPC_TMR32B0->IR &= (1<<0)) == (1<<0)){
             pin_low();
             LPC_TMR32B0->IR = (1<<0); //clear flag
        }
}




int main (void)
{
    init_port();
    init_timer();
    timer_start();
    pin_high();
	while (1) {

        //while ((LPC_TMR32B0->IR & ((1<<0)|(1<<3))) == 0) {
        //    }
        //if((LPC_TMR32B0->IR &= (1<<3)) == (1<<3)){
        //    pin_high();
        //    LPC_TMR32B0->IR = (1<<3); //clear flag
        //}
        //else if((LPC_TMR32B0->IR &= (1<<0)) == (1<<0)){
        //     pin_low();
        //     LPC_TMR32B0->IR = (1<<0); //clear flag
        //}
    __WFI();
	}
}


//while (((LPC_TMR32B0->IR &= (1<<0)) != (1<<0)) | ((LPC_TMR32B0->IR &= (1<<3)) != (1<<3))) {
  //      }
