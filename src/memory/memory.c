/*
 * memory.c
 *
 *  Created on: Dec 30, 2025
 *      Author: MSI Cyborg
 */

#include "memory.h"
#include <stdio.h>
#include "../cpu/cpu.h"

MEMORY_MAP memory = {0};

void Memory_Init(){


}

uint8_t Memory_Read_Byte(uint16_t addr){

	if (addr >= ERAM_START && addr <= ERAM_END) {
	        addr -= 0x2000;
	}
	if(addr >= ROM_START && addr <= ROM_END){

		return memory.rom[addr-ROM_START];
	}
	else if(addr >= VRAM_START && addr <= VRAM_END){

		return memory.vram[addr-VRAM_START];
	}
	else if(addr >= EXT_RAM_START && addr <= EXT_RAM_END){

		return memory.ext_ram[addr-EXT_RAM_START];
	}
	else if(addr >= WRAM_START && addr <= WRAM_END){

		return memory.wram[addr-WRAM_START];
	}
	else if(addr >= OAM_START && addr <= OAM_END){

		return memory.oam[addr-OAM_START];
	}
	else if(addr >= IO_REG_START && addr <= IO_REG_END){

		return memory.io_reg[addr-IO_REG_START];
	}
	else if(addr >= HRAM_START && addr <= HRAM_END){

		return memory.hram[addr-HRAM_START];
	}
	else{
		return memory.ie;
	}
}

void Memory_Write_Byte(uint16_t addr, uint8_t val){

	if (addr >= ERAM_START && addr <= ERAM_END) {
	        addr -= 0x2000;
	}
	if(addr >= ROM_START && addr <= ROM_END){
		//printf("ROM INACCESIBLE\n");
		memory.rom[addr-ROM_START] = val;
	}
	else if(addr >= VRAM_START && addr <= VRAM_END){

		memory.vram[addr-VRAM_START] = val;
	}
	else if(addr >= EXT_RAM_START && addr <= EXT_RAM_END){

		memory.ext_ram[addr-EXT_RAM_START] = val;
	}
	else if(addr >= WRAM_START && addr <= WRAM_END){

		memory.wram[addr-WRAM_START] = val;
	}
	else if(addr >= OAM_START && addr <= OAM_END){

		memory.oam[addr-OAM_START] = val;;
	}
	else if(addr >= IO_REG_START && addr <= IO_REG_END){

		memory.io_reg[addr-IO_REG_START] = val;
	}
	else if(addr >= HRAM_START && addr <= HRAM_END){

		memory.hram[addr-HRAM_START] = val;
	}
	else{
		memory.ie = val;
	}

}


