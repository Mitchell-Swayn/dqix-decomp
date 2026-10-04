#include "World/Zone3DContainers.h"
#include "Grotto/Main/TileFeatures.h"
#include "std_library_functions.h"

void ResetGrottoTileData(GrottoTileData* tile)
{
    tile->bmdj = NULL;
    tile->rotationAngle = 0;
    tile->featurePlacement.tileID = 0;
    memset(tile->featurePlacement.directionBitmasks, 0, 9);
    memset(tile->featurePlacement.tilename, 0, 5);
    Mat3x3_WriteIdentity(&tile->rotationMatrix);
    tile->centrePosition.x = 0;
    tile->centrePosition.y = 0;
    tile->centrePosition.z = 0;
}
