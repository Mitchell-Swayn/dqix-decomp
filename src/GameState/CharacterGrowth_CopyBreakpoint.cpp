#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020823E4; symbol: func_020823e4; size: 0x2C.
extern "C" void CharacterGrowth_CopyBreakpoint(unsigned char* p,unsigned char* q) { *(unsigned int*)p=*(unsigned int*)q;*(unsigned short*)(p+4)=*(unsigned short*)(q+4);*(unsigned int*)(p+8)=*(unsigned int*)(q+8);*(unsigned int*)(p+12)=*(unsigned int*)(q+12);*(unsigned int*)(p+16)=*(unsigned int*)(q+16); }
