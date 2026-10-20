#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void SoundStream_DispatchNextBufferSlice(void*,int);
// Original: arm9/main @ 0x020BCD20; symbol: func_020bcd20; size: 0x10.
extern "C" void SoundStream_RefillBufferOnAlarm(void* p){SoundStream_DispatchNextBufferSlice(p,1);}
