#include <globaldefs.h>
ARM
extern "C" unsigned _fmul(unsigned, unsigned);
// Original: arm9/ov024 @ 0x021F6BF0; symbol: func_ov024_021f6bf0; size: 0x50.
extern "C" int Resource_ScaleValuesByThreeQuartersForFlag(void* self) {
    void* state = *(void**)((char*)self + 8);
    if (state != 0) {
        unsigned mode = ((unsigned)*(unsigned short*)((char*)state + 0xA) << 21) >> 28;
        if (mode == 1) {
            *(unsigned*)((char*)self + 0x1C) = _fmul(0x3FC00000, *(unsigned*)((char*)self + 0x14));
            *(unsigned*)((char*)self + 0x20) = _fmul(0x3FC00000, *(unsigned*)((char*)self + 0x18));
        }
    }
    return 1;
}
