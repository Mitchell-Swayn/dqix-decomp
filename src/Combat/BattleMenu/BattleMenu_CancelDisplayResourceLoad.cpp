#include <globaldefs.h>
ARM
extern "C" void BackgroundLoader_CancelTaskAndDestroyDisplayAllocator(void *self);
// Original: arm9/ov000 @ 0x02176038; symbol: func_ov000_02176038; size: 0x1C.
extern "C" void BattleMenu_CancelDisplayResourceLoad(void *object) {
    *(unsigned char *)((char *)object + 0xb3) |= 8;
    BackgroundLoader_CancelTaskAndDestroyDisplayAllocator((char *)object + 0x7c);
}
