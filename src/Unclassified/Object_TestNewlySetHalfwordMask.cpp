#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02012444; symbol: func_02012444; size: 0x24.
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short* p,unsigned int mask) { if ((p[0]&mask)!=0 && (p[1]&mask)==0) return 1; return 0; }
