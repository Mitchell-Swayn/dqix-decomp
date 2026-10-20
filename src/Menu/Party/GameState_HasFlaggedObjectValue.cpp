#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
// Original: arm9/ov002 @ 0x02154A34; symbol: GameState_HasFlaggedObjectValue; size: 0x38.
// Looks up the flag-0x100 object and reports whether its nested unsigned halfword at +0x134 is positive.
extern "C" int GameState_HasFlaggedObjectValue(void* unused, int key) {
    void* object = GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(), key);
    if (!object) return 0;
    int result = 0;
    int value = *(unsigned short*)(*(unsigned char**)((char*)object + 0x130) + 4);
    if (value > 0) result = 1;
    return result;
}
