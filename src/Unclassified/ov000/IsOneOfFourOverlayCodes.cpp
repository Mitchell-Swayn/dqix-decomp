#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02163690; symbol: func_ov000_02163690; size: 0x1c.
extern "C" ARM int IsOneOfFourOverlayCodes(int value) { return value == 1 || value == 2 || value == 0xdb || value == 0x150; }
