#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02053DFC; symbol: func_02053dfc; size: 0x14.
extern "C" unsigned int GameObject_GetCombatTrackingCounterOrZero(unsigned char* p) { unsigned char* v=*(unsigned char**)(p+0x19c); return v ? *(unsigned int*)(v+0x8) : 0x0; }
