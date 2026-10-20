#include <globaldefs.h>

// Original: arm9/main @ 0x020213FC; symbol: func_020213fc; size: 0x14.
extern "C" ARM void WorldMap_SetFadeInBlocked (char* p, int n) { p[0x9c6] = n != 0; }
