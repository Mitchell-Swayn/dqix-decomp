#include <globaldefs.h>
ARM
extern "C" unsigned char* data_0210782c[];
// Original: arm9/main @ 0x020425B4; symbol: func_020425b4; size: 0x30.
extern "C" unsigned char* GetBoundedEightByteTableEntry(unsigned int i,int table) { unsigned char* p=data_0210782c[table];if ((int)i>=0 && i<*(unsigned int*)(p+4))return *(unsigned char**)(p+0x10)+i*8;return 0; }
