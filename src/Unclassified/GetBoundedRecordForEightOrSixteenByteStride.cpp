#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020B00E0; symbol: func_020b00e0; size: 0x28.
extern "C" unsigned char* GetBoundedRecordForEightOrSixteenByteStride(unsigned char* p,unsigned int i) { if (i>=*(unsigned short*)p) return 0; unsigned short flags=*(unsigned short*)(p+2);unsigned char* base=*(unsigned char**)(p+4); return flags&1 ? base+i*16 : base+i*8; }
