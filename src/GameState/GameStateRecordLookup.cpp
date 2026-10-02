#include "GameState/GameState.h"

typedef char GameStateIndexedRecordSizeCheck[
    sizeof(GameStateIndexedRecord) == 0x964 ? 1 : -1];
typedef char GameStateIndexedRecordsOffsetCheck[
    offsetof(GameState, indexedRecords_) == 0x474 ? 1 : -1];
typedef char GameStateIndexedRecordIndexOffsetCheck[
    offsetof(GameStateIndexedRecord, objectIndex_) == 0x568 ? 1 : -1];
typedef char GameStateIndexListOffsetCheck[
    offsetof(GameState, unk_2a04) == 0x2a04 ? 1 : -1];
typedef char GameStateIndexListCountOffsetCheck[
    offsetof(GameState, unknownObjectIndexCount_3980_) == 0x3980 ? 1 : -1];

// The list is embedded in the state block returned by func_02010828.
struct GameStateIndexList {
    char unknown_000[0xf78];
    unsigned char indices[4];
    unsigned char count;
};

extern "C" GameObject* func_0200ff94(GameState* state, int index);

extern "C" void* func_02010828(GameState* state)
{
    return state->unk_2a04;
}

extern "C" void func_02010834(GameState* state, int index,
                              int* indices, int* count)
{
    int valid = index >= 0 && index <= 3;
    if (!valid)
        return;
    unsigned char i;
    GameStateIndexList* list = (GameStateIndexList*)state->unk_2a04;
    for (i = 0; i < list->count; ++i)
        indices[i] = list->indices[i];
    *count = list->count;
}

extern "C" void func_02010890(GameState* state, int* indices, int* count)
{
    unsigned int found = 0;
    int i = 0;
    for (; i < 4; ++i) {
        if (func_0200ff94(state, i) != NULL) {
            indices[found] = i;
            ++found;
        }
    }
    *count = found;
}

extern "C" GameStateIndexedRecord* func_020108d8(GameState* state, int index)
{
    return state->indexedRecords_ + index;
}

extern "C" GameStateIndexedRecord* func_020108f0(GameState* state, int index)
{
    if (index < 0 || index >= 4)
        return NULL;
    for (int i = 0; i < 4; ++i) {
        if (state->indexedRecords_[i].objectIndex_ == index)
            return state->indexedRecords_ + i;
    }
    return NULL;
}

extern "C" GameStateIndexedRecord* func_02010954(GameState* state)
{
    for (int i = 0; i < 4; ++i) {
        if (state->indexedRecords_[i].objectIndex_ < 0)
            return state->indexedRecords_ + i;
    }
    return NULL;
}
