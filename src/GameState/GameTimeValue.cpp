#include "GameState/GameState.h"

// Original: arm9/main @ 0x020103C8; symbol: func_020103c8; size: 0x20.
extern "C" void GameState_SetRequestedDayTimer(GameState* state, float value)
{
    if (!(value < 0.0f))
        state->unknown_3e0_ = value;
}

// Original: arm9/main @ 0x020103E8; symbol: func_020103e8; size: 0x8.
extern "C" float GameState_GetRequestedDayTimer(GameState* state)
{
    return state->unknown_3e0_;
}
