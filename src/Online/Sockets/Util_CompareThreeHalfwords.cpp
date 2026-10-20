#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02200824; symbol: func_ov031_02200824; size: 0x2C.
extern "C" unsigned int Util_CompareThreeHalfwords(const unsigned short* a, const unsigned short* b) { int i = 0; do { unsigned short x = *a++; unsigned short y = *b++; if (x != y) return 1; ++i; } while (i < 3); return 0; }
