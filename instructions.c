#include "SDL2/SDL.h"
#include "register_functions.h"

extern int a, x, y, pc, s, p;
extern int status;
extern int* memory;

// --- add with carry to accumulator---

void adc(int value) {
    int result = a + value;

    // set flags
    set_overflow(a, value, result);
    set_zero(result);
    set_negative(result);
    set_carry(result);

    // finally add
    a = result;
}

// --- logical AND to accumulator ---

void and(int value) {
    a &= value;

    // set flags
    set_zero(a);
    set_negative(a);
}

// -- arithmetic shift left ---
void asl(int address) {
    memory[address] << 1;

    // set flags
    set_carry(memory[address]);
    set_zero(memory[address]);
    set_negative(memory[address]);
}

// --- branch if carry clear ---
void bcc(int value) {
    if (!(p | 0b10000000)) {
        pc += value;
    }
}

// --- branch if cary set ---
void bcs(int value) {
    if (is_negative_set()) {
        pc += value;
    }
}

// --- branch if equal ---
void beq(int value) {
    if (is_zero_set()) {
        pc += value;
    }
}

// --- bit test ---
void bit(int value) {
    if (value & 0b10000000) {   // negative
        p |= 0b10000000;
    } else {
        p &= 0b01111111;
    }

    if (value & 0b01000000) {   // overflow
        p |= 0b01000000;
    } else {
        p &= 0b10111111;
    }

    set_zero(value & a);
}

// --- branch if minus ---
void bmi(int value) {
    if (is_negative_set) {
        pc += value;
    }
}

// --- branch if not equal ---
void bne(int value) {
    if (!is_zero_set()) {
        pc += value;
    }
}

// --- branch if positive ---
void bpl(int value) {
    if (is_negative_set) {
        pc += value;
    }
}

// --- break - force interrupt ---
void brk() {
    // TODO
    pc++;
    return;
}

// --- branch if overflow clear ---
bvc(int value) {
    if (!is_overflow_set()) {
        pc += value;
    }
}

// --- branch if overflow set ---
void bvs(int value) {
    if (is_overflow_set()) {
        pc += value;
    }
}

// --- clear carry flag ---
void clc() {
    pc++;
    p &= 0b11111110;
}

// --- clear decimal mode ---
void cld() {
    p &= 0b11110111;
}

// --- clear interrupt disable ---
void cli() {
    p &= 0b11111011;
}

// --- clear overflow flag ---
void clv() {
    p &= 0b10111111;
}

// --- compare ---
void cmp(int value) {
    int result = a - value;

    set_carry(result);
    set_zero(result);
    set_zero(result);
}

// --- compare x register ---
void cpx(int value) {
    int result = x - value;

    set_carry(result);
    set_zero(result);
    set_zero(result);
}

// --- compare y register ---
void cpy(int value) {
    int result = y - value;

    set_carry(result);
    set_zero(result);
    set_zero(result);
}

// --- decrement memory ---
void dec(int* value) {
    *value--;

    set_zero(*value);
    set_negative(*value);
}

// --- decrement x register ---
void dex() {
    x--;

    set_zero(x);
    set_negative(x);
}

// --- decrement y register ---
void dey() {
    y--;

    set_zero(y);
    set_negative(y);
}

// --- exclusive or ---
void eor(int value) {
    a |= value;

    set_zero(a);
    set_negative(a);
}

// --- increment memory ---
void inc(int* value) {
    *value++;

    set_zero(*value);
    set_negative(*value);
}

// --- increment x register ---
void inx() {
    x++;

    set_zero(x);
    set_negative(x);
}

// --- increment y register ---
void iny() {
    y++;

    set_zero(y);
    set_negative(y);
}

// --- jump ---
void jmp(int value) {
    pc = value;
}

// --- jump to subroutine ---
void jsr(int value) {
    stack_push(pc + 2);
    stack_push(pc + 1);

    pc = value;
}

// --- load accumulator ---
void lda(int value) {
    a = value;

    set_zero(a);
    set_negative(a);
}

// --- load x register ---
void ldx (int value) {
    x = value;

    set_zero(x);
    set_negative(x);
}

// --- load y register ---
void ldy (int value) {
    y = value;

    set_zero(y);
    set_negative(y);
}

// --- logical shift right ---
void lsr(int* value) {
    *value >> 1;

    set_zero(*value);
    set_negative(*value);
}

// --- no operation ---
void nop() {
    return;
}

// --- logical inclusive or ---
void ora(int value) {
    a |= value;

    set_zero(a);
    set_negative(a);
}

// --- push accumulator to stack ---
void pha() {
    stack_push(a);
}

// -- push processor status to stack ---
void php() {
    stack_push(p);
    pc++;
}

// --- pull accumulator ---
void pla() {
    a = stack_pop();

    set_zero(a);
    set_negative(a);
}

// --- pull processor status ---
void plp() {
    p++;
    p = stack_pop();
}

// --- rotate left ---
void rol(int* value) {
    *value << 1;

    if (is_carry_set()) {
        *value |= 0b00000001;
    }
    set_carry(*value);
    set_zero(*value);
    set_negative(*value);
}

// --- rotate right ---
void ror(int* value) {
    int new_carry = *value & 0b00000001;
    *value >> 1;
    int current_carry = *value & 0b00000001;

    if (current_carry) {
        *value |= 0b10000000;   // set value with old carry
    }

    if (new_carry) {
        p |= 0b00000001;        // set new carry
    }

    set_zero(*value);
    set_negative(*value);
}

// --- return from interrupt ---
void rti() {
    p = stack_pop();
    pc = stack_pop();
}

// --- return form subroutine ---
void rts() {
    pc = stack_pop();
    // TODO: might be wrong
}

// --- subtract with carry ---
void sbc(int value) {
    //a -= value - (1 - is_carry_set());
    int result = a - value - (1 - is_carry_set());

    set_carry(result);
    set_zero(result);
    set_overflow(a, value, result);
    set_negative(result);

    a = result;
}

// --- set carry flag to 1 ---
void sec() {
    p |= 0b00000001;
}

// --- set decimal flag ---
void sed() {
    p |= 0b00001000;
}

// --- set interrupt disable ---
void sei() {
    p |= 0b00000100;
}

// --- store accumulator ---
void sta(int location) {
    memory[location] = a;
}

// --- store x register ---
void stx(int location) {
    memory[location] = x;
}

// --- store x register ---
void sty(int location) {
    memory[location] = y;
}

// --- transfer accumulator to x ---
void tax() {
    x = a;

    set_zero(x);
    set_negative(x);
}

// --- transfer accumulator to y ---
void tay() {
    y = a;

    set_zero(y);
    set_negative(y);
}

// --- transfer stack pointer to x ---
void tsx() {
    x = s;

    set_zero(x);
    set_negative(x);
}

// --- transfer x to accumulator  ---
void txa() {
    a = x;

    set_zero(a);
    set_negative(a);
}

// --- transfer x to stack pointer ---
void txs() {
    s = x;
}

// --- transfer y to accumulator ---
void tya() {
    a = y;

    set_zero(a);
    set_negative(a);
}