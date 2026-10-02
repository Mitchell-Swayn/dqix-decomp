#pragma once

#include "TreasureMapMetadata.h"
#include "System/Matrix.h"

struct DetailedTreasureMapData;

// Snapshot copied to/from the save-state collection by 0x020ac734/0x020ac760.
struct TreasureMapCollection
{
    unsigned char numMaps;
    char padding;
    TreasureMapMetadata maps[99];
};

struct GrottoMetadataDescriptor
{
    unsigned char kind_;
    unsigned char value_01_;
    unsigned short value_02_;
};

// The transfer routines use this region between active metadata and the saved
// map collection. Names describe the observed layout; the values remain unknown.
struct GrottoMetadataTransferState
{
    unsigned char available_;
    unsigned char unknown_01_;
    char unknown_02_[2];
    GrottoMetadataDescriptor descriptor_;
    int unknown_08_;
    unsigned int unknown_0c_;
    unsigned char unknown_10_;
    char unknown_11_;
    unsigned short unknown_12_;
    unsigned char metadataAvailable_;
    char unknown_15_;
    TreasureMapMetadata metadata_;
    char text_32_[64];
    char unknown_72_;
    char text_73_[10];
    char text_7d_[10];
    char unknown_87_;
};

// Could probably do with a better name. This is a persistent struct
// holding data about all grottos, as opposed to the ActiveGrottoStruct
// which only holds data about a single grotto while you're inside it.
struct GrottoStruct
{
    unsigned char unknown_0[5];
    // still a bit unsure of these, though seems correct.
    unsigned char activeEnviron;
    unsigned char activeStartingMonsterRank;
    unsigned char activeMapLevel;

    unsigned char unknown_8, unknown_9;
    char unk_a[2];

    unsigned int entranceZoneId;
    Vector3i entrancePosition; // centre of the grotto entrance model
    char activeMapImageName[16]; // e.g. tmap_005
#if defined(usa)
    char activeMapNameNoLevel[64]; // e.g. Granite Tunnel of Woe
#elif defined(jpn)                 // (this is the string that appears
    char activeMapNameNoLevel[32]; // on the top screen in overworld)
#endif

    TreasureMapMetadata activeMapData;
#if defined(usa)
    GrottoMetadataTransferState metadataTransfer_;
#else
    char unk_88[0x7c]; // historical JPN layout remains unverified
#endif
    TreasureMapCollection metadataCollection_;

    void LoadActiveMetadataFromDetailed(DetailedTreasureMapData* detail);
};

class GameState;
typedef char GrottoEntrancePositionSizeCheck[sizeof(Vector3i) == 12 ? 1 : -1];
