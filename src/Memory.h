#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include <cstdint>
#include <string>

class Memory
{
public:
    Memory();

    // Load a program into memory by path.
    bool load(const std::string& inputPath);

    // Read the address from memory and return the value stored there.
    uint8_t read(uint8_t address) const;

    // Write a value to the address.
    void write(uint8_t address, uint8_t value);
private:
    /*
    // Address width.
    static constexpr std::size_t ADDRESS_WIDTH = 8;

    // Shift bits 8 times to the left, so we get 1 0000 0000 which is 256.
    static constexpr std::size_t MEMORY_SIZE = 1 << ADDRESS_WIDTH;
    */

    // An array of uint8_t (8-bit size cells aka 1 byte).
    // 2^8 = 256, the amount of addressable locations.
    std::array<uint8_t, 256> storage_{};
};

#endif