// Original locations for overloaded or compiler-generated definitions in this unit:
// Original: arm9/main @ 0x02019F24; symbol: _ZN24TileFeaturePlacementDataaSERKS_; size: 0x48. (TileFeaturePlacementData::operator=(TileFeaturePlacementData const&))
#include "World/Zone3DPaths.h"
#include <globaldefs.h>
#include "Grotto/Main/TileFeatures.h"
#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

#ifdef jpn
#define Zone3DGetGrottoObjectPositionOrientation_UnknownRoleInitializedBytes data_020e77a4

#define ProgramData_TextW01A data_020ef1b0
#define ProgramData_TextW02A data_020ef1b5
#define ProgramData_TextW03A data_020ef1ba
#define ProgramData_TextW04A data_020ef1bf
#define ProgramData_TextE01A data_020ef1c4
#define ProgramData_TextR01A data_020ef1c9
#define ProgramData_TextR02A data_020ef1ce
#define ProgramData_TextR03A data_020ef1d3
#define ProgramData_TextR04A data_020ef1d8
#define ProgramData_TextR05A data_020ef1dd
#define ProgramData_TextD01A data_020ef1e2
#define ProgramData_TextD02A data_020ef1e7
#define ProgramData_TextD03A data_020ef1ec
#define ProgramData_TextD04A data_020ef1f1

#define func_0201e434 func_0201e1c0
#endif

extern "C"
{
    // get timer (seconds since game start?)
    void GameState_ComputeElapsedMainTimestamp(GameState*, int*);
    void* Network_GetConnectionManager();
}

struct RelativePosition
{
    fix32_t x;
    fix32_t y;
};

extern const char ProgramData_TextW01A[], ProgramData_TextW02A[], ProgramData_TextW03A[],
    ProgramData_TextW04A[], ProgramData_TextE01A[], ProgramData_TextR01A[], ProgramData_TextR02A[],
    ProgramData_TextR03A[], ProgramData_TextR04A[], ProgramData_TextR05A[], ProgramData_TextD01A[],
    ProgramData_TextD02A[], ProgramData_TextD03A[], ProgramData_TextD04A[];

// Original data: arm9/main @ 0x20e6f00; symbol: data_020e6f00.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 56d5ffff.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const RelativePosition Zone3DGetGrottoObjectPositionOrientation_UnknownRoleInitializedBytes[];
extern char const ProgramData_TextR02A[];

