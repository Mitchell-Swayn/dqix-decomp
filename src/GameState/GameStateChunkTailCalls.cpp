#include "GameState/GameState.h"

extern "C" void* GameState_CopyChunkLayout(void* destination, const void* source);

// Original: arm9/main @ 0x0200FBA4; symbol: func_0200fba4; size: 0x10.
extern "C" void* GameState_StoreRequestedFieldTransition(GameState* state, const void* source)
{
    return GameState_CopyChunkLayout(state->unk_3f8, source);
}
