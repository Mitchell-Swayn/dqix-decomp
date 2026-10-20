#include <globaldefs.h>
ARM
extern "C" int System_ReportHardwareProbeUnsupported();extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);
// Original: arm9/main @ 0x020D28F0; symbol: func_020d28f0; size: 0x40.
extern "C" bool SoundCommand_IsTransportAvailable() { if(!System_ReportHardwareProbeUnsupported())return true;int state=_Z20DisableIRQInterruptsv();volatile unsigned int* reg=(volatile unsigned int*)0x04fff200;*reg=16;unsigned int result=*reg;_Z20SetIRQInterruptStatei(state);return result!=0; }
