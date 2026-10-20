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
    extern char ResetPlacementListOrLoadPlacementResources_PathDataScenarioFlditemPac[26];
    extern char ResetPlacementListOrLoadPlacementResources_TextFldbiasBin[12];
    extern char ResetPlacementListOrLoadPlacementResources_FormatF02DflditemBin[18];
}
