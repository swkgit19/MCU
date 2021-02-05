/*
===============================================================================
 Name        : Lab1.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

//#include <cr_section_macros.h>

//#include <stdio.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

	asm("LDR R0, =0x2009C018");
	asm("LDR R1, =0x00400000");
	asm("STR R1, [R0]");

	asm("repeat: LDR R2, =0x2009C000");
	asm("LDR R3, =0x00400000");
	asm("STR R3, [R2]");

	asm("LDR R5, =0x00000000");
	asm("LDR R4, =0x000FFFFF");
	asm("loop1: SUB R4, #1");
	asm("CMP R4, R5");
	asm("BNE loop1");

	asm("LDR R3, =0x00000000");
	asm("STR R3, [R2]");

	asm("LDR R5, =0x00000000");
	asm("LDR R4, =0x000FFFFF");
	asm("loop2: SUB R4, #1");
	asm("CMP R4, R5");
	asm("BNE loop2");

	asm("B repeat");
	return 0;
}
