#include <globaldefs.h>
ARM
extern "C" int _ffix(unsigned int);
extern "C" int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021D92F8; symbol: func_ov024_021d92f8; size: 0x24.
extern "C" int Math_ScaleIntegerBySevenTenths(int, int, int, int, int, int value) {
    return _ffix(_fmul(0x3f333333, _fflt(value)));
}
