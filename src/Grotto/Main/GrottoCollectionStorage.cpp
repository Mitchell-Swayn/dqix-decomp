#include "GameState/GameState.h"
#include "System/Memory.h"

#if defined(usa)

typedef char GrottoCollectionStorageOffsetCheck[
    offsetof(GameState, grottoInfo_) +
    offsetof(GrottoStruct, metadataCollection_) == 0x64f4 ? 1 : -1];
typedef char GrottoCollectionStorageSizeCheck[
    sizeof(TreasureMapCollection) == 0xad6 ? 1 : -1];

extern "C" int func_020ac734(const TreasureMapCollection* collection)
{
    GameState* state = GameState::GetInstance();
    VectorizedInvertedMemcpy(collection, &state->grottoInfo_.metadataCollection_,
                              sizeof(TreasureMapCollection));
    return 1;
}

extern "C" int func_020ac760(TreasureMapCollection* collection)
{
    GameState* state = GameState::GetInstance();
    VectorizedInvertedMemcpy(&state->grottoInfo_.metadataCollection_, collection,
                              sizeof(TreasureMapCollection));
    return 1;
}

extern "C" int func_020ac78c(unsigned char* count)
{
    GameState* state = GameState::GetInstance();
    VectorizedInvertedMemcpy(&state->grottoInfo_.metadataCollection_.numMaps,
                              count, 1);
    return 1;
}

#endif
