#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" {
// Original data: arm9/main @ 0x2112780; symbol: data_02112780.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int SNDPushCommand_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D26EC; symbol: func_020d26ec; size: 0x2C.
unsigned int ReadSelectedGlobalValueUnderIRQProtection(){int old=DisableIRQInterrupts();unsigned int v;if(SNDPushCommand_UnknownRoleZeroInitializedStorage[2]==0)v=SNDPushCommand_UnknownRoleZeroInitializedStorage[1];else v=SNDPushCommand_UnknownRoleZeroInitializedStorage[8];SetIRQInterruptState(old);return v;}
}
