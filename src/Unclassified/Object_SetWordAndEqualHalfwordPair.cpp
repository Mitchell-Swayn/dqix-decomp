#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02072AA8; symbol: func_02072aa8; size: 0x1C.
extern "C" int Object_SetWordAndEqualHalfwordPair(unsigned char* p,unsigned int value,int x) { short s=(short)x; *(unsigned int*)p=value; *(short*)(p+6)=s; *(short*)(p+4)=s; return 1; }
