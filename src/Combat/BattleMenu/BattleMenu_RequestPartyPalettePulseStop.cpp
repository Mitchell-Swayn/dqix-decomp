#include <globaldefs.h>
ARM
extern "C" void* BattleMenu_FindPartyCommandRecord(unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x021754E0; symbol: func_ov000_021754e0; size: 0x1C.
extern "C" void* BattleMenu_RequestPartyPalettePulseStop(unsigned int a, unsigned int b) { void* p = BattleMenu_FindPartyCommandRecord(a, b); if (p) *((unsigned char*)p + 0x43c) |= 2; return p; }
