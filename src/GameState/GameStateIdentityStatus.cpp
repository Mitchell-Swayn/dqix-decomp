#include "GameState/GameState.h"

#if defined(usa)

typedef char GameStateIdentityWordOffsetCheck[
    offsetof(GameState, unknown_7f6c_) == 0x7f6c ? 1 : -1];
typedef char GameStateIdentityByteOffsetCheck[
    offsetof(GameState, unknown_7f70_) == 0x7f70 ? 1 : -1];
typedef char GameStateIdentityStatusStateSizeCheck[
    sizeof(GameState) == 0x7ff4 ? 1 : -1];

extern "C" GameStateIndexedRecord* GameState_FindCharacterStateByObjectIndex(GameState* state, int index);

// Original: arm9/main @ 0x02011FF0; symbol: func_02011ff0; size: 0x20.
extern "C" unsigned int GameState_ReadIndexedRecordLowNibble(GameState* state, int index)
{
    GameStateIndexedRecord* record = GameState_FindCharacterStateByObjectIndex(state, index);
    if (record != NULL)
        return record->lowNibble_56b_;
    return 0;
}

// Original: arm9/main @ 0x02012010; symbol: func_02012010; size: 0xC.
extern "C" void GameState_SetUnknown7f6c(GameState* state, unsigned int value)
{
    state->unknown_7f6c_ = value;
}

// Original: arm9/main @ 0x0201201C; symbol: func_0201201c; size: 0xC.
extern "C" unsigned int GameState_GetStartupDispatchMode(GameState* state)
{
    return state->unknown_7f6c_;
}

// Original: arm9/main @ 0x02012028; symbol: func_02012028; size: 0xC.
extern "C" void GameState_WriteUnknownF70(GameState* state, unsigned char value)
{
    state->unknown_7f70_ = value;
}

// Original: arm9/main @ 0x02012034; symbol: func_02012034; size: 0xC.
extern "C" unsigned int GameState_ReadUnknown7f70(GameState* state)
{
    return state->unknown_7f70_;
}

#endif
