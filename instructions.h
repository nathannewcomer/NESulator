#include "SDL2/SDL.h"

void adc(int value);

void and(int value);

void asl(int address);

// --- branch if carry clear ---
void bcc(int value);

// --- branch if cary set ---
void bcs(int value);

// --- branch if equal ---
void beq(int value);

// --- bit test ---
void bit(int value);

// --- branch if minus ---
void bmi(int value);

// --- branch if not equal ---
void bne(int value);

// --- branch if positive ---
void bpl(int value);

// --- break - force interrupt ---
void brk();

// --- branch if overflow clear ---
void bvc(int value);

// --- branch if overflow set ---
void bvs(int value);

// --- clear carry flag ---
void clc();

// --- clear decimal mode ---
void cld();

// --- clear interrupt disable ---
void cli();

// --- clear overflow flag ---
void clv();

// --- compare ---
void cmp(int value);

// --- compare x register ---
void cpx(int value);

// --- compare y register ---
void cpy(int value);

// --- decrement memory ---
void dec(int* value);

// --- decrement x register ---
void dex();

// --- decrement y register ---
void dey();

// --- exclusive or ---
void eor(int value);

// --- increment memory ---
void inc(int* value);

// --- increment x register ---
void inx();

// --- increment y register ---
void iny();

// --- jump ---
void jmp(int value);

// --- jump to subroutine ---
void jsr(int value);

// --- load accumulator ---
void lda(int value);

// --- load x register ---
void ldx (int value);

// --- load y register ---
void ldy (int value);

// --- logical shift right ---
void lsr(int* value);

// --- no operation ---
void nop();

// --- logical inclusive or ---
void ora(int value);

// --- push accumulator to stack ---
void pha();

// -- push processor status to stack ---
void php();

// --- pull accumulator ---
void pla();

// --- pull processor status ---
void plp();

// --- rotate left ---
void rol(int* value);

// --- rotate right ---
void ror(int* value);

// --- return from interrupt ---
void rti();

// --- return form subroutine ---
void rts();

// --- subtract with carry ---
void sbc(int value);

// --- set carry flag to 1 ---
void sec();

// --- set decimal flag ---
void sed();

// --- set interrupt disable ---
void sei();

// --- store accumulator ---
void sta(int location);

// --- store x register ---
void stx(int location);

// --- store x register ---
void sty(int location);

// --- transfer accumulator to x ---
void tax();

// --- transfer accumulator to y ---
void tay();

// --- transfer stack pointer to x ---
void tsx();

// --- transfer x to accumulator  ---
void txa();

// --- transfer x to stack pointer ---
void txs();

// --- transfer y to accumulator ---
void tya();