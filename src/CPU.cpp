#include "CPU.h"

#include <iostream>

CPU::CPU(Memory& memory) : memory_(memory)
{

}

void CPU::run()
{
    while(!halted_)
    {
        std::string input;

        std::cout << "Press any key to continue the step: ";
        std::cin.get();
        step();
    }
}

void CPU::step()
{
    fetch();
    pc_++;

    CPU::DecodedInstruction instruction = decode();

    printStep(instruction);
    execute(instruction);
    printRegisters();
}

void CPU::reset()
{
    for (int i = 0; i < registers_.size(); i++)
    {
        registers_[i] = 0;
    }

    // For debug only
    registers_[0] = 34;
    registers_[1] = 49;

    pc_ = 0;
    ir_ = 0;
    zeroFlag_ = false;
    halted_ = false;
}

bool CPU::isHalted() const
{
    return halted_;
}

void CPU::fetch()
{
    ir_ = memory_.read(pc_);
}


CPU::DecodedInstruction CPU::decode()
{
    uint8_t opCodeMask = 0b11110000;
    uint8_t reg1Mask = 0b00001100;
    uint8_t reg2Mask = 0b00000011;
    
    uint8_t rawOpCode = (ir_ & opCodeMask) >> 4;
    uint8_t reg1 = (ir_ & reg1Mask) >> 2;
    uint8_t reg2 = ir_ & reg2Mask;
    
    // Cast rawOpCode to an enum to make it easier to address in the execute method
    OpCode opCode = static_cast<OpCode>(rawOpCode);

    return
    {
        opCode,
        reg1,
        reg2
    };
}

void CPU::execute(const DecodedInstruction& instruction)
{   
    uint8_t &registerA = registers_[instruction.reg1];
    uint8_t &registerB = registers_[instruction.reg2];

    switch(instruction.opCode)
    {
        case OpCode::NOP:
            break;
        
        case OpCode::MOV:
            registerA = registerB;
            break;

        case OpCode::LOAD:
            registerA = memory_.read(registerB);
            break;
            
        /*
        case CPU::OpCode::STORE:
            memory_.write(registerB, registerA);
            break;
        */

        case OpCode::ADD:
            registerA = registerA + registerB;
            break;

        case OpCode::SUB:
            registerA = registerA - registerB;
            break;
        
        case OpCode::AND:
            registerA = registerA & registerB;
            break;
        
        case OpCode::OR:
            registerA = registerA | registerB;
            break;
        
        case OpCode::XOR:
            registerA = registerA ^ registerB;
            break;

        /*
        case CPU::OpCode::JMP:
            pc_ = registerA;
            break;
        */

        /*
        case CPU::OpCode::JZ:
            if (zeroFlag_)
            {
                pc_ = registerA;
            }
            break;
        */

        case OpCode::HALT:
            halted_ = true;
            break;

        default:
            std::cout << "INSTRUCTION NOT FOUND!" << std::endl;
            break;
    }
}

void CPU::printRegisters() const
{
    std::cout << "Registers: ";

    for (int i = 0; i < registers_.size(); i++)
    {
        std::cout << "R" << i << " = "
                  << static_cast<int>(registers_[i]) << " ";
    }

    std::cout << '\n';
}

void CPU::printStep(const DecodedInstruction& instruction) const
{
    std::cout << "PC: " << static_cast<int>(pc_)
              << " | Opcode: "
              << static_cast<int>(instruction.opCode)
              << " | R" << static_cast<int>(instruction.reg1)
              << " | R" << static_cast<int>(instruction.reg2)
              << '\n';
}