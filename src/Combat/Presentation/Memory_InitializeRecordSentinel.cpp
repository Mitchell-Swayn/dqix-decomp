#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E8A20; symbol: func_ov025_021e8a20; size: 0x20.
extern "C" void Memory_InitializeRecordSentinel(void* p) { *(unsigned short*)((char*)p + 4) = 0; *(unsigned short*)((char*)p + 6) = 0; *((unsigned char*)p + 8) = 0; *((unsigned char*)p + 9) = 0; *(unsigned int*)p = 0xffffffff; }
