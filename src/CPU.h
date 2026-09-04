#ifndef CPU_H
#define CPU_H

#include <array>
#include <cstdint>

#include "Memory.h"

class CPU
{
public:
    CPU(Memory& memory);

    void run();

    // Execute one complete CPU cycle:
    // fetch, decode and execute an instruction.
    void step();

    // Reset the CPU to its initial state.
    void reset();

    // Return whether the CPU has executed a HALT instruction.
    bool isHalted() const;

private:
    // OpCode as enum, to make things clearer
    enum class OpCode : std::uint8_t
    {
        NOP   = 0x0,
        MOV   = 0x1,
        LOAD  = 0x2,
        STORE = 0x3,

        ADD   = 0x4,
        SUB   = 0x5,
        AND   = 0x6,
        OR    = 0x7,
        XOR   = 0x8,

        JMP   = 0x9,
        JZ    = 0xA,

        HALT  = 0xF
    };

    // Produced by decode to be used by execute
    struct DecodedInstruction
    {
        OpCode opCode;
        std::uint8_t reg1;
        std::uint8_t reg2;
    };

    // Fetch the next instruction from memory using the program counter.
    void fetch();

    // Decode the current instruction to determine what operation to perform.
    DecodedInstruction decode();

    // Execute the decoded instruction.
    void execute(const DecodedInstruction& instruction);

    // Memory used by the CPU.
    Memory& memory_;

    // 4 General-purpose 8-bit registers (R0-R3).
    //
    // Each register is identified using 2 bits:
    //
    // 00 -> R0
    // 01 -> R1
    // 10 -> R2
    // 11 -> R3
    std::array<std::uint8_t, 4> registers_{};

    // Program Counter:
    // address of the next instruction to fetch.
    std::uint8_t pc_{};

    // Instruction Register:
    // holds the instruction currently being processed.
    std::uint8_t ir_{};

    // Set when the result of an operation is zero.
    bool zeroFlag_{};

    // Set when the CPU executes a HALT instruction.
    bool halted_{};

    // DEBUG METHODS
    void printRegisters() const;
    void printStep(const DecodedInstruction& instruction) const;
};

#endif