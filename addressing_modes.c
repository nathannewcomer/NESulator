extern int a, x, y, pc, s, p;
extern int status;
extern int* memory;

// returns zero page address
int zero_page() {
    int output = memory[pc];
    pc++;
    return output;
}

// return zero page address added to x register
int zero_page_x() {
    int output = memory[pc];
    pc++;
    return output + x;
}

// return zero page address added to y register
int zero_page_y() {
    int output = memory[pc];
    pc++;
    return output + y;
}

int relative() {
    pc += memory[pc];
}

int absolute() {
    int output = memory[pc] * 0xFF;
    pc++;
    output += memory[pc];
    pc++;

    return output;
}

int absolute_x() {
    return absolute() + x;
}

int absolute_y() {
    return absolute() + y;
}

// only used by jump
int indirect() {
    int address = absolute();
    return memory[address];
}

// only used with x register
int indexed_indirect() {
    int address = (x + memory[pc]) & 0xFF;
    pc++;

    int output = memory[address];
    output += memory[address + 1] * 0xFF;

    return memory[output];
}

// only used with y register
int indirect_indexed() {
    int address = memory[pc];
    pc++;
    int output = memory[address];
    output += memory[address + 1] * 0xFF;

    output += y;
    return memory[output];
}