/*
===============================================================================
 Name        : Lab10.c
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

//Section 1.3
//ADC Sample Program
/*
void ADC_Power_Init(void)
{
	//Configure ADC Power Control Bit
	LPC_SC->PCONP |= (1<<12);
}

void ADC_Pin_Init(void)
{
	//Configure P0.23 to 01 - AD0.0 Function
	LPC_PINCON->PINSEL1 &= (~(1<<15));
	LPC_PINCON->PINSEL1 |= (1<<14);
	//Configure P0.23 to 10 - Neither pull-up nor pull-down
	LPC_PINCON->PINMODE1 |= (1<<15);
	LPC_PINCON->PINMODE1 &= (~(1<<14));
}

void ADC_Init(void)
{
	//Configure PCLK_ADC to 00 - CCLK/4 = 100M/4 = 25MHz
	LPC_SC->PCLKSEL0 &= (~(3<<24));
	//Configure AD0.0 to be sampled ad converted.
	LPC_ADC->ADCR |= (1<<0);
	//Configure ADC Clock Divider to 2 - 25MHz/2 - 12.5MHz
	//(=<13MHz);
	LPC_ADC->ADCR |= (1<<8);
	//Configure ADC to be in operational mode.
	LPC_ADC->ADCR |= (1<<21);
}

int main(void)
{
	int ADC_Value;

	ADC_Power_Init();
	ADC_Pin_Int();
	ADC_Init();
	while(1)
	{
		//Start ADC Conversion.
		LPC_ADC->ADCR |= (1<<24);
		//Wait for Conversion to complete.
		while(LPC_ADC->ADDR0 & (1<<31) == 0); //Polling Mode
		//Read ADC Value
		printf("ADC Value = %d\n", ADC_Value);
	}
    return 0 ;
}
*/

//Section 2.3
//DAC Sample Program
void DAC_Pin_Init(void)
{
	//Configure P0.26 to 10 - AOUT Function
	LPC_PINCON->PINSEL1 &= (~(1<<20));
	LPC_PINCON->PINSEL1 |= (1<<21);
	//Configure P0.26 to 10 - Neither pull-up nor pull-down
	LPC_PINCON->PINMODE1 |= (1<<21);
	LPC_PINCON->PINMODE1 &= (~(1<<20));
}

void DAC_Init(void)
{
	//Configure PCLK_DAC to 00 - CCLK/4 = 100/4 = 25MHz
	LPC_SC->PCLKSEL0 &= (~(3<<22));
	//16bit reload value for the DMA Timer
	LPC_DAC->DACCNTVAL = 0xFFFF;
	//Time-out counter operation enabled.
	LPC_DAC->DACCTRL |= (1<<2);
}

int main(void)
{
	DAC_Pin_Init();
	DAC_Init();
	while(1)
	{
		while((LPC_DAC->DACCNTVAL & (1<<0)) == 0);
		LPC_DAC->DACR = ((0 &0x3FF) << 6);
	}
	return 0;
}
