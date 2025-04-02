#include "LPC13xx.h"
#include "leddriver.h"
void init (void){
    LPC_GPIO1->DIR |= (1<<4); //SDA pin
    LPC_GPIO1->DIR |= (1<<5); //SCL pin
    LPC_IOCON -> PIO0_4 = 0x1; //table 107
    LPC_IOCON -> PIO0_5 = 0x1;; //table 108
    LPC_SYSCON -> SYSAHBCLKCTRL |= (1<<5); // table 25
    LPC_SYSCON -> PRESETCTRL |= (1<<1); //table 9
    //clock help
    LPC_I2C->SCLH = 360;
    LPC_I2C->SCLL = 360;
    LPC_I2C ->CONSET = (1<<6);
    NVIC_EnableIRQ(I2C_IRQn);
}

void I2C_Handler(void){

    switch (LPC_I2C->STAT) {
      case 0x08:
        LPC_I2C->DAT = 0x90; //write
        LPC_I2C ->CONCLR = (1<<3);
        LPC_I2C ->CONCLR = (1<<5);
        //LPC_I2C->STAT = 0x18;
        break;
      case 0x18:
        LPC_I2C->DAT = 0;
        LPC_I2C ->CONCLR = (1<<3);
        //LPC_I2C->STAT = 0x28;
        break;
      case 0x28:
        LPC_I2C ->CONSET = (1<<5);
        LPC_I2C ->CONCLR = (1<<3);
        //LPC_I2C->STAT = 0x10;
        break;
      case 0x10:
        LPC_I2C->DAT = 0x91; //read
        LPC_I2C ->CONCLR = (1<<3);
        LPC_I2C ->CONCLR = (1<<5);
         //   LPC_I2C->STAT = 0x40;
        break;
      case 0x40:
        LPC_I2C ->CONCLR = (1<<2);
        LPC_I2C ->CONCLR = (1<<3);
        //LPC_I2C->STAT = 0x58;
        break;
      case 0x58:
        set_leds(LPC_I2C->DAT);
        LPC_I2C ->CONSET = (1<<5);
        LPC_I2C ->CONCLR = (1<<3);
        //LPC_I2C->STAT = 0x28;

        break;

    }

}


int main (void)
{
    init_leds();
    init();
    LPC_I2C ->CONSET = (1<<5);
    LPC_I2C ->CONCLR = (1<<3);
	while (1) {
    __WFI();
	}
}
