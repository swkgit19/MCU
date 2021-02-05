/*
===============================================================================
 Name        : Lab11.c
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

void UART3_Power_Init(Void)
{
	//Configure UART3 Power Control Bit.
	LPC_SC->PCONP |= (1 << 25);
}

void UART3_Pin_Init(Void)
{
	//Configure P0.0 & P0.1 to 10 - TXD3 & RXD3
	LPC_PINCON->PINSEL0 		&= (~(1<<0));
	LPC_PINCON->PINSEL0 		|= (1<<1);
	LPC_PINCON->PINSEL0 		&= (~(1<<2));
	LPC_PINCON->PINSEL0 		|= (1<<3);

	//Configure P0.0 & P0.1 to 10 - Neither pull-up nor pull-down
	LPC_PINCON->PINMODE0 		&= (~(1<<0));
	LPC_PINCON->PINMODE0 		|= (1<<1);
	LPC_PINCON->PINMODE0 		&= (~(1<<2));
	LPC_PINCON->PINMODE0 		&= (1<<3);
}

void UART3_BandRate_Init(Void)
{
	//Configure PCLK_UART3 to 00 - CCLK/4 - 25MHz
	LPC_SC->PCLKSEL1 &= (~(3<<18));
	//Configure Data Format: 8 bit Data, 1 Stop Bit, Parity None.
	LPC_UART3->LCR |= (3<<0);
	LPC_UART3->LCR &= (~(1<<2));
	LPC_UART3->LCR &= (~(1<<3));
	//Enable access to divisor latches - DLAB  = 1
	LPC_UART3->LCR |= (1<<7);
	//Configure Band Rate to 115200bps
	LPC_UART3->DLL = 9;
	LPC_UART3->DLM = 0;
	LPC_UART3->FDR = 0x21;
	//Disable access to divisor latches - DLAB = 0
	LPC_UART3->LCR &= (~(1<<7));
}

void UART3_FIFOBuffer_Init(Void)
{
	//Enable FIFO, Reset Rx FIFO and Tx FIFO
	LPC_UART3->FCR |= (1<<0) | (1<<1) | (1<<2);
}

void UART3_Interrupt_Init(Void)
{
	NVIC_EnableIRQ(UART3_IRQn);
	LPC_UART3->IER |= (3<<0);
}

void UART3_DataTransmit(char * TxData, int DataSize)
{
	while(DataSize)
	{
		while((LPC_UART3->LSR & (1<<5)) == 0);
		LPC_UART3->THR = *TxData;
		TxData++;
		DataSize--;
	}
}

void UART3_IRQHandler(void)
{
	if(LPC_UART3->IIR & (1<<0) == 0);
	printf("%c", LPC_UART3->RBR);
}

int main(void)
{
	char TransmitData[] = "How are you?\r\n";
	UART3_Power_Init();
	UART3_Pin_Init();
	UART3_BandRate_Init();
	UART3_FIFOBuffer_Init();
	UART3_Interrupt_Init();
	UART3_DataTransmit(TransmitData, sizeof(TransmitData));
	while(1);

    return 0 ;
}
