#include <globaldefs.h>

// Original: arm9/main @ 0x020263C8; symbol: func_020263c8; size: 0x14.
extern "C" ARM void TreasureMapPanel_RequestTextRefresh (char* p, int n) { p[0x778] = n != 0; }
