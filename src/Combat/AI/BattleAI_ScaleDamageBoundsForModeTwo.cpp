#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _Z7RoundUpf(unsigned int);
extern "C" unsigned int _fflt(int);
// Original: arm9/ov024 @ 0x021F6A88; symbol: ScaleVectorComponentsBy1Point5WhenMode2; size: 0x60.
// When the nested mode field is 2, scales float fields +0x14/+0x18 by 1.5, rounds up, and stores floats at +0x1C/+0x20.
extern "C" int BattleAI_ScaleDamageBoundsForModeTwo(void *p) {
    void *nested = *(void **)((char *)p + 8);
    if (nested != 0 && (((unsigned int)*(unsigned short *)((char *)nested + 0xa) << 21) >> 28) == 2) {
        *(unsigned int *)((char *)p + 0x1c) = _fflt(_Z7RoundUpf(_fmul(0x3fc00000, *(unsigned int *)((char *)p + 0x14))));
        *(unsigned int *)((char *)p + 0x20) = _fflt(_Z7RoundUpf(_fmul(0x3fc00000, *(unsigned int *)((char *)p + 0x18))));
    }
    return 1;
}
