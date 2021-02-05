/*
===============================================================================
 Name        : Lab14.c
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
#include <string.h>

int StartComplete = 0;
int AddressByteAckComplete = 0;
int DataByteAckComplete = 0;
int RepeatStartComplete = 0;
int DataByteReceiveAckComplete = 0;
int DataByteReceiveNotAckComplete = 0;

void I2C2_Power_Init(void)
{
	//Configure I2C2 Power Control Bit.
	LPC_SC->PCONP |= (1<<26);
}

void I2C2_Pin_Init(void)
{
	//COnfigure P0.10 & P0.11 to 10 - SDA2 & SCL2
	LPC_PINCON->PINSEL0 	&= (~(1<<20));
	LPC_PINCON->PINSEL0 	|= (1<<21);
	LPC_PINCON->PINSEL0 	&= (~(1<<22));
	LPC_PINCON->PINSEL0 	&= (1<<23);
	//Configure P0.10 & P0.11 to 10 Neither pull-up nor pull-down
	LPC_PINCON->PINMODE0	&= (~(1<<20));
	LPC_PINCON->PINMODE0	|= (1<<21);
	LPC_PINCON->PINMODE0	&= (~(1<<22));
	LPC_PINCON->PINMODE0	|= (1<<23);
	//Configure P0.10 & P0.11 to 1- Open drain mode.
	LPC_PINCON->PINMODE_OD0 |= (3<<10);
}

void I2C2_Clock_Init(void)
{
	//Configure I2C2 Core Clock Rate to CCLK/2 - 50MHz
	LPC_SC->PCLKSEL1 		&= (~(1<<20));
	LPC_SC->PCLKSEL1 		|= (1<<21);
	//Configure SCL Clock Rate to 100khz
	LPC_I2C2->I2SCLH 		= 250;
	LPC_I2C2->I2SCLL 		= 250;
}

void I2C2_MasterTxRx_Init(void)
{
	//Configure I2C2 to Master Transmit/Receive Mode
	LPC_I2C2->I2CONSET = (1<<6);
	//Enable I2C2 Interrupt
	NVIC_EnableIRQ(I2C2_IRQn);
}

void I2C2_Start(void)
{
	//Configure START Flag to 1
	LPC_I2C2->I2CONSET = (1<<5);
}

void I2C2_Stop(void)
{
	//Configure STOP Flag to 1
	LPC_I2C2->I2CONSET = (1<<4);
}

void I2C2_SendAddressByte(int AddressByte)
{
	//Send Address Byte
	LPC_I2C2->I2DAT = AddressByte;
}

void I2C2_SendDataByte(int DataByte)
{
	//Send Data Byte
	LPC_I2C2->I2DAT = DataByte;
}

void I2C2_GetDataByte(int Ack)
{
	if(Ack == 1)
	{
		//Configure Acknowledgment Flag to 1
		LPC_I2C2->I2CONSET = (1<<2);
	}
	else
	{
		//Configure Acknowledgment Flag to 0
		LPC_I2C2->I2CONCLR = (1<<2);
	}
}

void I2C2_IRQHandler(void)
{
	//Check Start Condition
	if(LPC_I2C2->I2STAT == 0x08)
	{
		//Configure START Flag to 0
		LPC_I2C2->I2CONCLR = (1<<5);
		//Indicate START Condition Complete
		StartComplete = 1;
	}
	//Check Repeat Start Condition
	if(LPC_I2C2->I2STAT == 0x10)
	{
		//Configure START Flag to 0
		LPC_I2C2->I2CONCLR = (1<<5);
		//Indicate START Condition Complete
		RepeatStartComplete = 1;
	}
	//Check AddressByteAck Condition
	if((LPC_I2C2->I2STAT == 0x18) || (LPC_I2C2->I2STAT == 0x40))
	{
		//Indicate AddressByteAck Condition Complete
		AddressByteAckComplete = 1;
	}
	//Check DataByteAck Condition
	if(LPC_I2C2->I2STAT == 0x28)
	{
		//Indicate DataByteAck Condition Complete
		DataByteAckComplete = 1;
	}
	//Check DataByteReceiveAck Condition
	if(LPC_I2C2->I2STAT == 0x50)
	{
		//Indicate DataByteReceiveAck Condition Complete
		DataByteReceiveAckComplete = 1;
	}
	//Check DataByteReceiveNotAck Condition
	if(LPC_I2C2->I2STAT == 0x58)
	{
		//Indicate DataByteReceiveNotAck Condition Complete
		DataByteReceiveNotAckComplete = 1;
	}
	//Clear Interrupt
	LPC_I2C2->I2CONCLR = (1<<3);
}


int main(void)
{
	int i;
	int DataWrite[5] = {0xF0, 0x01, 0x03, 0x05, 0x07};
	int DataRead[4] = {};
	I2C2_Power_Init();
	I2C2_Pin_Init();
	I2C2_Clock_Init();
	I2C2_MasterTxRx_Init();

	//Write Operation
	I2C2_Start();
	while(StartComplete == 0);
	StartComplete = 0;
	I2C2_SendAddressByte(0xA0);
	while(AddressByteAckComplete == 0);
	AddressByteAckComplete = 0;
	for(i=0; i<5; i++)
	{
		I2C2_SendDataByte(DataWrite[i]);
		while(DataByteAckComplete == 0)
		DataByteAckComplete = 0;
	}
	I2C2_Stop();
	for(i=1; i<5; i++)
	{
		printf("Data Written is %d\n", DataWrite[i]);
	}
	//Delay Program
	for(i=0; i<100000; i++);
	//Read Operation
	I2C2_Start();
	while(StartComplete == 0);
	StartComplete = 0;
	I2C2_SendAddressByte(0xA0); //Write Bit
	while(AddressByteAckComplete == 0);
	AddressByteAckComplete = 0;
	I2C2_SendDataByte(0xF0);
	while(DataByteAckComplete == 0);
	DataByteAckComplete = 0;
	I2C2_Start();
	while(RepeatStartComplete == 0);
	RepeatStartComplete = 0;
	I2C2_SendAddressByte(0xA1); //Read Bit
	while(AddressByteAckComplete == 0);
	AddressByteAckComplete = 0;
	I2C2_GetDataByte(1);
	for(i=0; i<3; i++)
	{
		while(DataByteReceiveAckComplete == 0);
		DataByteReceiveAckComplete = 0;
		DataRead[i] = LPC_I2C2->I2DAT;
	}
	I2C2_GetDataByte(0);
	while(DataByteReceiveNotAckComplete == 0);
	DataByteReceiveNotAckComplete = 0;
	DataRead[3] = LPC_I2C2->I2DAT;
	I2C2_Stop();
	for(i=0; i<4; i++)
	{
		printf("Data Read is %d\n", DataRead[i]);
	}
    return 0 ;
}
