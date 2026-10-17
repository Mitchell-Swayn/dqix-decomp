#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0207C60C; symbol: func_0207c60c; size: 0x14.
extern "C" unsigned int ReadOneOfEightWordFieldsAtOffsetBF0(unsigned char* p,unsigned int i) { if (i>7) return 0; return ((unsigned int*)(p+i*4+0xbf0))[0]; }
