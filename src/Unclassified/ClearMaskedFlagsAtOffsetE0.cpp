#include <globaldefs.h>

// Original: arm9/main @ 0x02033FDC; symbol: func_02033fdc; size: 0x10.
extern "C" ARM void ClearMaskedFlagsAtOffsetE0 (unsigned char* p) { p[0xe0] &= ~4; }
