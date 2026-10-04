#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff94(GameState* state, int index)
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
