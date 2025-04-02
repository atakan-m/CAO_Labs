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
}


int main (void)
{
    init_leds();
    init();

    LPC_I2C ->CONSET = (1<<5);
    LPC_I2C ->CONCLR = (1<<3); //table 224
    while((LPC_I2C ->CONSET & (1<<3)) == 0){
        //set_leds(1);
    }
    LPC_I2C->DAT = 0x90; //write
    LPC_I2C ->CONCLR = (1<<3);
    LPC_I2C ->CONCLR = (1<<5);

    while((LPC_I2C ->CONSET & (1<<3)) == 0){
    }
    LPC_I2C->DAT = 0;
    LPC_I2C ->CONCLR = (1<<3);
    while((LPC_I2C ->CONSET & (1<<3)) == 0){
    }
	while (1) {
        LPC_I2C ->CONSET = (1<<5);
        LPC_I2C ->CONCLR = (1<<3);
        while((LPC_I2C ->CONSET & (1<<3)) == 0){
        }
        LPC_I2C->DAT = 0x91; //read
        LPC_I2C ->CONCLR = (1<<3);
        LPC_I2C ->CONCLR = (1<<5);
        while((LPC_I2C ->CONSET & (1<<3)) == 0){
        }
        LPC_I2C ->CONCLR = (1<<2);
        LPC_I2C ->CONCLR = (1<<3);
        while((LPC_I2C ->CONSET & (1<<3)) == 0){
        }
        set_leds(LPC_I2C->DAT );

	}
}
