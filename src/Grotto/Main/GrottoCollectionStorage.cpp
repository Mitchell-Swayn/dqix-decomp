#include "GameState/GameState.h"
#include "System/Memory.h"

#if defined(usa)

typedef char GrottoCollectionStorageOffsetCheck[
    offsetof(GameState, grottoInfo_) +
    offsetof(GrottoStruct, metadataCollection_) == 0x64f4 ? 1 : -1];
typedef char GrottoCollectionStorageSizeCheck[
    sizeof(TreasureMapCollection) == 0xad6 ? 1 : -1];

// Original: arm9/main @ 0x020AC734; symbol: func_020ac734; size: 0x2C.
extern "C" int GameState_CopyGrottoMetadataCollection(const TreasureMapCollection* collection)
{
    GameState* state = GameState::GetInstance();
    MI_CpuCopy8(collection, &state->grottoInfo_.metadataCollection_,
                              sizeof(TreasureMapCollection));
    return 1;
}

// Original: arm9/main @ 0x020AC760; symbol: func_020ac760; size: 0x2C.
extern "C" int GameState_CopyTreasureMapMetadataCollection(TreasureMapCollection* collection)
{
    GameState* state = GameState::GetInstance();
    MI_CpuCopy8(&state->grottoInfo_.metadataCollection_, collection,
                              sizeof(TreasureMapCollection));
    return 1;
}

// Original: arm9/main @ 0x020AC78C; symbol: func_020ac78c; size: 0x28.
extern "C" int GameState_ReadTreasureMapCollectionCount(unsigned char* count)
{
    GameState* state = GameState::GetInstance();
    MI_CpuCopy8(&state->grottoInfo_.metadataCollection_.numMaps,
                              count, 1);
    return 1;
}

#endif
