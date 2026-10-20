#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x0206EBF4; symbol: func_0206ebf4; size: 0x28.
 extern "C" void Script_ResetMessageUsageCounters(unsigned char* p) { memset(p,0,0x80);memset(p+0x80,0,0x80); }
