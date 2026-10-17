#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" unsigned data_02112780[2];
// Original: arm9/main @ 0x020D2718; symbol: func_020d2718; size: 0x50.
extern "C" bool TestWraparoundTargetCounterUnderIRQGuard(unsigned target) { int state=DisableIRQInterrupts(); unsigned now=data_02112780[1]; bool result; if(target>now){ if((target-now)<0x80000000u)result=false; else result=true; } else result=(now-target)<0x80000000u; SetIRQInterruptState(state); return result; }
