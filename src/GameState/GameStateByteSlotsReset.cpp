#include "GameState/GameState.h"

#if defined(usa)

typedef char GameStateByteSlotsSizeCheck[
    sizeof(GameStateByteSlots) == 7 ? 1 : -1];
typedef char GameStateByteSlotsOffsetCheck[
    offsetof(GameState, byteSlots_7f74_) == 0x7f74 ? 1 : -1];

// Original: arm9/main @ 0x0200FB40; symbol: func_0200fb40; size: 0x44.
extern "C" void GameState_ClearByteSlots(GameState* state)
{
    state->byteSlots_7f74_.unknown_00_ = 0;
    state->byteSlots_7f74_.unknown_01_ = 0;
    for (unsigned char i = 0; i < 4; ++i)
        state->byteSlots_7f74_.bytes_02_[i] = 0;
    state->byteSlots_7f74_.unknown_06_ = 0;
}

#endif
