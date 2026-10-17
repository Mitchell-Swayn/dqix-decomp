#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov001 @ 0x0215E960; symbol: func_ov001_0215e960; size: 0x1C.
extern "C" int func_ov001_0215e960(void) { *((unsigned char*)((char*)ReadWordFieldAtOffset1C() + 0x19ca)) = 0; return 1; }
