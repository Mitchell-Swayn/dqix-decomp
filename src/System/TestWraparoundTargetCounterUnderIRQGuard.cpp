#include <globaldefs.h>
#include <System/Interrupts.h>
// Original data: arm9/main @ 0x2112780; symbol: data_02112780.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned SNDPushCommand_UnknownRoleZeroInitializedStorage[2];
// Original: arm9/main @ 0x020D2718; symbol: func_020d2718; size: 0x50.
extern "C" bool TestWraparoundTargetCounterUnderIRQGuard(unsigned target) { int state=DisableIRQInterrupts(); unsigned now=SNDPushCommand_UnknownRoleZeroInitializedStorage[1]; bool result; if(target>now){ if((target-now)<0x80000000u)result=false; else result=true; } else result=(now-target)<0x80000000u; SetIRQInterruptState(state); return result; }
