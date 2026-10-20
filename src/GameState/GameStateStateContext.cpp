#include "GameState/GameState.h"

extern "C" unsigned int Camera_GetObjectFlags(void* value);

// Original: arm9/main @ 0x020100CC; symbol: func_020100cc; size: 0x2C.
extern "C" void* GameState_GetManualControlCamera(GameState* state)
{
    if (state->unknown_3b0_ != NULL &&
        (Camera_GetObjectFlags(state->unknown_3b0_) & 2))
        return state->unknown_3b0_;
    return NULL;
}

// Original: arm9/main @ 0x020100F8; symbol: func_020100f8; size: 0x2C.
extern "C" void* GameState_GetFieldOrbitCamera(GameState* state)
{
    if (state->unknown_3b0_ != NULL &&
        (Camera_GetObjectFlags(state->unknown_3b0_) & 4))
        return state->unknown_3b0_;
    return NULL;
}

// Original: arm9/main @ 0x02010124; symbol: func_02010124; size: 0x2C.
extern "C" void GameState_InitializeTimingDefaults(GameState* state)
{
    state->effectiveDeltaTimeMilliseconds_ = 0x21;
    state->trueDeltaTimeMilliseconds_ = 0x21;
    state->gameSpeed_ = 0x1000;
    state->numTicks_ = 2;
    state->animationDeltaTime_ = 0x2000;
}
