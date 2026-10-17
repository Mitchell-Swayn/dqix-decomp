#include <globaldefs.h>
ARM
extern "C" void* data_ov031_0224e5b4;
// Original: arm9/ov031 @ 0x02212248; symbol: func_ov031_02212248; size: 0x2C.
extern "C" unsigned int System_IsGlobalStateHalfwordFourEqualSix(void) { void* p = *(void**)((char*)&data_ov031_0224e5b4 + 4); return p && *(unsigned short*)((char*)p + 4) == 6; }
