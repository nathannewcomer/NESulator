#include <stdio.h>
#include "SDL2/SDL.h"
#include "cpu.h"
#include "runtime.h"

extern int a, x, y, pc, s, p;
extern int status;
extern int* memory;

int main() {
    SDL_bool running = SDL_TRUE;

    // initialize registers
    a = 0;
    x = 0;
    y = 0;
    pc = 0;
    s = 0x01FF;
    p = 0;

    // initialize memory
    memory = (int*)malloc(0xFFFF);

    // load rom into memory
    load_rom();

    // processor loop
    while (running) {
        process_instruction();

        // TODO: add everything else
    }

    // free memory
    free(memory);
    return 0;
}