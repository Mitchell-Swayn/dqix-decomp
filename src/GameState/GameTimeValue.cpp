#include "GameState/GameState.h"

extern "C" void func_020103c8(GameState* state, float value)
{
    if (!(value < 0.0f))
        state->unknown_3e0_ = value;
}

extern "C" float func_020103e8(GameState* state)
{
    return state->unknown_3e0_;
}
