#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void func_0200fd38(GameState* state, int index, GameObject* object)
{
    state->objects_[index] = object;
    object->obj3D_.unknown_4_ = index;
}

extern "C" void func_0200fd48(GameState* state, int index)
{
    state->objects_[index] = 0;
}

extern "C" void func_0200fd58(GameState* state)
{
    memset(state->objects_, 0, sizeof(state->objects_));
}
