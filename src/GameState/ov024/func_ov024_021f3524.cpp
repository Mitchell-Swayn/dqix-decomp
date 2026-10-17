#include <globaldefs.h>
ARM
extern "C" void* FindIndexedGameStateObjectWithFlag400(void*, int);
extern "C" int TestRecordFlags14Mask01000000(void*);
// Original: arm9/ov024 @ 0x021F3524; symbol: func_ov024_021f3524; size: 0x40.
extern "C" int func_ov024_021f3524(void** gameState, short index, int unused, int* found, short* value) {
    short requested = index;
    void* object = FindIndexedGameStateObjectWithFlag400(*gameState, requested);
    if (!object) return 0;
    if (TestRecordFlags14Mask01000000(object)) return 0;
    *found = 1;
    *value = requested;
    return 1;
}
