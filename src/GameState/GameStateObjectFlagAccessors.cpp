#include "GameState/GameState.h"

// These filters test observed object flag bits. Their higher-level meanings
// are not established, so retain address-based function names and raw masks.
extern "C" GameObject* func_0200fea4(GameState* state, int index)
{
    if (index < 0)
        return NULL;
    if (index >= 0xe9)
        return NULL;
    GameObject* object = state->objects_[index];
    if (object == NULL)
        return NULL;
    if (!(object->obj3D_.unknown_0_ & 0x400))
        return NULL;
    return object;
}

extern "C" GameObject* func_0200fee0(GameState* state, int index)
{
    if (index < 0)
        return NULL;
    if (index >= 0xe9)
        return NULL;
    GameObject* object = state->objects_[index];
    if (object == NULL)
        return NULL;
    if (!(object->obj3D_.unknown_0_ & 0x200))
        return NULL;
    return object;
}

extern "C" GameObject* func_0200ff1c(GameState* state, int index)
{
    if (index < 0)
        return NULL;
    if (index >= 0xe9)
        return NULL;
    GameObject* object = state->objects_[index];
    if (object == NULL)
        return NULL;
    if (!(object->obj3D_.unknown_0_ & 0x100))
        return NULL;
    return object;
}

extern "C" GameObject* func_0200ff58(GameState* state, int index)
{
    if (index < 0)
        return NULL;
    if (index >= 0xe9)
        return NULL;
    GameObject* object = state->objects_[index];
    if (object == NULL)
        return NULL;
    if (!(object->obj3D_.unknown_0_ & 0x1000))
        return NULL;
    return object;
}