// Original: arm9/main @ 0x02019728; symbol: _ZN6Zone3D22ComputeGrottoTileTypesEiP12ZoneFeaturesP24TileFeaturePlacementDataP8FloorMap; size: 0x7FC.
int Zone3D::ComputeGrottoTileTypes(int floor, ZoneFeatures *featuresArg, TileFeaturePlacementData *output, FloorMap *floorMapArg)
{
    ZoneFeatures* features = (featuresArg == NULL) ? &bFeatures_ : featuresArg;
    FloorMap* floorMap = (floorMapArg == NULL) ? &grotto_.floorMap_ : floorMapArg;

    
    char tileName[8] = {0};
    int tileType = 0;
    fix32_t rotationAngle;

    for (int tileY = 0; tileY < 16; tileY++)
    {
        for (int tileX = 0; tileX < 16; tileX++)
        {
            // joining us today on stupid code is a struct with a single volatile write!
            struct { unsigned char x; union { volatile unsigned char y; unsigned char y2;}; } adj;
            adj.x = floorMap->GetAdjacencyBits(tileX, tileY);
            adj.y = adj.x;
            Matrix3x3 tileRotationMatrix;
            GrottoTileData* extendedEntry = grottoTileMapData_420_ + 16 * tileY + tileX;
            MTX_Identity33_(&tileRotationMatrix);
            switch (adj.y2)
            {
            case 0xff:
                tileType = 12;
                sprintf(tileName, gZone3DPaths.zoneF01A);
                break;
            case 0xbb: case 0xee:
                tileType = 3;
                sprintf(tileName, ProgramData_TextW01A);
                break;
            case 0xaf: case 0xbe: case 0xeb: case 0xfa:
                tileType = 2;
                sprintf(tileName, ProgramData_TextW02A);
                break;
            case 0xaa:
                tileType = 1;
                sprintf(tileName, ProgramData_TextW03A);
                break;
            case 0xba: case 0xae: case 0xab: case 0xea:
                tileType = 0;
                sprintf(tileName, ProgramData_TextW04A);
                break;
            case 0xbf: case 0xef: case 0xfb: case 0xfe:
                tileType = 13;
                sprintf(tileName, ProgramData_TextE01A);
                break;
            case 0x38: case 0x0e: case 0x83: case 0xe0:
                tileType = 10;
                sprintf(tileName, ProgramData_TextR01A);
                break;
            case 0x8f: case 0x3e: case 0xf8: case 0xe3:
                tileType = 9;
                sprintf(tileName, ProgramData_TextR02A);
                break;
            case 0x20: case 0x08: case 0x02: case 0x80:
                tileType = 8;
                sprintf(tileName, ProgramData_TextR03A);
                break;
            case 0:
                tileType = 7;
                sprintf(tileName, ProgramData_TextR04A);
                break;
            case 0x22: case 0x88:
                tileType = 6;
                sprintf(tileName, ProgramData_TextR05A);
                break;
            case 0x0a: case 0x28: case 0xa0: case 0x82:
                tileType = 17;
                sprintf(tileName, ProgramData_TextD01A);
                break;
            case 0x8e: case 0x3a: case 0xe8: case 0xa3:
                tileType = 16;
                sprintf(tileName, ProgramData_TextD02A);
                break;
            case 0x2e: case 0x8b: case 0xe2: case 0xb8:
                tileType = 15;
                sprintf(tileName, ProgramData_TextD03A);
                break;
            case 0x2a: case 0x8a: case 0xa2: case 0xa8:
                tileType = 14;
                sprintf(tileName, ProgramData_TextD04A);
                break;
            }

            if (output == NULL)
            {
                extendedEntry->bmdj = GetBMDJGroupAtIndex(tileType);
                TileFeaturePlacementData* knownData = features->GetGrottoTileFeaturePlacementEntry(tileName);
                if (knownData != NULL)
                    extendedEntry->featurePlacement = *knownData;
            }
            else
            {
                TileFeaturePlacementData* knownData = features->GetGrottoTileFeaturePlacementEntry(tileName);
                if (knownData != NULL && output != NULL)
                    *(output + 16 * tileY + tileX) = *knownData;    
            }
            rotationAngle = 0;
            int tileDirection = 0;
            switch (adj.y2)
            {
            case 0x02: case 0x82: case 0x83: case 0x88: case 0x8a: case 0x8e:
            case 0x8f: case 0xab: case 0xaf: case 0xe2: case 0xee: case 0xef:
                // East-facing tile, 90 degrees, sin = 1, cos = 0
                rotationAngle = 0x1921;
                MTX_RotY33_(&tileRotationMatrix, 1 << 12, 0);
                tileDirection = 1;
                break;
            case 0x08: case 0x0a: case 0x0e: case 0x2a: case 0x3a: 
            case 0x3e: case 0x8b: case 0xae: case 0xbe: case 0xbf:
                // South-facing tile, 180 degrees, sin = 0, cos = -1
                rotationAngle = 0x3243;
                MTX_RotY33_(&tileRotationMatrix, 0, -1 << 12);
                tileDirection = 2;
                break;
            case 0x20: case 0x28: case 0x2e: case 0x38: case 0xa8:
            case 0xba: case 0xe8: case 0xf8: case 0xfa: case 0xfe:
                // West-facing tile, 270 degrees, sin = -1, cos = 0
                rotationAngle = 0x4b65;
                MTX_RotY33_(&tileRotationMatrix, -1 << 12, 0);
                tileDirection = 3;
                break;
            case 0xff:
                break;
            default:
                rotationAngle = 0;
                break;
            }

            if (output == NULL)
            {
                extendedEntry->rotationAngle = rotationAngle;
                RotateGrottoTileFeaturePlacementData(extendedEntry->featurePlacement.directionBitmasks, tileDirection);
                extendedEntry->centrePosition.x = 4096.0f * (8.0f * tileX);
                extendedEntry->centrePosition.y = 0;
                extendedEntry->centrePosition.z = 4096.0f * (8.0f * tileY);
                extendedEntry->rotationMatrix = tileRotationMatrix;
            }
            else
            {
                RotateGrottoTileFeaturePlacementData((output + 16 * tileY + tileX)->directionBitmasks, tileDirection);
            }
        }
    }
    return 1;
}

