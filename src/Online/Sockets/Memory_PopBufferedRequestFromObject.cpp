#include <globaldefs.h>
ARM
extern "C" void Memory_PopBufferedRequest(void *);
// Original: arm9/ov031 @ 0x02205EAC; symbol: func_ov031_02205eac; size: 0x10.
extern "C" void Memory_PopBufferedRequestFromObject(void *p) { Memory_PopBufferedRequest(*(void **)((unsigned char *)p + 4)); }
