#include <globaldefs.h>

// Original data: arm9/ov017 @ 0x21d8474; symbol: data_ov017_021d8474.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void LinkedQueue_InitializeNodeStatus(unsigned int *); extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *); extern "C" unsigned int PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage;
ARM
// Original: arm9/ov017 @ 0x021C0124; symbol: func_ov017_021c0124; size: 0x3C.
extern "C" void PartyTransition_InitializeDialogueRequest(void *record, unsigned char value) { unsigned char *p=(unsigned char *)record; LinkedQueue_InitializeNodeStatus((unsigned int *)record); p[0]=0x20; _ZN13SafeAllocator21ResetAllocatorPointerEv(p+8); PartyTransitionUpdateDialogueRequest_UnknownRoleZeroInitializedStorage=0; *(unsigned int *)(p+0x1c)=0; p[0x20]=value; }
