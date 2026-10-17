#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020DBD9C; symbol: func_020dbd9c; size: 0x24.
extern "C" void InitializeRecordWithInvalidWordC(unsigned char* p) { *(unsigned int*)p=0;*(unsigned int*)(p+4)=0;*(unsigned int*)(p+8)=0;*(unsigned int*)(p+12)=0xffffffff;*(unsigned int*)(p+16)=0;p[20]=0; }
