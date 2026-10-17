#include <globaldefs.h>
ARM
extern "C" unsigned _fmul(unsigned, unsigned);
// Original: arm9/ov024 @ 0x021F6BC0; symbol: func_ov024_021f6bc0; size: 0x30.
extern "C" int Ov024_ScaleObjectFieldsByThreeQuarters(unsigned char *object) {
    *(unsigned *)(object + 0x1c) = _fmul(0x3f400000, *(unsigned *)(object + 0x14));
    *(unsigned *)(object + 0x20) = _fmul(0x3f400000, *(unsigned *)(object + 0x18));
    return 1;
}
