# compiler
CC = gcc
# flags
CFLAGS = -g -Wall
# target
TARGET = nesulator
# object files
OBJECTS = addressing_modes.o instructions.o main.o register_functions.o runtime.o
# dependencies
DEPS = addressing_modes.h cpu.h instructions.h register_functions.h runtime.h

# recompile .c files when .h files change
%.o: %.c $(DEPS)
    $(CC) $(CFLAGS) -c -o $@ $<

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)