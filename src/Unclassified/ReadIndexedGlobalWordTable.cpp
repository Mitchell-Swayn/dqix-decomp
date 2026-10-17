#include <globaldefs.h>
ARM
extern "C" unsigned char data_020e88c0[];
// Original: arm9/main @ 0x02074938; symbol: func_02074938; size: 0x10.
extern "C" unsigned int ReadIndexedGlobalWordTable(unsigned int i) { return ((unsigned int*)data_020e88c0)[i]; }
