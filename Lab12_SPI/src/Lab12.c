/*
===============================================================================
 Name        : Lab12.c
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

void SSP1_Power_Init(void)
{
	//Configure SSP1 Power Control Bit.
	LPC_SC->PCONP |= (1<<10);
}

void SSP1_Pin_Init(void)
{
	//Configure P0.7, P0.8, P0.9 to 10 - SCK1, MISO1, MOSI1
	//Function
	//Configure P2.2 to 00 - GPIO Function
	LPC_PINCON->PINSEL0 &= (~(1<<14));
	LPC_PINCON->PINSEL0 |= (1<<15);
	LPC_PINCON->PINSEL0 &= (~(1<<16));
	LPC_PINCON->PINSEL0 |= (1<<17);
	LPC_PINCON->PINSEL0 &= (~(1<<18));
	LPC_PINCON->PINSEL0 |= (1<<19);
	LPC_PINCON->PINSEL0 &= (~(3<<4));
	//Configure P0.7, P0.8, P0.9 & P2.2 to 00 - Enable on-chip
	//pull-up resistor function
	LPC_PINCON->PINMODE0 &= (~(3<<14));
	LPC_PINCON->PINMODE0 &= (~(3<<16));
	LPC_PINCON->PINMODE0 &= (~(3<<18));
	LPC_PINCON->PINMODE4 &= (~(3<<4));
	//Configure P2.2 to 1 - Output
	LPC_GPIO2->FIODIR |= (1<<2);
	//Configure P2.2 to 0 - Disable Pin Masking.
	LPC_GPIO2->FIOMASK &= (~(1<<2));
}

void SSP1_Clock_Init(void)
{
	//Configure PCLK to 10 - CCLK/2 - 50MHz
	LPC_SC->PCLKSEL0 &= (~(1<<20));
	LPC_SC->PCLKSEL0 |= (1<<21);
	//Configure SCL to 5MHz  PCLK/10 - 5MhHz
	LPC_SSP1->CPSR = 2;
	LPC_SSP1->CR0 |= (4<<8);
}

void SSP1_Init(void)
{
	//Configure SSP1: DataSize=8, FrameFormat=SPI, CPOL=0, CPHA=0
	LPC_SSP1->CR0 |= (7<<0);
	LPC_SSP1->CR0 &= (~(3<<4));
	LPC_SSP1->CR0 &= (~(1<<6));
	LPC_SSP1->CR0 &= (~(1<<7));
	//Configure SSP1: Master Mode & Enable SSP1
	LPC_SSP1->CR1 &= (~(1<<2));
	LPC_SSP1->CR1 |= (1<<1);
}

void SSP1_EnableDisable_CS(int EnableDisable)
{
	if(EnableDisable == 1)
		//Configure FIOCLR(P2.2) to 1 - Output Low Logic
		LPC_GPIO2->FIOCLR |= (1<<2);
	if(EnableDisable == 0)
		//Configure FIOSET(P2.2) to 1 - Output High Logic
		LPC_GPIO2->FIOSET |= (1<<2);
}

void SSP1_SendData(int Data)
{
	//Check if Tx FIFO is full
	while((LPC_SSP1->SR & (1<<1)) == 0);
	//Send Data
	LPC_SSP1->DR = Data;
	//Check if Rx FIFO is not empty
	while((LPC_SSP1->SR & (1<<2)) == 0);
	//Receive Data
	LPC_SSP1->DR;
}

int SSP1_ReceiveData()
{
	//Check if Tx FIFO is full
	while((LPC_SSP1->SR & (1<<1)) == 0);
	//Send Data
	LPC_SSP1->DR = 0xFF;
	//Check if Rx FIFO is not empty
	while((LPC_SSP1->SR & (1<<2)) == 0);
	//Receive Data
	return (LPC_SSP1->DR);
}

int main(void)
{

    int i = 0;
    int DeviceID[4];

    SSP1_Power_Init();
    SSP1_Pin_Init();
    SSP1_Clock_Init();
    SSP1_Init();

    while(1)
    {
    	SSP1_EnableDisable_CS(1);
    	SSP1_SendData(0x9F);
    	for(i=0; i<4; i++)
    	{
    		DeviceID[i] = SSP1_ReceiveData();
    	}
    	SSP1_EnableDisable_CS(0);
    	for(i=0; i<4; i++)
    	{
    		printf("Device ID is %x\n", DeviceID[i]);
    	}
    }
    return 0 ;
}
