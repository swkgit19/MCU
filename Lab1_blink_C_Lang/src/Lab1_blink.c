/*
===============================================================================
 Name        : Lab1_blink.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here
void led2_init(void)
{
	LPC_PINCON->PINSEL1 &= (~(3 << 12));
	LPC_GPIO0->FIODIR |= (1 << 22);
}

void led2_on(void)
{
	LPC_GPIO0->FIOSET = (1 << 22);
}

void led2_off(void)
{
	LPC_GPIO0->FIOCLR = (1 << 22);
}


int main(void)
{
	int i;
	led2_init();
    while(1)
    {
        led2_on();
        for(i=0; i<50000; i++);
        led2_off();
        for(i=0; i<50000; i++);
    }
    return 0 ;
}
