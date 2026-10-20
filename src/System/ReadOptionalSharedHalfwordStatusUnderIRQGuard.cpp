#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" {
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char *WMiCheckIdle_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D46CC; symbol: func_020d46cc; size: 0x30.
unsigned int ReadOptionalSharedHalfwordStatusUnderIRQGuard(){int old=DisableIRQInterrupts();char *p=WMiCheckIdle_UnknownRoleZeroInitializedStorage[1];unsigned int v;if(p)v=*(unsigned short *)(p+0x150);else v=0;SetIRQInterruptState(old);return v;}
}
