#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_FindIndexedObjectWithFlag400(void*, unsigned);
extern "C" void func_02048690(void*);
// Original: arm9/ov000 @ 0x02160FE4; symbol: func_ov000_02160fe4; size: 0x3C.
extern "C" void ProcessEightFlaggedIndexedObjects(void) {
    void* game = _ZN9GameState11GetInstanceEv();
    for (int i = 0; i < 8; ++i) {
        unsigned char* object = GameState_FindIndexedObjectWithFlag400(game, i + 0xc0);
        if (object)
            func_02048690(object);
    }
}
