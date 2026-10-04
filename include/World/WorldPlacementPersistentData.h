#pragma once
#include "Resource/Script.h"

// Original contiguous initialization opcode table and writable path pool.
struct WorldPlacementPersistentData
{
    Script::OpcodeLookupEntry opcodes[5];
    char archive[26];
    char variants[12];
    char field[18]; // includes one trailing padding byte after the terminator
};
extern WorldPlacementPersistentData gWorldPlacementPersistentData;

// Linker-defined names of the original path subobjects; no extra storage.
extern "C" {
    extern char data_020f1330[26];
    extern char data_020f134a[12];
    extern char data_020f1356[18];
}
