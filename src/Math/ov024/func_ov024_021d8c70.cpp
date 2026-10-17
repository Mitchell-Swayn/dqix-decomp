#include <globaldefs.h>
ARM
extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
// Original: arm9/ov024 @ 0x021D8C70; symbol: func_ov024_021d8c70; size: 0x20.
extern "C" int func_ov024_021d8c70(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int unused, int value) {
    return _ffix(_fmul(0x3f400000, _fflt(value)));
}
