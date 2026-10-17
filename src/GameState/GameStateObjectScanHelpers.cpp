#include "GameState/GameState.h"

extern "C" GameObject* GameState_FindIndexedObjectWithFlag1000(GameState* state, int index);

// Original: arm9/main @ 0x0200FFE0; symbol: func_0200ffe0; size: 0x58.
extern "C" GameObject* GameState_FindFlag20ObjectByKey(GameState* state, int key)
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

// Original: arm9/main @ 0x02010038; symbol: func_02010038; size: 0x50.
extern "C" int GameState_CollectPresentMemberIndices(GameState* state, unsigned char* indices)
{
    if (indices == NULL)
        return 0;

    int index = 0;
    int count = 1;
    indices[index] = index;
    for (; index < 4; ++index) {
        if (GameState_FindIndexedObjectWithFlag1000(state, index) != NULL) {
            indices[count] = index;
            ++count;
        }
    }
    return count;
}
