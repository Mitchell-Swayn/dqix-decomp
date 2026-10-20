#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6FB0; symbol: func_ov024_021f6fb0; size: 0x34.
extern "C" int BattleAI_ScaleDamageEstimatesByThirteenTenths(void *p) {
    *(unsigned int *)((char *)p + 0x1c) = _fmul(0x3fa66666, *(unsigned int *)((char *)p + 0x14));
    *(unsigned int *)((char *)p + 0x20) = _fmul(0x3fa66666, *(unsigned int *)((char *)p + 0x18));
    return 1;
}
