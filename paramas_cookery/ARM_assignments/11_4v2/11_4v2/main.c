#include "LPC13xx.h"
#include "delay.h"
static void init_led(){
    LPC_GPIO3->DIR =1;
    //*(volatile uint32_t *)0x50038000 = 1;
}

static void init_button(){
    //*(volatile uint32_t *)0x40044054 = 1; //PIO2.9
    //*(volatile uint32_t *)0x40044094 = 1;//PIO1.4
    LPC_GPIO2->DIR &= ~(1<<9);
    LPC_GPIO1->DIR &= ~(1<<4);
}

static void led_on(){
    LPC_GPIO3->DATA=0;
    //*(volatile uint32_t *)0x50033FFC = 0;
}
static void led_off(){
    LPC_GPIO3->DATA=1;
    //*(volatile uint32_t *)0x50033FFC = 1;
}

static int but1_pressed(){
    if((LPC_GPIO2->DATA &= (1<<9)) == (1<<9)){
        return 0;
    }
    else{
        return 1;
    }
}


int main (void)
{
    init_button();
    init_led();
    int memory = 0;

	while (1) {

        //if (but1_pressed() == 1 && memory == 0){
        //    memory = 1;
        //}
        //else if (but1_pressed() == 1 && memory == 1){
        //    memory = 0;
        //}
        //else if (but1_pressed() == 0 && memory  == 0) {
        //    memory = 0;
        //}
        //else if (but1_pressed() == 0 && memory  == 1){
        //    memory = 1;
        //}

        while(memory == 0){
            led_off();


                while(but1_pressed() ==1){
                   delay_ms(10);
                   memory = 1;
                }
        }
        while(memory == 1){
            led_on();


                while(but1_pressed() ==1){
                   delay_ms(10);
                   memory = 0;
                }
        }

    }
}
