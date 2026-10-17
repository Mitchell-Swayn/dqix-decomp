#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x02093980; symbol: func_02093980; size: 0x2C.
extern "C" void ClearRecordAndInitializeInvalidIndices(unsigned char* p) { memset(p,0,0x30);*(short*)(p+0x30)=-1;*(signed char*)(p+0x32)=-1;p[0x33]=0; }
