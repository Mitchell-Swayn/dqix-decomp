#include "World/WorldPlacementPaths.h"
#include "World/WorldPlacementSource.h"

extern "C" int func_0208e444(Script::Parameter*, int);

Script::OpcodeLookupEntry gSpecialPlacementOpcodes[3] = {
    {102, WorldPlacementSource::ReadSpecialRecord},
    {104, func_0208e444},
    {0, 0}
};
Script::OpcodeLookupEntry gFieldPlacementOpcodes[5] = {
    {100, WorldPlacementSource::AcceptOpcode100},
    {101, WorldPlacementSource::AcceptOpcode101},
    {102, WorldPlacementSource::ReadRecord},
    {103, WorldPlacementSource::ReadVariantTable},
    {0, 0}
};
WorldPlacementPaths gWorldPlacementPaths = {
    "R01M07", "data/bin/izmitm.bin", "%sflditem.bin",
    "data/scenario/flditem.pac", "fldbias.bin"
};
