#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02075D64; symbol: func_02075d64; size: 0x4C.
extern "C" void ClearStateWordsAndFlags(unsigned char* p) { *(unsigned int*)p=0;*(unsigned int*)(p+4)=0;*(unsigned int*)(p+12)=0;*(unsigned int*)(p+8)=0;*(unsigned int*)(p+16)=0;*(unsigned int*)(p+24)=0;*(unsigned int*)(p+28)=0;*(unsigned int*)(p+32)=0;*(unsigned int*)(p+36)=0;*(unsigned int*)(p+80)=0;*(unsigned int*)(p+84)=0;*(short*)(p+92)=0;p[95]=0;*(unsigned int*)(p+96)=0;*(unsigned int*)(p+100)=0;*(unsigned int*)(p+104)=0;*(unsigned int*)(p+108)=0; }
