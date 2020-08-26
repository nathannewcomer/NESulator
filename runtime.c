#include <stdio.h>
#include "instructions.h"
#include "addressing_modes.h"

extern int a, x, y, pc, s, p;
extern int status;
extern int* memory;

// load ROM into memory
void loadrom() {
    FILE* rom;
    int i = 0x4020;
    pc = 0x4020;
    int byte;

    rom = fopen("mario.nes", 'r');

    while (byte = fgetc(rom)) {
        memory[i] = byte;
        i++;
    }

    fclose(rom);
}

void process_instruction() {
    switch(memory[pc]) {
        case 0x0:           // break
            brk();
            break;

        case 0x01:
            ora(indexed_indirect());
            break;
        
        case 0x05:
            ora(memory[zero_page()]);
            break;

        case 0x06:
            asl(&memory[zero_page()]);
            break;

        case 0x08:
            php();

        case 0x09:
            ora(immediate());
            break;

        case 0x0A:
            asl(&a);
            break;
        
        case 0x0D:
            ora(absolute());
            break;

        case 0x0E:
            asl(absolute());
            break;

        case 0x10:
            bpl(relative());
            break;

        case 0x11:
            ora(indirect_indexed());
            break;

        case 0x15:
            ora(memory[zero_page_x()]);
            break;

        case 0x16:
            asl(&memory[zero_page_x()]);
            break;

        case 0x18:
            clc();
            break;

        case 0x19:
            ora(absolute_y());
            break;

        case 0x1D:
            ora(absolute_x());
            break;

        case 0x1E:
            asl(absolute_x());
            break;

        case 0x20:
            jsr(absolute());
            break;

        case 0x21:
            and(indexed_indirect());
            break;

        case 0x24:
            bit(zero_page());
            break;

        case 0x25:
            and(memory[zero_page()]);
            break;

        case 0x26:
            rol(memory[zero_page()]);
            break;


    }
}