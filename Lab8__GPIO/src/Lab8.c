/*
===============================================================================
 Name        : Lab8.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <stdio.h>


//Section 3.2.2
void Led2_Power_Init(void)
{
	//Configure GPIO Power Control Bit.
	LPC_SC->PCONP |= (1<<15);
}

void Led2_Pin_Init(void)
{
	//Configure P0.22 to 00 - GPIO Function
	LPC_PINCON->PINSEL1 &= (~(3<<12));
	//Configure P0.22 to 1 - Output
	LPC_GPIO0->FIODIR |= (1<<22);
	//Configure P0.22 to 0 - Disable Pin Masking
	LPC_GPIO0->FIOMASK &= (~(1<<22));
}

void Led2_Pin_Output(int OutputBit)
{
	if(OutputBit == 1)
		//Configure FIOSET(P0.22) to 1 - Output High Logic
		LPC_GPIO0->FIOSET |= (1<<22);
	if(OutputBit == 0)
		//Configure FIOCLR(P0.22) to 1 - Output Low Logic
		LPC_GPIO0->FIOCLR |= (1<<22);
}


int main(void)
{
	int i;
	Led2_Power_Init();
	Led2_Pin_Init();
	//Led2_Pin_Output(0);
	while(1)
	{
		//Turn "ON" LED2
		Led2_Pin_Output(1);
		//Delay Program
		for(i=0; i<1000000; i++);
		//Turn "OFF" LED2
		Led2_Pin_Output(0);
		for(i=0; i<1000000; i++);
	}

    return 0 ;
}


//Section 3.3.2
//Push Button Sample Program
/*
void SW4_Power_Init(void)
{
	//Configure GPIO Power Control Bit
	LPC_SC->PCONP |= (1<<15);
}

void SW4_Pin_Init(void)
{
	//Configure P1.31 to 00 - GPIO Function
	LPC_PINCON->PINSEL3 &= (~(3<<30));
	//Configure P1.31 to 0 - Input
	LPC_GPIO1->FIODIR &= (~(1<<31));
	//Configure P1.31 to 0 - Disable Pin Masking
	LPC_GPIO1->FIOMASK &= (~(1<<31));
	//Configure P1.31 to 00 - Enable On-Chip Pull-Up Resistor
	LPC_PINCON->PINMODE3 &= (~(3<<30));
}

int SW4_PIN_Input(void)
{
	//Return the input data from P1.31
	return ((LPC_GPIO1->FIOPIN & (1<<31)) >> 31);
}

int main(void)
{
	SW4_Power_Init();
	SW4_Pin_Init();
	while(1)
	{
		//Read Data from SW4
		printf("Input data is %d\n", SW4_PIN_Input());
	}
	return 0;
}

 */


//Section 4.3
//External Interrupt Sample Program
