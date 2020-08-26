#include "SDL2/SDL.h"

extern int a, x, y, pc, s, p;
extern int status;
extern int* memory;

void stack_push(int value) {
    s--;
    memory[s] = value;
}

int stack_pop() {
    int value = memory[s];
    s++;
}

// --- flag setters and clearers ---

// NVss DIZC
// NES doesn't use decimal mode

void set_carry(int reg) {
    if (reg | 0b10000000) {
        p |= 0b00000001;
    } else {
        p &= 0b11111110;    
    }
}

void set_zero(int reg) {
    if (reg == 0) {
        p |= 0b00000010;
    } else {
        p &= 0b11111101;    
    }
}

void set_interrupt(SDL_bool set) {
    if (set) {
        p |= 0b00000100;
    } else {
        p &= 0b11111011;
    }
}

// you must convert subraction to negative addition to use this
void set_overflow(int a, int b, int result) {
    if (a > 0 && b > 0 && result < 0) {
        p |= 0b01000000;
    } else if (a < 0 && b < 0 && result > 0) {
        p &= 0b10111111;
    }
}

void set_negative(int reg) {
    if (reg < 0) {
        p |= 0b10000000;
    } else {
        p &= 0b01111111;
    }
}

int is_carry_set() {
    return p & 0b00000001;
}

int is_zero_set() {
    return p & 0b00000010;
}

int is_interrupt_set() {
    return p & 0b00000100;
}

int is_overflow_set() {
    return p & 0b01000000;
}

int is_negative_set() {
    return p & 0b10000000;
}