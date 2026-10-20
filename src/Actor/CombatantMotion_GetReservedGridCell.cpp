#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020493EC; symbol: func_020493ec; size: 0x14.
extern "C" unsigned int CombatantMotion_GetReservedGridCell(unsigned char* p) { unsigned char* v=*(unsigned char**)(p+0x13c); return v ? *(unsigned char*)(v+0x1e) : 0xff; }
