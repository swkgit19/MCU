/*
===============================================================================
 Name        : Lab11_2_Zigbee.c
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
#include <string.h>

int CompleteDataReceivedFlag = 0;

void UART3_Power_Init(void)
{
	// Configure UART3 Power Control Bit.
	LPC_SC->PCONP			|= (1<<25);
}

void UART3_Pin_Init(void)
{
	// Configure P0.0 & P0.1 to 10 - TXD3 & RXD3
	LPC_PINCON->PINSEL0		&= (~(1<<0));
	LPC_PINCON->PINSEL0		|= (1<<1);
	LPC_PINCON->PINSEL0		&= (~(1<<2));
	LPC_PINCON->PINSEL0		|= (1<<3);
	// Configure P0.0 & P0.1 to 10 - Neither pull-up nor pull-down
	LPC_PINCON->PINMODE0 	&= (~(1<<0));
	LPC_PINCON->PINMODE0 	|= (1<<1);
	LPC_PINCON->PINMODE0 	&= (~(1<<2));
	LPC_PINCON->PINMODE0 	|= (1<<3);
}

void UART3_BaudRate_Init(void)
{
	// Configure PCLK_UART3 to 00 - CCLK/4 - 25MHz
	LPC_SC->PCLKSEL1 		&= (~(3<<18));
	// Configure Data Format: 8 bit Data, 1 Stop Bit, Parity None.
	LPC_UART3->LCR 			|= (3<<0);
	LPC_UART3->LCR 			&= (~(1<<2));
	LPC_UART3->LCR 			&= (~(1<<3));
	// Enable access to divisor latches - DLAB = 1
	LPC_UART3->LCR			|= (1<<7);
	// Configure Baud Rate to 9600bps
	LPC_UART3->DLL			= 108;
	LPC_UART3->DLM			= 0;
	LPC_UART3->FDR			= 0x21;
	// Disable access to divisor latches - DLAB = 0
	LPC_UART3->LCR			&= (~(1<<7));
}

void UART3_FIFOBuffer_Init(void)
{
	// Enable FIFO, Reset Rx FIFO and TX FIFO
	LPC_UART3->FCR			|= (1<<0)|(1<<1)|(1<<2);
}

void UART3_Interrupt_Init(void)
{
	NVIC_EnableIRQ(UART3_IRQn);
	LPC_UART3->IER 			|= (3<<0);
}

void UART3_DataTransmit(char * TxData, int DataSize)
{
	while(DataSize)
	{
		while((LPC_UART3->LSR & (1<<5)) == 0);
		LPC_UART3->THR		= *TxData;
		TxData++;
		DataSize--;
	}
}

void UART3_IRQHandler(void)
{
	char DataReceived = 0;
	if((LPC_UART3->IIR & 4) != 0)
	{
		while((LPC_UART3->LSR & (1<<0)) == 0);
		DataReceived = LPC_UART3->RBR;
		printf("%c", DataReceived);
		if(DataReceived == 0x0D)
		{
			CompleteDataReceivedFlag = 1;
		}
	}
}

int main(void)
{

	char TransmitData[50];
	UART3_Power_Init();
	UART33_Pin_Init();
	UART3_BaudRate_Init();
	UART3_FIFOBuffer_Init();
	UART3_Interrupt_Init();
	while(1)
	{
		CompleteDataReceivedFlag = 0;
		memset(TransmitData, 0, 50);
		printf("Enter Command:");
		gets(TransmitData);
		if(TransmitData[0] != '+');
		{
			TransmitData[strlen(TransmitData)] = 0x0D;
		}
		UART3_DataTransmit(TransmitData, strlen(TransmitData));
		printf("Command Response:");
		while(CompleteDataReceivedFlag == 0);
	}

    return 0 ;
}
