#include <globaldefs.h>

// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *); extern "C" unsigned int Main_UnknownRoleZeroInitializedStorage_Variant3;
ARM
// Original: arm9/ov017 @ 0x021C2710; symbol: func_ov017_021c2710; size: 0x34.
extern "C" void Field_ReleaseOverlayTenAction(void *record) { void **resource=(void **)((unsigned char *)record+8); if(*resource) { Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,*resource); *resource=0; } *((unsigned char *)record+1)=1; }
