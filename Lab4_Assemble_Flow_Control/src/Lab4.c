/*
===============================================================================
 Name        : Lab4.c
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

int main(void) {

	//Section 4, Part 1.2 //Code with Error.
	//asm("LDR R0, =0x00000000");
	//asm("MSR APSR, R0"); // Error on this line.
	asm("LDR R0, =0xF0001111");
	asm("LDR R1, =0x80002222");
	asm("ADDS R2, R0, R1");
	asm("ADCS R3, R0, R1");
	asm("SUBS R4, R1, R0");
	asm("SBCS R5, R0, R1");
	asm("ASRS R6, R1, #1");  //#01
	asm("ASRS R6, R0, #1"); //#01
	asm("LSLS R7, R5, #1"); //#01
	asm("RRXS R8, R0");
	asm("RRXS R9, R8");
	asm("CMP R1, R0");
	asm("LDR R0, 0x80002222");
	asm("CMP R1, R0");
	asm("CMN R1, R0");
	asm("LDR R0, =0x30001111");
	asm("TST R1, R0");

	//Section 4, Part 2.2
	//asm("ADR R0, Tstart+1");
	//asm("BLX R0");
	//asm("NOP");
	//asm("Tstart: MOV R0, #0x10");
	//asm("MOV R1, #0x03");
	//asm("BL doadd");
	//asm("exit: B exit");
	//asm("doadd: ADD R2, R0, R1");
	//asm("MOV PC, LR");

	//Section 4, Part 2.4
	//asm("MOV R0, #0x03");
	//asm("MOV R1, #0x03");
	//asm("MOV R2, #0x03");
	//asm("BL arithfunc");
	//asm("stop: B stop");
	//asm("arithfunc: CMP R0, #0x02");
	//asm("BHS DoAdd");
	//asm("B DoSub");
	//asm("DoAdd: ADD R0, R1, R2");
	//asm("MOV PC, LR");
	//asm("DoSub: SUB R0, R1, R2");
	//asm("MOV PC, LR");

	//Section 4, Part 2.6
	//asm("LDR R3, =0x00000000");
	//asm("MSR APSR, R3");
	//asm("MOV R0, #0x03");
	//asm("MOV R1, #0x01");
	//asm("MOV R2, #0x02");
	//asm("loop1: CBNZ R0, mulfunc");
	//asm("exit: B exit");
	//asm("mulfunc: MUL R1, R2");
	//asm("SUB R0, #1");
	//asm("B loop1");

	//Section 4, Part 2.8
	//asm("MOV R0, #0x03");
	//asm("MOV R1, #0x03");
	//asm("MOV R2, #0x00");
	//asm("MOV R3, #0x00");
	//asm("CMP R0, R1");
	//asm("ITET HS");
	//asm("ADDHS R2, R0, R1");
	//asm("SUBLO R2, R1, R0");
	//asm("MULHS R3, R0, R1");
	//asm("exit: B exit");

    return 0 ;
}