// Original: arm9/main @ 0x02019F6C; symbol: _ZN6Zone3D36RotateGrottoTileFeaturePlacementDataEPhi; size: 0x19C.
void Zone3D::RotateGrottoTileFeaturePlacementData(unsigned char *placementArray, int numTurns)
{
    unsigned char original[9];
    memcpy(original, placementArray, 9);
    switch (numTurns)
    {
    case 1:
        placementArray[TilePlacementPoint_NW] = original[TilePlacementPoint_NE];
        placementArray[TilePlacementPoint_N] = original[TilePlacementPoint_E];
        placementArray[TilePlacementPoint_NE] = original[TilePlacementPoint_SE];
        placementArray[TilePlacementPoint_W] = original[TilePlacementPoint_N];
        placementArray[TilePlacementPoint_Center] = original[TilePlacementPoint_Center];
        placementArray[TilePlacementPoint_E] = original[TilePlacementPoint_S];
        placementArray[TilePlacementPoint_SW] = original[TilePlacementPoint_NW];
        placementArray[TilePlacementPoint_S] = original[TilePlacementPoint_W];
        placementArray[TilePlacementPoint_SE] = original[TilePlacementPoint_SW];
        for (int i = 0; i < 9; i++)
            RotateGrottoObjectDirectionBitmask(&placementArray[i], 1);
        break;
    case 2:
        placementArray[TilePlacementPoint_NW] = original[TilePlacementPoint_SE];
        placementArray[TilePlacementPoint_N] = original[TilePlacementPoint_S];
        placementArray[TilePlacementPoint_NE] = original[TilePlacementPoint_SW];
        placementArray[TilePlacementPoint_W] = original[TilePlacementPoint_E];
        placementArray[TilePlacementPoint_Center] = original[TilePlacementPoint_Center];
        placementArray[TilePlacementPoint_E] = original[TilePlacementPoint_W];
        placementArray[TilePlacementPoint_SW] = original[TilePlacementPoint_NE];
        placementArray[TilePlacementPoint_S] = original[TilePlacementPoint_N];
        placementArray[TilePlacementPoint_SE] = original[TilePlacementPoint_NW];
        for (int i = 0; i < 9; i++)
            RotateGrottoObjectDirectionBitmask(&placementArray[i], 2);
        break;
    case 3:
        placementArray[TilePlacementPoint_NW] = original[TilePlacementPoint_SW];
        placementArray[TilePlacementPoint_N] = original[TilePlacementPoint_W];
        placementArray[TilePlacementPoint_NE] = original[TilePlacementPoint_NW];
        placementArray[TilePlacementPoint_W] = original[TilePlacementPoint_S];
        placementArray[TilePlacementPoint_Center] = original[TilePlacementPoint_Center];
        placementArray[TilePlacementPoint_E] = original[TilePlacementPoint_N];
        placementArray[TilePlacementPoint_SW] = original[TilePlacementPoint_SE];
        placementArray[TilePlacementPoint_S] = original[TilePlacementPoint_E];
        placementArray[TilePlacementPoint_SE] = original[TilePlacementPoint_NE];
        for (int i = 0; i < 9; i++)
            RotateGrottoObjectDirectionBitmask(&placementArray[i], 3);
        break;
    }
}

