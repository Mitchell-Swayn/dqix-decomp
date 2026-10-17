#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020656D0; symbol: func_020656d0; size: 0x14.
extern "C" unsigned short ReadCurrentIndexedHalfwordFromStoredArray(unsigned char* p) { unsigned int i=*(unsigned int*)(p+0x78); unsigned short* v=*(unsigned short**)(p+0x4c); return v[i]; }
