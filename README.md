# CPU Emulator

A simple CPU emulator for both practicing C++ and refreshing knowledge on CPU architecture.

`docs` has a `manual.md` has information regarding the CPU.

## Specifications
- 8-bit instructions
- 8-bit registers (8-bit architecture)
- 9 instructions implemented (16 possible instructions due to a 4-bit opCode)
- Reads a `program.txt` file and converts it to `program_binary.txt`

## To-do
- Make the CPU actually run `program_binary.txt`
- Increase instruction width to 16-bit to support instructions that need an immediate value or address, such as `JMP`, `JZ`, and `STORE`. Will need to edit
- Change the `ProgramEncoder` to read 
- Finish project setup in README.md

## Project setup
- TBA