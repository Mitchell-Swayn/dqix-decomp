#include "GameState/GameState.h"

extern "C" void func_020100a0(GameState* state, int index)
{
    state->protagonistObjectIndex_ = index;
}

extern "C" int func_020100a8(GameState* state)
{
    return state->protagonistObjectIndex_;
}

extern "C" unsigned char func_020100b0(GameState* state)
{
#if defined(usa)
    return state->indexList_.objectIndices_[0];
#else
    return state->unknownObjectIndex_397c_;
#endif
}

extern "C" void* func_020100bc(GameState* state)
{
    return state->unknown_3b0_;
}

extern "C" void func_020100c4(GameState* state, void* value)
{
    state->unknown_3b0_ = value;
}
