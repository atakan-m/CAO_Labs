#include "LPC13xx.h"
#include "delay.h"
#include <stdlib.h>
static void init(){
    *(volatile uint32_t *)0x50038000 = 1;
}

static void led_off(){
    *(volatile uint32_t *)0x50033FFC = 1;
}

static void led_on(){
    *(volatile uint32_t *)0x50033FFC = 0;
}

int main (void)
{
init ();
	while (1) {
        //static void led_off(void);
        led_on();
        delay_ms(500);
        led_off();
        delay_ms(500);

	}
}
