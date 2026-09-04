#ifndef PROGRAM_ENCODER_H
#define PROGRAM_ENCODER_H

#include <cstdint>
#include <string>

class ProgramEncoder
{
public:
    ProgramEncoder();

    // Read a human-readable program and write encoded instructions.
    bool encodeFile(
        const std::string& inputPath,
        const std::string& outputPath
    );

private:
    // Encode one line, e.g. "ADD R0 R1".
    uint16_t encodeLine(const std::string& line);

    // Convert things like "ADD" into an opcode.
    uint8_t encodeOpcode(const std::string& instruction);

    // Convert things like "R0" into a register number.
    uint8_t encodeRegister(const std::string& reg);
};

#endif