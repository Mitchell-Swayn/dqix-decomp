#if defined(usa)
// This reconstruction uses USA-specific layout; JPN retains its original range.
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

extern "C" void func_0209a338(GameStateAttributeTable* table);
extern "C" void func_0209a3dc(GameStateAttributeTable* table, void* buffer);
extern "C" GameStateAttributeRecord* func_0209a594(
    GameStateAttributeTable* table, int identifier);

extern "C" void func_0201133c(GameState* state)
{
    memset(state->attributeTableBuffer_, 0, sizeof(state->attributeTableBuffer_));
    func_0209a338(&state->attributeTable_);
    func_0209a3dc(&state->attributeTable_, state->attributeTableBuffer_);
}

extern "C" unsigned int func_0201137c(GameState* state, int identifier)
{
    unsigned int result = 0;
    GameStateAttributeRecord* record =
        func_0209a594(&state->attributeTable_, identifier);
    if (record != NULL)
        result = (record->attributes_ << 12) >> 24;
    return result;
}

#endif // defined(usa)
