#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020884F8; symbol: func_020884f8; size: 0x1C.
extern "C" void CombatStatus_ClearActionRestriction(unsigned char* p) { *(unsigned int*)(p+0x14)&=~0x80000; *(unsigned short*)(p+0x22)&=~0x3c; }
