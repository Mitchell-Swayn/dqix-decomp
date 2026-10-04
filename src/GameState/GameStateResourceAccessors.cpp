#include "GameState/GameState.h"

// Preserve the original C-linkage entry points while using the observed
// GameState layout: resource pointer at offset 0 and a byte field at offset 4.
extern "C" void func_0200fb84(GameState* state, GameResources* resources)
{
    state->pResources_ = resources;
}

extern "C" GameResources* func_0200fb8c(GameState* state)
{
    return state->pResources_;
}

extern "C" void func_0200fb94(GameState* state, unsigned char value)
{
    state->unk_4[0] = value;
}

extern "C" unsigned char func_0200fb9c(GameState* state)
{
    return (unsigned char)state->unk_4[0];
}
