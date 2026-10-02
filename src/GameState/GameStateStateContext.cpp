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
    char* bytes = (char*)state;
    *(unsigned int*)(bytes + 0x3b4) = 0x21;
    *(unsigned int*)(bytes + 0x3b8) = 0x21;
    *(unsigned short*)(bytes + 0x3bc) = 0x1000;
    *(unsigned int*)(bytes + 0x3c4) = 2;
    *(unsigned int*)(bytes + 0x3c0) = 0x2000;
}
