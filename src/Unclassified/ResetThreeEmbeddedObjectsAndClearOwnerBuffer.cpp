#include <globaldefs.h>
ARM
extern "C" void ClearWordAndTwoBytes(void*);extern "C" void StatusRecord_ClearInitialWord(void*);extern "C" void ClearValue_Main0206DA74(void*);extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0203CFB4; symbol: func_0203cfb4; size: 0x40.
extern "C" void ResetThreeEmbeddedObjectsAndClearOwnerBuffer(unsigned char* p){ClearWordAndTwoBytes(p);StatusRecord_ClearInitialWord(p+144);ClearValue_Main0206DA74(p+148);memset(p+12,0,128);*(int*)(p+152)=0;*(int*)(p+140)=0;p[156]=0;}
