#ifndef OPCODE_H
#define OPCODE_H

#include <cstdint>
#include <string>
#include <stdexcept>

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

// Used by ProgramEncoder
inline OpCode stringToOpCode(const std::string& name)
{
    if (name == "NOP")   return OpCode::NOP;
    if (name == "MOV")   return OpCode::MOV;
    if (name == "LOAD")  return OpCode::LOAD;
    if (name == "STORE") return OpCode::STORE;
    if (name == "ADD")   return OpCode::ADD;
    if (name == "SUB")   return OpCode::SUB;
    if (name == "AND")   return OpCode::AND;
    if (name == "OR")    return OpCode::OR;
    if (name == "XOR")   return OpCode::XOR;
    if (name == "JMP")   return OpCode::JMP;
    if (name == "JZ")    return OpCode::JZ;
    if (name == "HALT")  return OpCode::HALT;

    throw std::invalid_argument("Unknown opcode: " + name);
}

#endif