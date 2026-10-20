#include <globaldefs.h>

// Original: arm9/main @ 0x020340C4; symbol: func_020340c4; size: 0x10.
extern "C" ARM void GameObject_ClearPositionMatchDeferral (unsigned char* p) { p[0xc2] &= ~0x80; }
