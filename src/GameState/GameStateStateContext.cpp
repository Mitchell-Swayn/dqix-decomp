#include "GameState/GameState.h"

extern "C" unsigned int func_0202e09c(void* value);

extern "C" void* func_020100cc(GameState* state)
{
    if (state->unknown_3b0_ != NULL &&
        (func_0202e09c(state->unknown_3b0_) & 2))
        return state->unknown_3b0_;
    return NULL;
}

extern "C" void* func_020100f8(GameState* state)
{
    if (state->unknown_3b0_ != NULL &&
        (func_0202e09c(state->unknown_3b0_) & 4))
        return state->unknown_3b0_;
    return NULL;
}

extern "C" void func_02010124(GameState* state)
{
    state->effectiveDeltaTimeMilliseconds_ = 0x21;
    state->trueDeltaTimeMilliseconds_ = 0x21;
    state->gameSpeed_ = 0x1000;
    state->numTicks_ = 2;
    state->animationDeltaTime_ = 0x2000;
}
