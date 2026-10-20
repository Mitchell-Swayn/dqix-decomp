#include <globaldefs.h>
ARM
struct GameState;
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned GameState_CopyActivePartySlotList(GameState*,void*);
extern "C" void Script_WriteIntegerReferenceOutput(void *,int);
// Original: arm9/ov023 @ 0x021EA630; symbol: func_ov023_021ea630; size: 0x8C.
extern "C" int GameState_WriteListedObjectZeroValueCount(void *output) {
    GameState *state = (GameState*)_ZN9GameState11GetInstanceEv();
    unsigned char indices[4] = {};
    int count = GameState_CopyActivePartySlotList(state, indices);
    int matches = 0;
    for (int i = 0; i < count; i++) {
        char *object = (char*)GameState_GetObjectWithFlag100(state, indices[i]);
        if (object && !(*(unsigned short*)object & 0x1000)) {
            int value = *(unsigned short*)(*(char**)(object + 0x130) + 4);
            if (value <= 0) matches++;
        }
    }
    Script_WriteIntegerReferenceOutput(output, matches);
    return 1;
}
