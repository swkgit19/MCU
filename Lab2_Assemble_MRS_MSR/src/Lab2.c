/*
===============================================================================
 Name        : Lab2.c
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

	//Section_1.3 Part 1
	asm("MOV R0, #0x00");
	asm("MSR CONTROL, R0");
	asm("MSR PSP, R0");
	asm("MSR MSP, R0"); // MSR ???
	//asm("MOVW R1, #0x1234"); // Start of Part 2
	//asm("MOV SP, R1");
	//asm("MOV R0, #0x02");
	//asm("MSR CONTROL, R0");

	//Section 1.3 Part 2
	asm("MOVW R1, #0x1234");
	asm("MOV SP, R1");
	asm("MOV R0, #0x01");
	asm("MSR CONTROL, R0");
	asm("MOV R0, #0x00");
	asm("MSR CONTROL, R0"); //Code Not Responding

	//Section 2.2
	//asm("MOV R0, #0x12");
	//asm("MOVW R1, #0x3294");
	//asm("MOVT R1, #0xA983");
	//asm("MOV R2, R1");
	//asm("MSR PSP, R2"); //SReg to Register
	//asm("MRS R3, PSP"); /Register to SReg

	//Section 2.3.2
	//asm("MOVW R0, #0x1000"); //Bottom 16-Bit
	//asm("MOVT R0, #0x1000"); //Top 16-Bit
	//asm("MOVW R1, #0x2468"); //Bottom 16-Bit
	//asm("MOVT R1, #0x1357"); //Top 16-Bit
	//asm("MOVW R2, #0x1122"); //Bottom 16-Bit
	//asm("MOVT R2, #0x4554"); //Top 16-Bit
	//asm("STRD R1, R2,[R0,#4]"); //Store Double Word
	//asm("LDRD R3, R4,[R0,#4]"); //Load Double Word

	//Section 2.3.4
	//asm("MOVW R0, #0x1000");
	//asm("MOVT R0, #0x1000");
	//asm("MOVW R1, #0x2468");
	//asm("MOVT R1, #0x1357");
	//asm("MOVW R2, #0x1122");
	//asm("MOVT R2, #0x4554");
	//asm("MOVW R3, #0x3454");
	//asm("MOVT R3, #0x4AB5");
	//asm("STMIA R0!, [R1-R3]"); //Store Multiple Words Increment
	//asm("LDMIA R0!, [R4-R6]"); //Read Multiple Words Increment

	//Section 2.3.6
	//asm("LDR R0, =0x10001008");
	//asm("ADR R1, exit");
	//asm("LDR R0, =exit");
	//asm("exit: b exit");

    return 0 ;
}
