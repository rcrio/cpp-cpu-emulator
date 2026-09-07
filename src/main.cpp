#include <iostream>
#include <filesystem>

#include "Memory.h"
#include "CPU.h"
#include "ProgramEncoder.h"

void run();

int main()
{
    run();
}

void run()
{
    Memory memory;
    CPU cpu(memory);
    ProgramEncoder programEncoder;

    programEncoder.encodeFile("bin/program.txt", "bin/program_binary.txt");
    memory.load("bin/program_binary.txt");
    /*
    memory.write(0, 0b00000000); // NOP
    memory.write(1, 0b01000001); // ADD R0, R1
    memory.write(2, 0b11110000); // HALT
    */

    cpu.reset();
    cpu.run();
}