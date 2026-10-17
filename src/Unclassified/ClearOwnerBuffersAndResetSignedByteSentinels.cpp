#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#include <std_library_functions.h>
// Original: arm9/main @ 0x02046380; symbol: func_02046380; size: 0x124.
extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(signed char* object){object[0x30]=-1;object[0x31]=-1;object[0x1880]=-1;memset(object+0x2ec,0,0xc0);memset(object+0x3ac,0,0x40);memset(object+0x3ec,0,0x40);memset(object+0x42c,0,0x40);memset(object+0x46c,0,0x40);memset(object+0x4ac,0,0x400);memset(object+0x8b0,0,0x40);memset(object+0x8f1,0,0x10);memset(object+0x902,0,0x10);*(unsigned*)(object+0x8ac)=0;object[0x901]=0;object[0x8f0]=0;*(unsigned*)(object+0x2e8)=0;unsigned zero=0;for(int i=0;i<2;++i){*(unsigned*)(object+i*4)=zero;*(unsigned*)(object+i*4+8)=0;*(unsigned*)(object+i*4+16)=0;*(unsigned*)(object+i*4+24)=0;*(unsigned*)(object+i*4+32)=0;}*(unsigned*)(object+40)=0;*(unsigned*)(object+44)=0;object[0x19d5]=0;object[0x19d6]=0;object[0x19d7]=0;object[0x19d8]=0;}
