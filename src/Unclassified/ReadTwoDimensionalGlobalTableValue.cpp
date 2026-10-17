#include <globaldefs.h>
ARM
extern "C" unsigned char data_020f01f8[];
// Original: arm9/main @ 0x0204A5E4; symbol: func_0204a5e4; size: 0x14.
extern "C" unsigned int ReadTwoDimensionalGlobalTableValue(unsigned int i,unsigned int j) { return ((unsigned int(*)[4])data_020f01f8)[i][j]; }
