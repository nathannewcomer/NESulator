extern int a, x, y, pc, s, p;
extern int status;
extern int* memory;

// returns immediate/actual value
int immediate() {
    pc++;
    int output = memory[pc];
    pc++;
    return output;
}

// returns zero page address
int zero_page() {
    pc++;
    int output = memory[pc];
    pc++;
    return output;
}

// return zero page address added to x register
int zero_page_x() {
    pc++;
    int output = memory[pc];
    pc++;
    return output + x;
}

// return zero page address added to y register
int zero_page_y() {
    pc++;
    int output = memory[pc];
    pc++;
    return output + y;
}

int relative() {
    pc++;
    pc += memory[pc];
}

int absolute() {
    pc++;
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
    pc++;
    int address = absolute();
    return memory[address];
}

// only used with x register
int indexed_indirect() {
    pc++;
    int address = (x + memory[pc]) & 0xFF;
    pc++;

    int output = memory[address];
    output += memory[address + 1] * 0xFF;

    return memory[output];
}

// only used with y register
int indirect_indexed() {
    pc++;
    int address = memory[pc];
    pc++;
    int output = memory[address];
    output += memory[address + 1] * 0xFF;

    output += y;
    return memory[output];
}