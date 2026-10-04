#include "GameState/GameState.h"
#include "System/Memory.h"

#if defined(usa)

typedef char TreasureMapCollectionSizeCheck[
    sizeof(TreasureMapCollection) == 0xad6 ? 1 : -1];
typedef char GrottoStructActiveMapOffsetCheck[
    offsetof(GrottoStruct, activeMapData) == 0x6c ? 1 : -1];
typedef char GrottoStructCollectionOffsetCheck[
    offsetof(GrottoStruct, metadataCollection_) == 0x110 ? 1 : -1];
typedef char GameStateGrottoStructOffsetCheck[
    offsetof(GameState, grottoInfo_) == 0x63e4 ? 1 : -1];
typedef char GameStateGrottoSizeCheck[sizeof(GameState) == 0x7ff4 ? 1 : -1];

extern "C" void func_ov017_021cfabc();
extern "C" void func_ov017_021cf730(int, int);

extern "C" void func_0201165c(GameState* state, const TreasureMapMetadata* metadata,
                              unsigned int entranceZoneId, Vector3i position,
                              unsigned char environ, unsigned char monsterRank)
{
    VectorizedInvertedMemcpy(metadata, &state->grottoInfo_.activeMapData, 0x1c);
    state->grottoInfo_.entranceZoneId = entranceZoneId;
    state->grottoInfo_.entrancePosition.x = position.x;
    state->grottoInfo_.entrancePosition.y = position.y;
    state->grottoInfo_.entrancePosition.z = position.z;
    state->grottoInfo_.activeEnviron = environ;
    state->grottoInfo_.activeStartingMonsterRank = monsterRank;
    state->grottoInfo_.unknown_0[0] = 1;
    state->grottoInfo_.unknown_0[1] = 1;
}

extern "C" void func_020116c8(GameState* state)
{
    state->grottoInfo_.unknown_0[0] = 0;
    state->grottoInfo_.unknown_0[1] = 0;
    TreasureMapCollection collection;
    func_020ac760(&collection);
    for (int i = 0; i < collection.numMaps; ++i)
        collection.maps[i].ClearInitialByteUnknownBit();
    func_020ac734(&collection);
    func_ov017_021cfabc();
    func_ov017_021cf730(-1, 0);
}

#endif

// USA: func_02011738
// JPN: func_020114a8
GrottoStruct* GameState::GetGrottoStruct()
{
    return &grottoInfo_;
}

#if defined(usa)

extern "C" void func_02011744(GameState* state)
{
    if (state->grottoInfo_.unknown_0[0] != 0) {
        TreasureMapCollection collection;
        func_020ac760(&collection);
        for (int i = 0; i < collection.numMaps; ++i) {
            if (collection.maps[i].GetInitialByteUnknownBit()) {
                VectorizedInvertedMemcpy(&state->grottoInfo_.activeMapData,
                                          &collection.maps[i], 0x1c);
                func_020ac734(&collection);
                break;
            }
        }
    }
}

extern "C" void func_020117cc(GameState* state, DetailedTreasureMapData* detail)
{
    state->grottoInfo_.LoadActiveMetadataFromDetailed(detail);
    state->grottoInfo_.activeMapData.SetInitialByteUnknownBit();
}

#endif
