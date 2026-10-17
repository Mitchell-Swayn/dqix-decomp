#include "GameState/GameState.h"

// Preserve the original C-linkage entry points while using the observed
// GameState layout: resource pointer at offset 0 and a byte field at offset 4.
// Original: arm9/main @ 0x0200FB84; symbol: func_0200fb84; size: 0x8.
extern "C" void GameState_SetResources(GameState* state, GameResources* resources)
{
    state->pResources_ = resources;
}

// Original: arm9/main @ 0x0200FB8C; symbol: func_0200fb8c; size: 0x8.
extern "C" GameResources* GameState_ReadPResources(GameState* state)
{
    return state->pResources_;
}

// Original: arm9/main @ 0x0200FB94; symbol: func_0200fb94; size: 0x8.
extern "C" void GameState_SetUnk4Element0(GameState* state, unsigned char value)
{
    state->unk_4[0] = value;
}

// Original: arm9/main @ 0x0200FB9C; symbol: func_0200fb9c; size: 0x8.
extern "C" unsigned char GameState_ReadByteAtOffset4(GameState* state)
{
    return (unsigned char)state->unk_4[0];
}
