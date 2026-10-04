#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff58(GameState* state, int index);

extern "C" GameObject* func_0200ffe0(GameState* state, int key)
{
    if (key < 0)
        return NULL;

    for (int index = 0x70; index <= 0x9f; ++index) {
        GameObject* object = state->objects_[index];
        if (object != NULL && (object->obj3D_.unknown_0_ & 0x20)) {
            // The compared halfword's meaning is not established. Preserve its
            // observed byte offset without assigning it a semantic field name.
            unsigned short objectKey =
                *(unsigned short*)((char*)object + 0x16a);
            if (key == objectKey)
                return object;
        }
    }
    return NULL;
}

extern "C" int func_02010038(GameState* state, unsigned char* indices)
{
    if (indices == NULL)
        return 0;

    int index = 0;
    int count = 1;
    indices[index] = index;
    for (; index < 4; ++index) {
        if (func_0200ff58(state, index) != NULL) {
            indices[count] = index;
            ++count;
        }
    }
    return count;
}
