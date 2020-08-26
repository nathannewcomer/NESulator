#include <stdio.h>
#include "SDL2/SDL.h"
#include "cpu.h"

extern int a, x, y, pc, s, p;
extern int status;
extern int* memory;

int main() {

    a = 0;
    x = 0;
    y = 0;
    pc = 0;
    s = 0x01FF;
    p = 0;

    // initialize memory
    memory = (int*)malloc(0xFFFF);


    // free memory
    free(memory);
    return 0;
}