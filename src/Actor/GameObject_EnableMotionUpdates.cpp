#include <globaldefs.h>

// Original: arm9/main @ 0x02033FDC; symbol: func_02033fdc; size: 0x10.
extern "C" ARM void GameObject_EnableMotionUpdates (unsigned char* p) { p[0xe0] &= ~4; }
