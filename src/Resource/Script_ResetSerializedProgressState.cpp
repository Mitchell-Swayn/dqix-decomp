#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* memset(void*,int,unsigned);extern "C" void InitializeFiveTwentyEightByteRecords(void*);
// Original: arm9/main @ 0x0206DDB8; symbol: func_0206ddb8; size: 0x88.
extern "C" void Script_ResetSerializedProgressState(unsigned char* p){p[0x332]=0;memset(p+0x8c,0,0x234);memset(p+0x2c0,0,12);InitializeFiveTwentyEightByteRecords(p);memset(p+0x2cc,0,102);memset(p+0x334,0,206);*(unsigned*)(p+0x404)=0;*(unsigned*)(p+0x408)=0;memset(p+0x40c,0,15);memset(p+0x41b,0,64);}
