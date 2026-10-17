#include "GameState/GameState.h"

// Original: arm9/main @ 0x0200FF94; symbol: func_0200ff94; size: 0x2C.
extern "C" GameObject* GameState_GetValidObjectByIndex(GameState* state, int index)
{
    if (index < 0)
        return NULL;
    if (index >= 0xe9)
        return NULL;
    GameObject* object = state->objects_[index];
    if (object == NULL)
        return NULL;
    return object;
}
