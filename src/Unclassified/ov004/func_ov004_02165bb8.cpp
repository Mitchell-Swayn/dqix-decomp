#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov004 @ 0x02165BB8; symbol: func_ov004_02165bb8; size: 0x18.
extern "C" int func_ov004_02165bb8(void) { *(unsigned int*)((char*)ReadWordFieldAtOffset1C() + 0x2c8) = 1; return 0; }
