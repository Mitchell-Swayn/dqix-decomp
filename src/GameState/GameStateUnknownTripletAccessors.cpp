#if defined(usa)
// This reconstruction uses USA-specific layout; JPN retains its original range.
#include "GameState/GameState.h"

extern "C" char* func_0205ec34();

typedef char GameStateSizeCheck[sizeof(GameState) == 0x7ff4 ? 1 : -1];
typedef char GameStateUnknown5cb0OffsetCheck[
    offsetof(GameState, unknown_5cb0_) == 0x5cb0 ? 1 : -1];
typedef char GameStateUnknown5cb4OffsetCheck[
    offsetof(GameState, unknown_5cb4_) == 0x5cb4 ? 1 : -1];
typedef char GameStateUnknown5cb8OffsetCheck[
    offsetof(GameState, unknown_5cb8_) == 0x5cb8 ? 1 : -1];
typedef char GameStateUnknown5cbcOffsetCheck[
    offsetof(GameState, unknown_5cbc_) == 0x5cbc ? 1 : -1];

extern "C" void func_02010774(GameState* state, unsigned int value)
{
    state->unknown_5cb0_ = value;
    char* record = func_0205ec34();
    unsigned char recordIndex = *((unsigned char*)record + 0x332);
    *((unsigned char*)record + recordIndex * 0x1c) = value;
}

extern "C" unsigned int func_0201079c(GameState* state)
{
    return state->unknown_5cb0_;
}

extern "C" void func_020107a8(GameState* state, unsigned int value)
{
    state->unknown_5cb4_ = value;
    char* record = func_0205ec34();
    unsigned char recordIndex = *((unsigned char*)record + 0x332);
    *((unsigned char*)record + recordIndex * 0x1c + 1) = value;
}

extern "C" unsigned int func_020107d0(GameState* state)
{
    return state->unknown_5cb4_;
}

extern "C" void func_020107dc(GameState* state, unsigned int value)
{
    state->unknown_5cb8_ = value;
    char* record = func_0205ec34();
    unsigned char recordIndex = *((unsigned char*)record + 0x332);
    *((unsigned char*)record + recordIndex * 0x1c + 2) = value;
}

extern "C" unsigned int func_02010804(GameState* state)
{
    return state->unknown_5cb8_;
}

extern "C" void func_02010810(GameState* state, unsigned int value)
{
    state->unknown_5cbc_ = value;
}

extern "C" unsigned int func_0201081c(GameState* state)
{
    return state->unknown_5cbc_;
}

#endif // defined(usa)
