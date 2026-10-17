#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020999D8; symbol: func_020999d8; size: 0x18.
extern "C" unsigned char* GetSixteenByteRecordByBoundedIndex(unsigned int* p,unsigned int i) { if (p[1]<=i) return 0; return (unsigned char*)p[0]+i*16; }
