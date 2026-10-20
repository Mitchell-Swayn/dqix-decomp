#include "World/WorldPlacementPersistentData.h"
#include "World/WorldPlacementSource.h"

extern "C" {
    int WorldPlacement_IgnoreOpcode100(Script::Parameter*, int);
    int WorldPlacement_IgnoreOpcode101(Script::Parameter*, int);
    int WorldPlacement_ReadPersistentStateRecord(Script::Parameter*, int);
}

// Initialization parses each field script through a distinct record reader.
WorldPlacementPersistentData gWorldPlacementPersistentData = {
    {
        {100, WorldPlacement_IgnoreOpcode100},
        {101, WorldPlacement_IgnoreOpcode101},
        {102, WorldPlacement_ReadPersistentStateRecord},
        {103, WorldPlacementSource::ReadVariantTable},
        {0, 0}
    },
    "data/scenario/flditem.pac", "fldbias.bin", "F%02dflditem.bin"
};
