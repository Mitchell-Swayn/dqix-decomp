// Reviewed original control flow and widths; initialization retains per-field writes.
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
#include <System/Graphics.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" unsigned int data_020ef74c[];struct Pair{unsigned int first:10;unsigned int second:10;unsigned int rest:12;};
// Original: arm9/main @ 0x02038508; symbol: func_02038508; size: 0x90.
extern "C" void InitializeRecordWithEnabledAndPercentDefaults(char* p){*(char*)(p+0)=0;*(char*)(p+1)=0;*(char*)(p+2)=0;*(char*)(p+3)=0;*(short*)(p+4)=0;*(short*)(p+6)=0;*(short*)(p+8)=0;*(short*)(p+10)=0;*(int*)(p+72)=0;*(int*)(p+76)=0;*(short*)(p+80)=0;*(char*)(p+82)=0;*(char*)(p+83)=1;*(char*)(p+84)=100;*(int*)(p+88)=0;*(int*)(p+92)=0;*(int*)(p+96)=0;*(int*)(p+12)=0;*(int*)(p+16)=0;*(int*)(p+20)=0;*(int*)(p+24)=0;*(int*)(p+28)=0;*(int*)(p+32)=0;*(int*)(p+36)=0;*(int*)(p+40)=0;*(int*)(p+44)=0;*(int*)(p+48)=0;*(int*)(p+52)=0;*(int*)(p+56)=0;*(int*)(p+60)=0;*(int*)(p+64)=0;*(int*)(p+68)=0;}
