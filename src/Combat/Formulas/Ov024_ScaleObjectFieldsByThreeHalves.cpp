#include <globaldefs.h>
ARM
extern "C" unsigned _fmul(unsigned, unsigned);
// Original: arm9/ov024 @ 0x021F71A8; symbol: func_ov024_021f71a8; size: 0x30.
extern "C" int Ov024_ScaleObjectFieldsByThreeHalves(unsigned char *object) {
    *(unsigned *)(object + 0x1c) = _fmul(0x3fc00000, *(unsigned *)(object + 0x14));
    *(unsigned *)(object + 0x20) = _fmul(0x3fc00000, *(unsigned *)(object + 0x18));
    return 1;
}
