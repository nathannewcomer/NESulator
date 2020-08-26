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
    s = 0;
    p = 0;

    return 0;
}