#include "globaldefs.h"
#pragma optimize_for_size on
ARM
extern "C" int ResourceFile_CountActiveStrideRecords(void*);extern "C" void* FindVariableLengthBlockByIndex(void*,int,int*,int*);extern "C" void Graphics_DispatchDataByResourceMagic(void*,void*,int,int);
// Original: arm9/main @ 0x0205A498; symbol: func_0205a498; size: 0x90.
extern "C" int ProcessAllFileEntriesWhenEnabled(void*p,void*state,int enable,int flag){if(enable){int count=ResourceFile_CountActiveStrideRecords(state);for(int i=0;i<count;i++){int a=0,b=0;void*r=FindVariableLengthBlockByIndex(state,i,&a,&b);if(r)Graphics_DispatchDataByResourceMagic(p,r,b,flag);}return 0;}return 1;}
