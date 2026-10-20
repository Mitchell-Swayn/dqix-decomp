#include <globaldefs.h>
ARM
#include <System/Memory.h>
extern "C" void WindowControl_SetEnabled(void*,int);extern "C" void WindowControl_ApplyInsideAndOutsideMasks(void*);
// Original: arm9/main @ 0x020E2BD8; symbol: func_020e2bd8; size: 0x5C.
extern "C" void WindowControl_InitializeDefaultsAndReset(unsigned char* object,unsigned char a,unsigned char b){object[0]=0;object[1]=a;object[2]=b;VectorizedMemset(object+20,0,16);*(unsigned*)(object+4)=5;*(unsigned*)(object+8)=1;*(unsigned*)(object+12)=31;*(unsigned*)(object+16)=1;WindowControl_SetEnabled(object,0);WindowControl_ApplyInsideAndOutsideMasks(object);}
