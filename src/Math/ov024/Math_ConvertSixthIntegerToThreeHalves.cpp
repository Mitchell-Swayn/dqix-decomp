#include <globaldefs.h>
ARM
extern "C" int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(void);
// Original: arm9/ov024 @ 0x021D9204; symbol: func_ov024_021d9204; size: 0x20.
extern "C" int Math_ConvertSixthIntegerToThreeHalves(int a, int b, int c, int d, int e, int value) { (void)a; (void)b; (void)c; (void)d; (void)e; unsigned int f = _fflt(value); f = _fmul(0x3fc00000, f); return _ffix(); }
