#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020882DC; symbol: func_020882dc; size: 0x1C.
extern "C" void CombatStatus_ClearParalysis(unsigned char* p) { *(unsigned int*)(p+0x14)&=~0x8;p[0x5c]=0;p[0x7f]=0; }
