#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*, int);
// Original: arm9/ov017 @ 0x02192548; symbol: func_ov017_02192548; size: 0x4C.
extern "C" int GameState_GetMaximumIndexedBytePlusOne(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    int maximum = 0;
    for (int index = 1; index < 4; index++) {
        void *object = GameState_FindIndexedObjectWithFlag1000(state, index);
        if (object) {
            unsigned char value = *(unsigned char *)((char *)object + 0x2d2);
            if (maximum < value) maximum = value;
        }
    }
    return maximum + 1;
}
