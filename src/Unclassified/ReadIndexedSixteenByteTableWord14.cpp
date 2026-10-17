#include <globaldefs.h>
ARM
extern "C" unsigned char* data_02110370;
// Original: arm9/main @ 0x020BD8AC; symbol: func_020bd8ac; size: 0x28.
 extern "C" unsigned int ReadIndexedSixteenByteTableWord14(unsigned int i) { unsigned char* p=*(unsigned char**)(data_02110370+0x84); if(i>=*(unsigned int*)(p+8))return 0; return *(unsigned int*)(p+i*16+0x14); }
