#include "World/WorldPlacementPersistentData.h"
#include "World/WorldPlacementSource.h"

extern "C" {
    int func_0208e884(Script::Parameter*, int);
    int func_0208e88c(Script::Parameter*, int);
    int func_0208e894(Script::Parameter*, int);
}

// Initialization parses each field script through a distinct record reader.
WorldPlacementPersistentData gWorldPlacementPersistentData = {
    {
        {100, func_0208e884},
        {101, func_0208e88c},
        {102, func_0208e894},
        {103, WorldPlacementSource::ReadVariantTable},
        {0, 0}
    },
    "data/scenario/flditem.pac", "fldbias.bin", "F%02dflditem.bin"
};
