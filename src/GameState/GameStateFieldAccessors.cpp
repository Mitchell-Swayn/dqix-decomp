#include "GameState/GameState.h"

// Original: arm9/main @ 0x020100A0; symbol: func_020100a0; size: 0x8.
extern "C" void GameState_SetProtagonistObjectIndex(GameState* state, int index)
{
    state->protagonistObjectIndex_ = index;
}

// Original: arm9/main @ 0x020100A8; symbol: func_020100a8; size: 0x8.
extern "C" int GameState_ReadProtagonistObjectIndex(GameState* state)
{
    return state->protagonistObjectIndex_;
}

// Original: arm9/main @ 0x020100B0; symbol: func_020100b0; size: 0xC.
extern "C" unsigned char GameState_ReadFirstObjectIndex(GameState* state)
{
#if defined(usa)
    return state->indexList_.objectIndices_[0];
#else
    return state->unknownObjectIndex_397c_;
#endif
}

// Original: arm9/main @ 0x020100BC; symbol: func_020100bc; size: 0x8.
extern "C" void* GameState_ReadUnknownB0(GameState* state)
{
    return state->unknown_3b0_;
}

// Original: arm9/main @ 0x020100C4; symbol: func_020100c4; size: 0x8.
extern "C" void GameState_SetUnknown3b0(GameState* state, void* value)
{
    state->unknown_3b0_ = value;
}
