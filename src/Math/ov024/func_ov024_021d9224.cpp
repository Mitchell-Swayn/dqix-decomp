#include <globaldefs.h>
ARM
extern "C" int _s32_div_f(int, int);

// Original: arm9/ov024 @ 0x021D9224; symbol: func_ov024_021d9224; size: 0x18.
extern "C" int func_ov024_021d9224(int a, int b, int c, int divisor, int e, int value) {
    return _s32_div_f(value * 4, divisor + 1);
}
