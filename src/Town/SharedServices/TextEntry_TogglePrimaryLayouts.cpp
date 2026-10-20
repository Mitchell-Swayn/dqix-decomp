#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215EE44; symbol: func_ov003_0215ee44; size: 0x24.
extern "C" unsigned int TextEntry_TogglePrimaryLayouts(unsigned char* p) { p[0x1e] = p[0x1e] == 2 ? 1 : 2; p[0x20] = 0; return 4; }
