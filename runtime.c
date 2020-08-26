#include <stdio.h>

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

