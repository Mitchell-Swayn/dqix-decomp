#include "World/Zone3DContainers.h"
#include "Grotto/Main/TileFeatures.h"
#include "std_library_functions.h"

// Original: arm9/main @ 0x02013490; symbol: _Z19ResetGrottoTileDataP14GrottoTileData; size: 0x50.
void ResetGrottoTileData(GrottoTileData* tile)
{
    tile->bmdj = NULL;
    tile->rotationAngle = 0;
    tile->featurePlacement.tileID = 0;
    memset(tile->featurePlacement.directionBitmasks, 0, 9);
    memset(tile->featurePlacement.tilename, 0, 5);
    MTX_Identity33_(&tile->rotationMatrix);
    tile->centrePosition.x = 0;
    tile->centrePosition.y = 0;
    tile->centrePosition.z = 0;
}
