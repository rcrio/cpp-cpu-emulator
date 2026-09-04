#include "ProgramEncoder.h"

#include <fstream>
#include <sstream>
#include <bitset>
#include <stdexcept>

#include "OpCode.h"

ProgramEncoder::ProgramEncoder()
{

}

bool ProgramEncoder::encodeFile(
    const std::string& inputPath,
    const std::string& outputPath)
{
    std::ifstream inputFile(inputPath);

    if (!inputFile)
        return false;

    std::ofstream outputFile(outputPath);

    if (!outputFile)
        return false;

    std::string line;

    while (std::getline(inputFile, line))
    {
        uint16_t encodedInstruction = encodeLine(line);

        outputFile << std::bitset<8>(encodedInstruction) << '\n';
    }

    return true;
}

uint16_t ProgramEncoder::encodeLine(const std::string& line)
{
    std::istringstream stream(line);

    std::string instruction;
    std::string operand1;
    std::string operand2;

    stream >> instruction >> operand1 >> operand2;

    uint8_t opcode = encodeOpcode(instruction);
    uint8_t reg1 = 0;
    uint8_t reg2 = 0;

    if (!operand1.empty())
        reg1 = encodeRegister(operand1);

    if (!operand2.empty())
        reg2 = encodeRegister(operand2);

    uint16_t encoded = 0x0;

    encoded |= static_cast<uint16_t>(opcode) << 4;
    encoded |= static_cast<uint16_t>(reg1) << 2;
    encoded |= static_cast<uint16_t>(reg2);

    return encoded;
}

uint8_t ProgramEncoder::encodeOpcode(
    const std::string& instruction)
{   
    return static_cast<uint8_t>(stringToOpCode(instruction));
}

uint8_t ProgramEncoder::encodeRegister(
    const std::string& reg)
{
    if (reg == "R0")
        return 0x0;

    if (reg == "R1")
        return 0x1;

    if (reg == "R2")
        return 0x2;

    if (reg == "R3")
        return 0x3;

    return 0;
}