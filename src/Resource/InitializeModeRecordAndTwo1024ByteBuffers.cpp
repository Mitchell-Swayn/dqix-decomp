#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma optimization_level 3
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0209E3DC; symbol: func_0209e3dc; size: 0x90.
extern "C" void InitializeModeRecordAndTwo1024ByteBuffers(unsigned* p,unsigned mode){p[0]=0;p[1]=mode;p[2]=0;p[3]=0;p[25]=~0U;p[26]=~0U;p[27]=~0U;memset(p+28,0,16);p[36]=~0U;p[37]=0;p[38]=0;memset(p+39,0,1024);p[295]=0;memset(p+296,0,1024);memset(p+4,0,84);p[33]=0;p[34]=0;p[35]=0;}
