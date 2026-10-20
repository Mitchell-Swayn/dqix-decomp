#include "GameState/GameState.h"
#include "std_library_functions.h"

// Original: arm9/main @ 0x0200FD38; symbol: func_0200fd38; size: 0x10.
extern "C" void GameState_SetIndexedObjectAndSlot(GameState* state, int index, GameObject* object)
{
    state->objects_[index] = object;
    object->obj3D_.unknown_4_ = index;
}

// Original: arm9/main @ 0x0200FD48; symbol: func_0200fd48; size: 0x10.
extern "C" void GameState_ClearObjectByIndex(GameState* state, int index)
{
    state->objects_[index] = 0;
}

// Original: arm9/main @ 0x0200FD58; symbol: func_0200fd58; size: 0x18.
extern "C" void GameState_ClearObjectPointers(GameState* state)
{
    memset(state->objects_, 0, sizeof(state->objects_));
}
