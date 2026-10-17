#include <globaldefs.h>
ARM
extern "C" void ClearWordAndTwoBytes(void*);extern "C" void StatusRecord_ClearInitialWord(void*);extern "C" void ClearValue_Main0206DA74(void*);extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0203CF58; symbol: func_0203cf58; size: 0x5C.
extern "C" void InitializeEmbeddedResourcesAndClearBuffers(unsigned char* p){ClearWordAndTwoBytes(p);StatusRecord_ClearInitialWord(p+144);ClearValue_Main0206DA74(p+148);memset(p+12,0,128);*(int*)(p+152)=0;*(int*)(p+140)=0;p[156]=0;memset(p+158,0,320);*(short*)(p+478)=0;*(int*)(p+484)=0;}
