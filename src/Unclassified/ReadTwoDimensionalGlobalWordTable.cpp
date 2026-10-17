#include <globaldefs.h>
ARM
extern "C" unsigned char data_020f0218[];
// Original: arm9/main @ 0x0204A5F8; symbol: func_0204a5f8; size: 0x14.
extern "C" unsigned int ReadTwoDimensionalGlobalWordTable(unsigned int i,unsigned int j) { return ((unsigned int(*)[4])data_020f0218)[i][j]; }
