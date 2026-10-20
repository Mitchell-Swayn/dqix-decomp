#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021ED2F4; symbol: func_ov025_021ed2f4; size: 0x20.
extern "C" unsigned int Combat_IsActionMessageQueueIdle(void* p) { return *((unsigned char*)p + 0x150) == 0 && *(unsigned short*)((char*)p + 0x15e) == 0; }
