#include "GameState/GameState.h"

typedef char GameStateIndexedRecordSizeCheck[
    sizeof(GameStateIndexedRecord) == 0x964 ? 1 : -1];
typedef char GameStateIndexedRecordsOffsetCheck[
    offsetof(GameState, indexedRecords_) == 0x474 ? 1 : -1];
typedef char GameStateIndexedRecordIndexOffsetCheck[
    offsetof(GameStateIndexedRecord, objectIndex_) == 0x568 ? 1 : -1];
typedef char GameStateIndexListOffsetCheck[
    offsetof(GameState, indexList_) == 0x2a04 ? 1 : -1];
typedef char GameStateIndexListCountOffsetCheck[
    offsetof(GameState, indexList_) + offsetof(GameStateIndexList, count_) ==
    0x3980 ? 1 : -1];

extern "C" GameObject* GameState_GetValidObjectByIndex(GameState* state, int index);

// Original: arm9/main @ 0x02010828; symbol: func_02010828; size: 0xC.
extern "C" void* GameState_GetIndexList(GameState* state)
{
    return &state->indexList_;
}

// Original: arm9/main @ 0x02010834; symbol: func_02010834; size: 0x5C.
extern "C" void GameState_CopyIndexedObjectList(GameState* state, int index,
                              int* indices, int* count)
{
    int valid = index >= 0 && index <= 3;
    if (!valid)
        return;
    unsigned char i;
    GameStateIndexList* list = &state->indexList_;
    for (i = 0; i < list->count_; ++i)
        indices[i] = list->objectIndices_[i];
    *count = list->count_;
}

// Original: arm9/main @ 0x02010890; symbol: func_02010890; size: 0x48.
extern "C" void GameState_CollectPresentIndicesAmongFirstFour(GameState* state, int* indices, int* count)
{
    unsigned int found = 0;
    int i = 0;
    for (; i < 4; ++i) {
        if (GameState_GetValidObjectByIndex(state, i) != NULL) {
            indices[found] = i;
            ++found;
        }
    }
    *count = found;
}

// Original: arm9/main @ 0x020108D8; symbol: func_020108d8; size: 0x18.
extern "C" GameStateIndexedRecord* GameState_ReadIndexedRecordsIndex(GameState* state, int index)
{
    return state->indexedRecords_ + index;
}

// Original: arm9/main @ 0x020108F0; symbol: func_020108f0; size: 0x64.
extern "C" GameStateIndexedRecord* GameState_FindRecordByObjectIndex(GameState* state, int index)
{
    if (index < 0 || index >= 4)
        return NULL;
    for (int i = 0; i < 4; ++i) {
        if (state->indexedRecords_[i].objectIndex_ == index)
            return state->indexedRecords_ + i;
    }
    return NULL;
}

// Original: arm9/main @ 0x02010954; symbol: func_02010954; size: 0x48.
extern "C" GameStateIndexedRecord* GameState_FindUnusedIndexedRecord(GameState* state)
{
    for (int i = 0; i < 4; ++i) {
        if (state->indexedRecords_[i].objectIndex_ < 0)
            return state->indexedRecords_ + i;
    }
    return NULL;
}
