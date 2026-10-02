#include "GameState/GameState.h"

#if defined(usa)

typedef char GameStateIdentityWordOffsetCheck[
    offsetof(GameState, unknown_7f6c_) == 0x7f6c ? 1 : -1];
typedef char GameStateIdentityByteOffsetCheck[
    offsetof(GameState, unknown_7f70_) == 0x7f70 ? 1 : -1];
typedef char GameStateIdentityStatusStateSizeCheck[
    sizeof(GameState) == 0x7ff4 ? 1 : -1];

extern "C" GameStateIndexedRecord* func_020108f0(GameState* state, int index);

extern "C" unsigned int func_02011ff0(GameState* state, int index)
{
    GameStateIndexedRecord* record = func_020108f0(state, index);
    if (record != NULL)
        return record->lowNibble_56b_;
    return 0;
}

extern "C" void func_02012010(GameState* state, unsigned int value)
{
    state->unknown_7f6c_ = value;
}

extern "C" unsigned int func_0201201c(GameState* state)
{
    return state->unknown_7f6c_;
}

extern "C" void func_02012028(GameState* state, unsigned char value)
{
    state->unknown_7f70_ = value;
}

extern "C" unsigned int func_02012034(GameState* state)
{
    return state->unknown_7f70_;
}

#endif
