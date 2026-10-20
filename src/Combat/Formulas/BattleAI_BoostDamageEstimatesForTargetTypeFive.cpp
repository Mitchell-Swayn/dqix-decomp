#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6F60; symbol: func_ov024_021f6f60; size: 0x50.
extern "C" int BattleAI_BoostDamageEstimatesForTargetTypeFive(void *obj) {
    void *nested = *(void **)((char *)obj + 8);
    if (nested != 0) {
        unsigned int field = ((unsigned int)*(unsigned short *)((char *)nested + 0xa) << 21) >> 28;
        if (field == 5) {
            *(unsigned int *)((char *)obj + 0x1c) = _fmul(0x3fc00000, *(unsigned int *)((char *)obj + 0x14));
            *(unsigned int *)((char *)obj + 0x20) = _fmul(0x3fc00000, *(unsigned int *)((char *)obj + 0x18));
        }
    }
    return 1;
}
