#include "Memory.h"

Memory::Memory()
{

}

uint8_t Memory::read(uint8_t address) const
{
    return storage_[address];
}

void Memory::write(uint8_t address, uint8_t value)
{
    storage_[address] =  value;
}
