/*
===============================================================================
 Name        : Lab3.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void)
{

	//Section 3.2
	asm("LDR R0, =0x65040302");
	asm("LDR R1, =0x53283AE2");
	asm("ADD R2, R0, R1");
	asm("ADDW R2, R2, #0x8F1");
	asm("SUB R3, R0, R1");
	asm("RSB R4, R0, R1");
	asm("SUBW R4, R4, #0x871");
	asm("LDR R5, =0x199F9334");
	asm("LDR R6, =0x9832FDA1");
	asm("MUL R6, R5");
	asm("LDR R6, =0x9832FDA1");
	asm("UMULL R7, R8, R5, R6");
	asm("MOV R9, #0x02");
	asm("MOV R10, #0x03");
	asm("UMLAL R9, R10, R5, R6");
	asm("MOV R11, #0x30");
	asm("MOV R12, #0x5");
	asm("UDIV R12, R11, R12");

	//Section 3.4
	//asm("LDR R0, =0xA0A0B0B0");
	//asm("LDR R1, =0x0000FFFF");
	//asm("AND R2, R0, R1"); //AND Logic
	//asm("ORR R3, R0, R1"); //ORR Logic
	//asm("ORN R4, R0, R1"); //OR NOT Logic
	//asm("EOR R5, R0, R1"); //Exclusive OR Logic
	//asm("BIC R6, R0, R1"); //Bit Clear
	//asm("MVN R7, R0");     //Move Not
	//asm("MVN R8, #0xA5");  //Move Not

	//Section 3.6
	//asm("LDR R0, =0x0000F002");
	//asm("LDR R1, =0x8000F000");
	//asm("ASR R2, R0, #3");
	//asm("ASR R3, R1, #3");
	//asm("LSL R4, R0, #4");
	//asm("LSR R5, R1, #4");
	//asm("ROR R6, R0, #2");
	//asm("LDR R7, =0x20000000");
	//asm("MSR APSR, R7");
	//asm("RRX R8, R0");
	//asm("REV R9, R1");
	//asm("LDR R10, =0x0000F002");
	//asm("BFC R10, #12, #2");
	//asm("CLZ R11, R0");
	//asm("UBFX R12, R0, #12, #2");


    return 0 ;
}