// Original: arm9/main @ 0x0201A108; symbol: _ZN6Zone3D34RotateGrottoObjectDirectionBitmaskEPhi; size: 0x80.
void Zone3D::RotateGrottoObjectDirectionBitmask(unsigned char *mask, int numTurns)
{
    unsigned char up = *mask & 1;
    unsigned char right = (*mask & 2) >> 1;
    unsigned char down = (*mask & 4) >> 2;
    unsigned char left = (*mask & 8) >> 3;

    switch (numTurns)
    {
    case 1:
        *mask = right | (down << 1) | (left << 2) | (up << 3);
        break;
    case 2:
        *mask = down | (left << 1) | (up << 2) | (right << 3);
        break;
    case 3:
        *mask = left | (up << 1) | (right << 2) | (down << 3);
        break;
    }
}

// USA: func_0201a188
// JPN: func_02019f28
// Original: arm9/main @ 0x0201A188; symbol: _ZN6Zone3D34GetGrottoObjectPositionOrientationEiiPiS0_PK24TileFeaturePlacementDatab; size: 0x178.
int Zone3D::GetGrottoObjectPositionOrientation(int tileX, int tileY, fix32_t *outX, fix32_t *outY,
    const TileFeaturePlacementData *tileDataArray, bool preferFaceDown)
{
    const TileFeaturePlacementData* tileDataPtr;
    if (tileDataArray == NULL)
    {
        GrottoTileData* ext = grottoTileMapData_420_ + tileX + 16 * tileY;
        if (ext == NULL)
            return -1;
        tileDataPtr = &ext->featurePlacement;
    }
    else
    {
        tileDataPtr = tileDataArray + tileX + 16 * tileY;
    }
    int position = ChooseTileFeaturePosition(tileDataPtr);
    int direction = ChooseTileFeatureOrientation(tileDataPtr, position, preferFaceDown);
    if (position <= 8)
    {
        // These arrays hold 0 or +/- 10922. We have to reference them as
        // char pointers too or we get the wrong assembly
        *outX = Zone3DGetGrottoObjectPositionOrientation_UnknownRoleInitializedBytes[position].x;
        *outY = Zone3DGetGrottoObjectPositionOrientation_UnknownRoleInitializedBytes[position].y;
    }
    // data_020ef292 holds "R02A"
    if (strstr(tileDataPtr->tilename, ProgramData_TextR02A))
    {
        if (position == TilePlacementPoint_NW)
        {
            *outX = -0x34cc;
            *outY = -0x34cc;
        }
        else if (position == TilePlacementPoint_NE)
        {
            *outX = 0x34cc;
            *outY = -0x34cc;
        }
        else if (position == TilePlacementPoint_SW)
        {
            *outX = -0x34cc;
            *outY = 0x34cc;
        }
        else if (position == TilePlacementPoint_SE)
        {
            *outX = 0x34cc;
            *outY = 0x34cc;
        }
    }
    *outX += (fix32_t)(tileX * 8.0f * 4096.0f);
    *outY += (fix32_t)(tileY * 8.0f * 4096.0f);
    return direction;
}

/* // wip, come back after decomping blue chest script stuff
bool Zone3D::PlaceGrottoChestsAndDetermineContents(const void *treasureArchive)
{
    BattleStruct* battle = GetBattleStruct();
    ActiveGrottoClass* grotto = &grotto_;
    FloorMap* floorMap = &grotto->floorMap;
    void* struct0202ae18 = func_0202ae18();
    numChests_ = floorMap->chestCount;
    if (numChests_ == 0)
    {
        int timeSeconds;
        func_020105a8(battle, &timeSeconds);
        int floor = currentGrottoFloor_23ba_;
        int seed = grotto->GetActiveGrottoSeed();
        srand(timeSeconds + seed + floor);
        return false;
    }
}*/