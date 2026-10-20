#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
#include <System/Interrupts.h>
// Original data: arm9/main @ 0x21103bc; symbol: data_021103bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" SignedAllocatorList NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/main @ 0x020BF418; symbol: func_020bf418; size: 0x40.
extern "C" ARM SignedAllocatorHeader* RemoveFirstGlobalAllocatorEntryUnderIRQProtection(){int state=DisableIRQInterrupts();SignedAllocatorHeader* p=NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant2.ElementAfter(0);if(p)NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant2.Remove(p);SetIRQInterruptState(state);return p;}
