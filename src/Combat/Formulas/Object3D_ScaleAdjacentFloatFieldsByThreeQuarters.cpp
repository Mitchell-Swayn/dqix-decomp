#include <globaldefs.h>
ARM
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6B5C; symbol: func_ov024_021f6b5c; size: 0x30.
extern "C" int Object3D_ScaleAdjacentFloatFieldsByThreeQuarters(unsigned int *object) {
    object[7] = _fmul(0x3f400000, object[5]);
    object[8] = _fmul(0x3f400000, object[6]);
    return 1;
}
