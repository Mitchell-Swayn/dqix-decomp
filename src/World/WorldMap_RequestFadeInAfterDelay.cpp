#include <globaldefs.h>

// Original: arm9/main @ 0x02021410; symbol: func_02021410; size: 0x18.
extern "C" ARM void WorldMap_RequestFadeInAfterDelay (char* p, int n, unsigned char v) { p[0x9c4] = n != 0; p[0x9c8] = v; }
