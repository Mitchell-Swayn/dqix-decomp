#include "GameState/GameState.h"

// These filters test observed object flag bits. Their higher-level meanings
// are not established, so retain address-based function names and raw masks.
// Original: arm9/main @ 0x0200FEA4; symbol: func_0200fea4; size: 0x3C.
extern "C" GameObject* GameState_FindIndexedObjectWithFlag400(GameState* state, int index)
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

// Original: arm9/main @ 0x0200FEE0; symbol: func_0200fee0; size: 0x3C.
extern "C" GameObject* GameState_GetObjectWithFlag200ByIndex(GameState* state, int index)
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

// Original: arm9/main @ 0x0200FF1C; symbol: func_0200ff1c; size: 0x3C.
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState* state, int index)
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

// Original: arm9/main @ 0x0200FF58; symbol: func_0200ff58; size: 0x3C.
extern "C" GameObject* GameState_FindIndexedObjectWithFlag1000(GameState* state, int index)
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
