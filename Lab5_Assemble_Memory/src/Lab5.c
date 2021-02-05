/*
===============================================================================
 Name        : Lab5.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif


int main(void) {

	//Setting up the MPU
	//Section 2.3
	asm("LDR R0, =0x000ED90");
	asm("LDR R1, [R0]");
	asm("CMP R1, #0x800"); //#0xFFFFFFFF
	asm("BEQ SetMPU");
	asm("B exit");

	asm("SetMPU: LDR R0, =0xE000ED94");
	asm("MOV R1, #0");
	asm("STR R1, [R0]");

	asm("LDR R0, =0xE000ED98");
	asm("MOV R1, #0");
	asm("STR R1, [R0]");
	asm("LDR R1, =0x00000000");
	asm("STR R1, [R0, #4]");
	asm("LDR R1, =0x05070025");
	asm("STR R1, [R0, #8]");

	asm("LDR R0, =0xE000ED98");
	asm("MOV R1, #1");
	asm("STR R1, [R0]");
	asm("LDR R1, =0x10000000");
	asm("STR R1, [R0, #4]");
	asm("LDR R1, =0x0307001D");
	asm("STR R1, [R0, #8]");

	asm("LDR R0, =0xE000ED94");
	asm("MOV R1, #1");
	asm("STR R1, [R0]");

	asm("LDR R0, =0x00000001");
	asm("MOV R1, #0xAA");
	asm("STR R1, [R0]"); //(Hard Fault) Valid Address but program not responding

	asm("exit: b exit");

	//Bit Band Operation
	//Section 3.1
	//asm("MOV R0, #0x03");
	//asm("MOV R1, #0x01");
	//asm("Loop: LDR R2, =0x40000000");
	//asm("LDR R3, [R2]");
	//asm("ORR R3, R1");
	//asm("STR R3, [R2]");
	//asm("SUB R0, #0x01");
	//asm("LSL R1, #0x01");
	//asm("CMP R0, #0x00");
	//asm("BNE Loop");
	//asm("exit: b exit");

    return 0 ;
}
