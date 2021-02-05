/*
===============================================================================
 Name        : Lab6.c
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

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void)
{

	//Section 1.4
	//Stack Memory Operation
	asm("LDR R0, =0x12345678");
	asm("LDR R2, =0x2468ACEF");
	asm("LDR R3, =0x928347AE");
	asm("LDR R4, =0x120974DC");
	asm("LDR R8, =0x2948AB93");
	asm("LDR SP, =0x00000000");
	asm("PUSH {R0, R2-R4, R8}"); //Follow SP(Stack) Pointer
	asm("POP {R1, R5-R7, R9}");
	asm("exit: b exit");


	//Setting up an Interrupt
	//Section 2.3
	/*
	asm("LDR R0, =0xE000ED0C"); 	//Note 1
	asm("LDR R1, =0x05FA0500");
	asm("STR R1, [R0]");

	asm("MOV R2, #0x08");			//Note 2
	asm("LDR R3, =0x10001000+8");
	asm("LDMIA R2!, [R0-R1]");
	asm("STMIA R3!, [R0-R1]");

	asm("LDR R0, =0xE000ED08");		//Note 3
	asm("LDR R1, =0x10001000");
	asm("STR R1, [R0]");

	asm("LDR R0, =irq1_handler+1");	//Note 4
	asm("LDR R1, =0xE000ED08");
	asm("LDR R1, [R1]");
	asm("ADD R1, R1, #(4*(1+16))");
	asm("STR R0, [R1]");

	asm("LDR R0, =0xE000E400"); 	//Note 5
	asm("MOV R1, #0xC0");
	asm("STRB R1, [R0, #1]");

	asm("LDR R0, =0xE000E100");		//Note 6
	asm("MOV R1, #(1<<1)");
	asm("STR R1, [R0]");

	asm("LDR R0, =0xE000E200");		//Note 7
	asm("MOV R1, #(1<<1)");
	asm("STR R1, [R0]");
	asm("exit: b exit");

	asm("irq1_handler: BX LR");		//Note 8
	*/
	/*
	//Section 3.5
	//asm("LDR R0, =0x00000000");
	//asm("MSR APSR, R0");
	//asm("LDR R0, =0xE000ED08");
	//asm("LDR R1, =0x10001000");
	//asm("STR R1, [R0]");

	//asm("LDR R0, =svc_handler+1");
	//asm("LDR R1, =0xE000ED08");
	//asm("LDR R1, [R1]");
	//asm("ADD R1, R1, #(4*11)");
	//asm("STR R0, [R1]");

	//asm("MOV R3, #0x02");
	//asm("LDR R12, =0x24681357");
	//asm("LDR SP, =0x10008000");

	//asm("MOV R2, #0x01");
	//asm("MSR CONTROL, R2");
	//asm("SVC 0x02");
	//asm("exit: b exit");

	//asm("svc_handler: MOV R2, #0x00");
	//asm("MSR CONTROL, R2");
	//ams("BX LR");


	//Section 4
	//asm("LDR R0, =0xE000ED08");
	//asm("LDR R1, =0x10001000");
	//asm("STR R1, [R0]");

	//asm("LDR R0, =svc_handler+1");
	//asm("LDR R1, =0xE000ED08");
	//asm("LDR R1, [R1]");
	//asm("ADD R1, R1, #(4*11)");
	//asm("STR R0, [R1]");

	//asm("SVC 0x03");
	//asm("exit: b exit");
	//asm("svc_handler:");
	//asm("...");
	//asm("...");
	//asm("...");
	//asm("...");
	//asm("...");
	//asm("...");
	//asm("BX LR");
	*/

    return 0 ;
}
