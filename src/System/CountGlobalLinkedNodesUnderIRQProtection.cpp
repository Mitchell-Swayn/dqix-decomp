#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Interrupts.h>
extern "C" {
// Original data: arm9/main @ 0x2112780; symbol: data_02112780.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern void **SNDPushCommand_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D27A4; symbol: func_020d27a4; size: 0x3C.
unsigned int CountGlobalLinkedNodesUnderIRQProtection(){int state=DisableIRQInterrupts();unsigned int count=0;void **p=SNDPushCommand_UnknownRoleZeroInitializedStorage[2];if(p)do{p=(void **)*p;count++;}while(p);SetIRQInterruptState(state);return count;}
}
