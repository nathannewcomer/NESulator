#include "SDL2/SDL.h"

void stack_push(int value);

int stack_pop();

void set_carry(int reg);

void set_zero(int reg);

void set_interrupt(SDL_bool set);

void set_overflow(int a, int b, int result);

void set_negative(int reg);

int is_carry_set();

int is_zero_set();

int is_interrupt_set();

int is_overflow_set();

int is_negative_set();