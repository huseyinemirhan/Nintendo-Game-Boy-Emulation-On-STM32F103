	/*
 * main.c
 *
 *  Created on: Dec 30, 2025
 *      Author: MSI Cyborg
 */

#include "cpu/cpu.h"
#include "memory/memory.h"
#include <stdio.h>

void Load_Test_Rom(){

	    Memory_Write_Byte(0x0000, 0x3E); // LD A, 0xAB
	    Memory_Write_Byte(0x0001, 0xAB);

	    Memory_Write_Byte(0x0002, 0x26); // LD H, 0xC0 (Point HL to Work RAM)
	    Memory_Write_Byte(0x0003, 0xC0);
	    Memory_Write_Byte(0x0004, 0x2E); // LD L, 0x05
	    Memory_Write_Byte(0x0005, 0x05);

	    // --- Step 2: Move data through memory ---
	    Memory_Write_Byte(0x0006, 0x77); // LD (HL), A  -> Writes 0xAB to 0xC005
	    Memory_Write_Byte(0x0007, 0x46); // LD B, (HL) -> Reads 0xC005 into B
	    Memory_Write_Byte(0x0008, 0x48); // LD C, B    -> Copies B into C

	    // --- Step 3: End ---
	    Memory_Write_Byte(0x0009, 0x00); // NOP
}

void print_debug(){
	printf("PC: %d Cycles: %d\n",cpu.PC,cpu.cycles);
	printf("------REGISTERS-------\n");
	printf("A: %x B: %x C: %x D: %x E: %d H: %x L: %x\n",cpu.A,cpu.B,cpu.C,cpu.D,cpu.E, cpu.H, cpu.L);
	printf("-Flags-\n");
	printf("Z: %d N: %d H: %d C: %d\n",CPU_Get_Flag(Z_FLAG),CPU_Get_Flag(N_FLAG),CPU_Get_Flag(H_FLAG),CPU_Get_Flag(C_FLAG) );
}



int main(){

	CPU_Init();
	Memory_Init();
	Load_Test_Rom();

	for(int i = 0; i<7; i++){
		CPU_Step();
		print_debug();
	}

	return 0;

}


