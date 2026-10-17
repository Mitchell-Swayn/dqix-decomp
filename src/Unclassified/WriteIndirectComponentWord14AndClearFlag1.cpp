#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02049C60; symbol: func_02049c60; size: 0x28.
extern "C" void WriteIndirectComponentWord14AndClearFlag1(unsigned char* p,unsigned int* value) { if (!*(unsigned char**)(p+0x13c)) return; *(unsigned int*)(*(unsigned char**)(p+0x13c)+0x14)=value[1]; *(unsigned int*)(*(unsigned char**)(p+0x13c)+0x20)&=~1; }
