#include <globaldefs.h>
ARM
extern "C" void _ZN13ZoneState27545ResetEv(void*);
// Original: arm9/main @ 0x0207CBE8; symbol: func_0207cbe8; size: 0x24.
 extern "C" void ResetZoneStateAndClearThreeWords(unsigned char* p) { _ZN13ZoneState27545ResetEv(p+0x14); *(unsigned int*)(p+0x2c)=0;*(unsigned int*)(p+0x30)=0;*(unsigned int*)(p+0x34)=0; }
