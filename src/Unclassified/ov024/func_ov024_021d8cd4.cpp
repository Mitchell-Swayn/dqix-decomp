#include <globaldefs.h>
ARM
extern "C" int _fflt(int value);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" int _ffix(unsigned);
// Original: arm9/ov024 @ 0x021D8CD4; symbol: func_ov024_021d8cd4; size: 0x20.
extern "C" int func_ov024_021d8cd4(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, int value) {
    return _ffix(_fmul(0x3f000000, (unsigned)_fflt(value)));
}
