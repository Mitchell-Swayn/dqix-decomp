#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6E04; symbol: func_ov024_021f6e04; size: 0x50.
extern "C" int BattleAI_BoostDamageEstimatesForTargetTypeEight(char* p) {
    void* nested = *(void**)(p + 8);
    if (nested && ((((unsigned int)*(unsigned short*)((char*)nested + 0xa) << 21) >> 28) == 8)) {
        *(unsigned int*)(p + 0x1c) = _fmul(0x3fc00000, *(unsigned int*)(p + 0x14));
        *(unsigned int*)(p + 0x20) = _fmul(0x3fc00000, *(unsigned int*)(p + 0x18));
    }
    return 1;
}
