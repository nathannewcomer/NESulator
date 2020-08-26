// returns zero page address
int zero_page();

// return zero page address added to x register
int zero_page_x();

// return zero page address added to y register
int zero_page_y();

int relative();

int absolute();

int absolute_x();

int absolute_y();

// only used by jump
int indirect();

// only used with x register
int indexed_indirect();

// only used with y register
int indirect_indexed();