#include <globaldefs.h>
// Returns the actor motion descriptor pointer stored at offset 0x0c.
// Original: arm9/main @ 0x02040538; symbol: func_02040538; size: 0x8.
extern "C" ARM char* Actor_GetMotionDescriptor(void* actor) { return *(char**)((char*)actor+0xc); }
