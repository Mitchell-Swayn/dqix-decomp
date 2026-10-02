#pragma once
#include "Resource/Script.h"

// Layout carrier for the original contiguous mutable path pool.
struct WorldPlacementPaths
{
    char specialMap[7];
    char specialFile[20];
    char mapFile[14];
    char archive[26];
    char variants[13];
};
extern WorldPlacementPaths gWorldPlacementPaths;
extern Script::OpcodeLookupEntry gSpecialPlacementOpcodes[3];
extern Script::OpcodeLookupEntry gFieldPlacementOpcodes[5];
