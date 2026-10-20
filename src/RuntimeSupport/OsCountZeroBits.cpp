// SDK support (community reconstruction): OsCountZeroBits.
// Labelled SDK community assembly; excluded from C/C++ reconstruction credit.
// Reference: pret/pokeheartgold@14c48938174ec92563afc6d03de5fa162f4cfdce
// lib/NitroSDK/src/os/os_vramExclusive.c, OsCountZeroBits, lines 6-9.
// Original: arm9/main @ 0x020C9A4C; symbol: func_020c9a4c; size: 0x8.
// Counts leading zero bits in a VRAM bank bitmap (zero returns 32).
#pragma thumb off
extern "C" asm unsigned int OsCountZeroBits(unsigned int bitmap)
{
    clz r0, r0
    bx lr
}
