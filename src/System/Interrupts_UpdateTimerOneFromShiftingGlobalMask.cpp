#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" {
// Original data: arm9/main @ 0x214e4a0; symbol: data_0214e4a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D8694; symbol: func_020d8694; size: 0x3C.
void Interrupts_UpdateTimerOneFromShiftingGlobalMask(){if(GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[1]&1)EnableSpecificInterrupts(4);else DisableSpecificInterrupts(4);GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[1]>>=1;}
}
