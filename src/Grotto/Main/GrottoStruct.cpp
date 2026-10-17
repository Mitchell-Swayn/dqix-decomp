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

extern "C" void Object_QueueA1RecordForEligibleGlobalState();
extern "C" void Network_QueueGrottoStateRecord(int, int);

// Original: arm9/main @ 0x0201165C; symbol: func_0201165c; size: 0x6C.
extern "C" void GameState_ConfigureActiveGrottoEntranceAndMetadata(GameState* state, const TreasureMapMetadata* metadata,
                              unsigned int entranceZoneId, Vector3i position,
                              unsigned char environ, unsigned char monsterRank)
{
    MI_CpuCopy8(metadata, &state->grottoInfo_.activeMapData, 0x1c);
    state->grottoInfo_.entranceZoneId = entranceZoneId;
    state->grottoInfo_.entrancePosition.x = position.x;
    state->grottoInfo_.entrancePosition.y = position.y;
    state->grottoInfo_.entrancePosition.z = position.z;
    state->grottoInfo_.activeEnviron = environ;
    state->grottoInfo_.activeStartingMonsterRank = monsterRank;
    state->grottoInfo_.unknown_0[0] = 1;
    state->grottoInfo_.unknown_0[1] = 1;
}

// Original: arm9/main @ 0x020116C8; symbol: func_020116c8; size: 0x70.
extern "C" void GameState_ResetGrottoAndTreasureMapInitialFlags(GameState* state)
{
    state->grottoInfo_.unknown_0[0] = 0;
    state->grottoInfo_.unknown_0[1] = 0;
    TreasureMapCollection collection;
    GameState_CopyTreasureMapMetadataCollection(&collection);
    for (int i = 0; i < collection.numMaps; ++i)
        collection.maps[i].ClearInitialByteUnknownBit();
    GameState_CopyGrottoMetadataCollection(&collection);
    Object_QueueA1RecordForEligibleGlobalState();
    Network_QueueGrottoStateRecord(-1, 0);
}

#endif

// USA: func_02011738
// JPN: func_020114a8
// Original: arm9/main @ 0x02011738; symbol: _ZN9GameState15GetGrottoStructEv; size: 0xC.
GrottoStruct* GameState::GetGrottoStruct()
{
    return &grottoInfo_;
}

#if defined(usa)

// Original: arm9/main @ 0x02011744; symbol: func_02011744; size: 0x88.
extern "C" void GameState_CopyMarkedTreasureMapToActiveGrotto(GameState* state)
{
    if (state->grottoInfo_.unknown_0[0] != 0) {
        TreasureMapCollection collection;
        GameState_CopyTreasureMapMetadataCollection(&collection);
        for (int i = 0; i < collection.numMaps; ++i) {
            if (collection.maps[i].GetInitialByteUnknownBit()) {
                MI_CpuCopy8(&state->grottoInfo_.activeMapData,
                                          &collection.maps[i], 0x1c);
                GameState_CopyGrottoMetadataCollection(&collection);
                break;
            }
        }
    }
}

// Original: arm9/main @ 0x020117CC; symbol: func_020117cc; size: 0x24.
extern "C" void GameState_LoadActiveGrottoMetadataFromDetailed(GameState* state, DetailedTreasureMapData* detail)
{
    state->grottoInfo_.LoadActiveMetadataFromDetailed(detail);
    state->grottoInfo_.activeMapData.SetInitialByteUnknownBit();
}

#endif
