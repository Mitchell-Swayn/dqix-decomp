#include "GameState/GameState.h"

extern "C" void* GameState_GetIndexList(GameState* state);

// Original: arm9/main @ 0x02039730; symbol: func_02039730; size: 0x20.
extern "C" signed char GameState_ReadIndexedByteAtOffset2C8D(void* self, int index)
{
    GameState* state = GameState::GetInstance();
    char* bytes = (char*)GameState_GetIndexList(state) + index + 0x2c00;
    return ((signed char*)bytes)[0x8d];
}
