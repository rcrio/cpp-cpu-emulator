# CPU emulator

- 8-bit instructions (plan to increase to 16-bit for loading values into registers, this would mean increasing to 16-bit IR)
- 8-bit registers (8-bit architecture)
- 12 instructions (16 possible instructions)

## Instruction size
Instructions are currently of size 8-bit.
The sturcture is as below:
    // opcode | register A | register B
    // 4 bits |   2 bits   |   2 bits

## Instruction set

`NOP`

  - Opcode: `0x0`
  - Do nothing.

`MOV R1, R2`

  - Opcode: `0x1`
  - Copy the value in `R2` into `R1`.

`LOAD R1, R2`

  - Opcode: `0x2`
  - Load `R2` into `R1`.

`STORE R1, R2`

  - Opcode: `0x3`
  - Store the value in `R1` into the memory address held in `R2`.

  (Not implemented yet)

`ADD R1, R2`

  - Opcode: `0x4`
  - Add `R2` to `R1`: `R1 = R1 + R2`.

`SUB R1, R2`

  - Opcode: `0x5`
  - Subtract `R2` from `R1`: `R1 = R1 - R2`.

`AND R1, R2`

  - Opcode: `0x6`
  - Bitwise AND: `R1 = R1 & R2`.

`OR R1, R2`

  - Opcode: `0x7`
  - Bitwise OR: `R1 = R1 | R2`.

`XOR R1, R2`

  - Opcode: `0x8`
  - Bitwise XOR: `R1 = R1 ^ R2`.

`JMP R1`

  - Opcode: `0x9`
  - Jump unconditionally to the address held in `R1`.

  (Not implemented yet)

`JZ R1`

  - Opcode: `0xA`
  - Jump to the address held in `R1` if the zero flag is set.

  (Not implemented yet)

`HALT`

  - Opcode: `0xF`
  - Stop CPU execution.

## Registers
Register sizes are currently of size 8-bit.
```
CPU
├── General-purpose registers
│   ├── R0
│   ├── R1
│   ├── R2
│   └── R3
│
└── Special-purpose registers
    ├── PC  ← Program Counter
    └── IR  ← Instruction Register
```