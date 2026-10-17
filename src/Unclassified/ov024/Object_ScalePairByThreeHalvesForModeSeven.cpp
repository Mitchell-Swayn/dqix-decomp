#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6E88; symbol: func_ov024_021f6e88; size: 0x50.
extern "C" int Object_ScalePairByThreeHalvesForModeSeven(void* self) {
    void* object = *(void**)((char*)self + 8);
    if (object != 0 && ((((unsigned)*(unsigned short*)((char*)object + 0xa) << 21) >> 28) == 7)) {
        *(unsigned*)((char*)self + 0x1c) = _fmul(0x3fc00000, *(unsigned*)((char*)self + 0x14));
        *(unsigned*)((char*)self + 0x20) = _fmul(0x3fc00000, *(unsigned*)((char*)self + 0x18));
    }
    return 1;
}
