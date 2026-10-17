#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02100044(void);
struct Object;
extern "C" void MoveQueuedRecordAndApplySourceValue(Object* object, const void* source, short value);
// Original: arm9/ov017 @ 0x021CBBD0; symbol: func_ov017_021cbbd0; size: 0x3C.
extern "C" void GameState_ApplyQueuedRecordValue(void* input) {
    volatile unsigned char source[0x14];
    void* object = ReadGlobalAt02100044();
    source[0] = 0x63;
    *(volatile unsigned short*)(source + 4) = *(unsigned short*)(*(char**)((char*)input + 0x8e18) + 8);
    MoveQueuedRecordAndApplySourceValue((Object*)object, (const void*)source, 1);
}
