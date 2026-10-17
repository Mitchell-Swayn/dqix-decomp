#include "GameState/GameState.h"

typedef char GameStateAttributeRecordSizeCheck[
    sizeof(GameStateAttributeRecord) == 12 ? 1 : -1];
typedef char GameStateAttributeTableSizeCheck[
    sizeof(GameStateAttributeTable) == 8 ? 1 : -1];
typedef char GameStateAttributeTableOffsetCheck[
    offsetof(GameState, attributeTable_) == 0x572c ? 1 : -1];
typedef char GameStateAttributeTableBufferOffsetCheck[
    offsetof(GameState, attributeTableBuffer_) == 0x5734 ? 1 : -1];
typedef char GameStateAttributeTableStateSizeCheck[
    sizeof(GameState) == 0x7ff4 ? 1 : -1];

extern "C" void Initialize2RecordFields_Main0209A338(GameStateAttributeTable* table);
extern "C" void LoadAndExecuteScriptWithGlobalObject(GameStateAttributeTable* table, void* buffer);
extern "C" GameStateAttributeRecord* Object_FindIdByDirectIndexThenLinearSearch(
    GameStateAttributeTable* table, int identifier);

// Original: arm9/main @ 0x0201133C; symbol: func_0201133c; size: 0x40.
extern "C" void GameState_InitializeAttributeTableBuffer(GameState* state)
{
    memset(state->attributeTableBuffer_, 0, sizeof(state->attributeTableBuffer_));
    Initialize2RecordFields_Main0209A338(&state->attributeTable_);
    LoadAndExecuteScriptWithGlobalObject(&state->attributeTable_, state->attributeTableBuffer_);
}

// Original: arm9/main @ 0x0201137C; symbol: func_0201137c; size: 0x2C.
extern "C" unsigned int GameState_ReadAttributeBits12To19(GameState* state, int identifier)
{
    unsigned int result = 0;
    GameStateAttributeRecord* record =
        Object_FindIdByDirectIndexThenLinearSearch(&state->attributeTable_, identifier);
    if (record != NULL)
        result = (record->attributes_ << 12) >> 24;
    return result;
}
