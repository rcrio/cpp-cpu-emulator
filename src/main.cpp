#include <iostream>

#include "Memory.h"
#include "CPU.h"

int main()
{
    Memory memory;
    CPU cpu(memory);

    memory.write(0, 0b00000000); // NOP
    memory.write(1, 0b01000001); // ADD R0, R1
    memory.write(2, 0b11110000); // HALT

    cpu.reset();
    cpu.run();
}