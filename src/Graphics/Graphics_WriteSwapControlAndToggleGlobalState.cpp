#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x214e4a0; symbol: data_0214e4a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D86D0; symbol: func_020d86d0; size: 0x34.
void Graphics_WriteSwapControlAndToggleGlobalState(unsigned int a,unsigned int b){*(volatile unsigned int *)0x04000540=a|(b<<1);GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[0]=GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[0]==0?1:0;}
}
