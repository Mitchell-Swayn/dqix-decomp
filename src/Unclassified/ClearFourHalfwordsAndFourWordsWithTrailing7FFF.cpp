#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02042FCC; symbol: func_02042fcc; size: 0x34.
extern "C" void ClearFourHalfwordsAndFourWordsWithTrailing7FFF(unsigned char* p) { *(short*)(p+6)=0;*(short*)(p+4)=0;*(short*)(p+2)=0;*(short*)p=0;*(unsigned int*)(p+8)=0;*(unsigned int*)(p+12)=0;*(unsigned int*)(p+20)=0;*(unsigned int*)(p+16)=0;*(short*)(p+24)=0x7fff; }
