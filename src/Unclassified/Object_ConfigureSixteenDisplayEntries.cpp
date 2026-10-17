#include <globaldefs.h>
extern "C" void UpdateDelayedEffectAndSoundFrame(void*,int,int);
// Original: arm9/main @ 0x020579B4; symbol: func_020579b4; size: 0x38.
extern "C" ARM void Object_ConfigureSixteenDisplayEntries(char* p,int mode){for(int i=0;i<16;++i)UpdateDelayedEffectAndSoundFrame(p+8+i*0xd4,mode,i+0xd0);}
