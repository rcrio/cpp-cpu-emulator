#include "Memory.h"

#include <fstream>
#include <iostream>

Memory::Memory()
{

}

bool Memory::load(const std::string &inputPath)
{
    std::ifstream inputFile(inputPath);

    if (!inputFile)
        return false;

    std::string line;

    int pc = 0;

    while (std::getline(inputFile, line))
    {
        uint8_t data = static_cast<uint8_t>(std::stoi(line, nullptr, 2));
        write(pc, data);
        pc++;
    }

    return true;
}

uint8_t Memory::read(uint8_t address) const
{
    return storage_[address];
}

void Memory::write(uint8_t address, uint8_t value)
{
    storage_[address] =  value;
}
