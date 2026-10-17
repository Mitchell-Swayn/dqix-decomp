#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020E1354; symbol: func_020e1354; size: 0x14.
extern "C" void Record_ClearTwoWordsAndByteEight(unsigned char* p) { *(unsigned int*)p=0; *(unsigned int*)(p+4)=0; p[8]=0; }
