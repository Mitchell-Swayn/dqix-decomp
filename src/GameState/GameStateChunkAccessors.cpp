#include "GameState/GameState.h"

extern "C" void* GameState_CopyChunkLayout(void* destination, const void* source);

// Original: arm9/main @ 0x0200FCFC; symbol: func_0200fcfc; size: 0x10.
extern "C" void* GameState_CopyChunkAtOffset3F8(GameState* state, const void* source)
{
    return GameState_CopyChunkLayout(state->unk_3f8, source);
}

// Original: arm9/main @ 0x0200FD0C; symbol: func_0200fd0c; size: 0x8.
extern "C" void* GameState_ReadUnkF8(GameState* state)
{
    return state->unk_3f8;
}
