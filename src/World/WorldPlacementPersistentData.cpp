#include "World/WorldPlacementPersistentData.h"
#include "World/WorldPlacementSource.h"

extern "C" {
    int ReturnOne_Main0208E884(Script::Parameter*, int);
    int Parameter_ReturnOne_Main0208E88C(Script::Parameter*, int);
    int WorldPlacement_ReadPersistentStateRecord(Script::Parameter*, int);
}

// Initialization parses each field script through a distinct record reader.
WorldPlacementPersistentData gWorldPlacementPersistentData = {
    {
        {100, ReturnOne_Main0208E884},
        {101, Parameter_ReturnOne_Main0208E88C},
        {102, WorldPlacement_ReadPersistentStateRecord},
        {103, WorldPlacementSource::ReadVariantTable},
        {0, 0}
    },
    "data/scenario/flditem.pac", "fldbias.bin", "F%02dflditem.bin"
};
