#include <stdio.h>
#include "instructions.h"
#include "addressing_modes.h"

extern int a, x, y, pc, s, p;
extern int status;
extern int* memory;

// load ROM into memory
void load_rom() {
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

// process each operation
void process_instruction() {
    switch(memory[pc]) {
        case 0x0:
            brk();
            break;

        case 0x01:
            ora(memory[indexed_indirect()]);
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
            ora(memory[absolute()]);
            break;

        case 0x0E:
            asl(memory[absolute()]);
            break;

        case 0x10:
            bpl(relative());
            break;

        case 0x11:
            ora(memory[indirect_indexed()]);
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
            ora(memory[absolute_y()]);
            break;

        case 0x1D:
            ora(memory[absolute_x()]);
            break;

        case 0x1E:
            asl(memory[absolute_x()]);
            break;

        case 0x20:
            jsr(memory[absolute()]);
            break;

        case 0x21:
            and(memory[indexed_indirect()]);
            break;

        case 0x24:
            bit(memory[zero_page()]);
            break;

        case 0x25:
            and(memory[zero_page()]);
            break;

        case 0x26:
            rol(&memory[zero_page()]);
            break;

        case 0x28:
            plp();
            break;

        case 0x29:
            and(immediate());
            break;

        case 0x2A:
            pc++;
            rol(&a);
            break;

        case 0x2C:
            bit(memory[absolute()]);
            break;

        case 0x2D:
            and(memory[absolute()]);
            break;

        case 0x2E:
            rol(&memory[absolute()]);
            break;

        case 0x30:
            bmi(relative());
            break;

        case 0x31:
            and(memory[indexed_indirect()]);
            break;

        case 0x35:
            and(memory[zero_page_x()]);
            break;

        case 0x36:
            rol(&memory[zero_page_x()]);
            break;

        case 0x38:
            sec();
            pc++;
            break;

        case 0x39:
            and(memory[indirect_indexed()]);
            break;

        case 0x3D:
            and(memory[indexed_indirect()]);
            break;

        case 0x3E:
            rol(&memory[indexed_indirect()]);
            break;

        case 0x40:
            rti();
            pc++;
            break;

        case 0x41:
            eor(memory[indexed_indirect()]);
            break;

        case 0x45:
            eor(memory[zero_page()]);
            break;

        case 0x46:
            lsr(&memory[zero_page()]);
            break;

        case 0x48:
            pha();
            pc++;
            break;

        case 0x49:
            eor(immediate());
            break;

        case 0x4A:
            lsr(&a);
            pc++;
            break;

        case 0x4C:
            jmp(memory[absolute()]);
            break;

        case 0x4D:
            eor(memory[absolute()]);
            break;

        case 0x4E:
            lsr(&memory[absolute()]);
            break;

        case 0x50:
            bvc(memory[relative()]);
            break;

        case 0x51:
            eor(memory[indirect_indexed()]);
            break;

        case 0x55:
            eor(memory[zero_page_x()]);
            break;

        case 0x56:
            lsr(memory[zero_page_x()]);
            break;

        case 0x58:
            cli();
            pc++;
            break;
        
        case 0x59: 
            eor(memory[absolute_y()]);
            break;

        case 0x5D:
            eor(memory[absolute_x()]);
            break;

        case 0x5E:
            lsr(&memory[absolute_x()]);
            break;

        case 0x60:
            rts();
            pc++;
            break;

        case 0x61:
            adc(memory[indexed_indirect()]);
            break;

        case 0x65:
            adc(memory[zero_page()]);
            break;

        case 0x66:
            ror(&memory[zero_page()]);
            break;

        case 0x68:
            pla();
            pc++;
            break;

        case 0x69:
            adc(immediate());
            break;

        case 0x6A:
            ror(&a);
            break;

        case 0x6C:
            jmp(indirect());
            break;

        case 0x6D:
            adc(memory[absolute()]);
            break;

        case 0x6E:
            ror(&memory[absolute()]);
            break;

        case 0x70:
            bvs(relative());
            break;

        case 0x71:
            adc(memory[indirect_indexed()]);
            break;

        case 0x75:
            adc(memory[zero_page_x()]);
            break;

        case 0x76:
            ror(&memory[zero_page_x()]);
            break;

        case 0x78:
            sei();
            pc++;
            break;

        case 0x79:
            adc(memory[absolute_y()]);
            break;

        case 0x7D:
            adc(memory[absolute_x()]);
            break;

        case  0x7E:
            ror(&memory[absolute_x()]);
            break;

        case 0x81:
            sta(indexed_indirect());
            break;

        case 0x84:
            sty(zero_page());
            break;

        case 0x85:
            sta(zero_page());
            break;

        case 0x86:
            stx(zero_page());
            break;

        case 0x88:
            dey();
            pc++;
            break;

        case 0x8A:
            txa();
            pc++;
            break;

        case 0x8C:
            sty(absolute());
            break;

        case 0x8D:
            sta(absolute());
            break;

        case 0x8E:
            stx(absolute());
            break;

        case 0x90:
            bcc(memory[relative()]);
            break;

        case 0x91:
            sta(memory[indirect_indexed()]);
            break;

        case 0x94:
            sty(zero_page_x());
            break;

        case 0x95:
            sta(zero_page_x());
            break;

        case 0x96:
            stx(zero_page_y());
            break;
        
        case 0x98:
            tya();
            pc++;
            break;

        case 0x99:
            sta(absolute_y());
            break;

        case 0x9A:
            txs();
            pc++;
            break;

        case 0x9D:
            sta(absolute_x());
            break;

        case 0xA0:
            ldy(immediate());
            break;

        case 0xA1:
            lda(memory[indexed_indirect()]);
            break;

        case 0xA2:
            ldx(immediate());
            break;

        case 0xA4:
            ldy(memory[zero_page()]);
            break;

        case 0xA5:
            lda(memory[zero_page()]);
            break;

        case 0xA6:
            ldx(memory[zero_page()]);
            break;

        case 0xA8:
            tay();
            pc++;
            break;

        case 0xA9:
            lda(immediate());
            break;

        case 0xAA:
            tax();
            pc++;
            break;

        case 0xAC:
            ldy(memory[absolute()]);
            break;

        case 0xAD:
            lda(memory[absolute()]);
            break;

        case 0xAE:
            ldx(memory[absolute()]);
            break;

        case 0xB0:
            bcs(relative());
            break;

        case 0xB1:
            lda(memory[indirect_indexed()]);
            break;

        case 0xB4:
            ldy(memory[zero_page_x()]);
            break;

        case 0xB5:
            lda(memory[zero_page_x()]);
            break;

        case 0xB6:
            ldx(memory[zero_page_y()]);
            break;

        case 0xB8:
            clv();
            pc++;
            break;

        case 0xB9:
            lda(memory[absolute_y()]);
            break;

        case 0xBA:
            tsx();
            pc++;
            break;

        case 0xBC:
            ldy(memory[absolute_x()]);
            break;

        case 0xBD:
            lda(memory[absolute_x()]);
            break;

        case 0xBE:
            ldx(memory[absolute_y()]);
            break;

        case 0xC0:
            cpy(immediate());
            break;

        case 0xC1:
            cmp(memory[indexed_indirect()]);
            break;

        case 0xC4:
            cpy(memory[zero_page()]);
            break;

        case 0xC5:
            cmp(memory[zero_page()]);
            break;

        case 0xC6:
            dec(&memory[zero_page()]);
            break;

        case 0xC8:
            iny();
            pc++;
            break;

        case 0xC9:
            cmp(immediate());
            break;

        case 0xCA:
            dex();
            pc++;
            break;

        case 0xCC:
            cpy(memory[absolute()]);
            break;

        case 0xCD:
            cmp(memory[absolute()]);
            break;

        case 0xCE:
            dec(&memory[absolute()]);
            break;

        case 0xD0:
            bne(relative());
            pc++;
            break;

        case 0xD1:
            cmp(memory[indirect_indexed()]);
            break;

        case 0xD5:
            cmp(memory[zero_page_x()]);
            break;

        case 0xD6:
            dec(&memory[zero_page_x()]);
            break;

        case 0xD8:
            cld();
            pc++;
            break;

        case 0xD9:
            cmp(memory[absolute_y()]);
            break;
        
        case 0xDD:
            cmp(memory[absolute_x()]);
            break;

        case 0xDE:
            dec(&memory[absolute_x()]);
            break;

        case 0xE0:
            cpx(immediate());
            break;

        case 0xE1:
            sbc(memory[indexed_indirect()]);
            break;

        case 0xE4:
            cpx(memory[zero_page()]);
            break;

        case 0xE5:
            sbc(memory[zero_page()]);
            break;

        case 0xE6:
            inc(memory[zero_page()]);
            break;

        case 0xE8:
            inx();
            pc++;
            break;
            
        case 0xE9:
            sbc(immediate());
            break;

        case 0xEA:
            break;      // NOP - no operation

        case 0xEC:
            cpx(memory[absolute()]);
            break;

        case 0xED:
            sbc(memory[absolute()]);
            break;

        case 0xEE:
            inc(&memory[absolute()]);
            break;

        case 0xF0:
            beq(relative());
            break;

        case 0xF1:
            sbc(memory[indirect_indexed()]);
            break;

        case 0xF5:
            sbc(memory[zero_page_x()]);
            break;

        case 0xF6:
            inc(&memory[zero_page_x()]);
            break;

        case 0xF8:
            sed();
            pc++;
            break;

        case 0xF9:
            sbc(memory[absolute_y()]);
            break;

        case 0xFD:
            sbc(memory[absolute_x()]);
            break;

        case 0xFE:
            inc(&memory[absolute_x()]);
            break;

        default:
            break;      // TODO: maybe some error checking in case I missed something
}