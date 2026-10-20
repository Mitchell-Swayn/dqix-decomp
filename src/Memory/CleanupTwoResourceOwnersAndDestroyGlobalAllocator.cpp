#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" {
// Original data: arm9/main @ 0x2153694; symbol: data_02153694.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char TextLookupStandardString_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2153680; symbol: data_02153680.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern SafeAllocator AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
void CancelOwnerTaskAndResetEmbeddedState(void *);
void Memory_FreeThroughAllocatorUnion(void *,void *);
// Original: arm9/main @ 0x020E5094; symbol: func_020e5094; size: 0x58.
void CleanupTwoResourceOwnersAndDestroyGlobalAllocator() {
    for (int i=0; i<2; i++) CancelOwnerTaskAndResetEmbeddedState(TextLookupStandardString_UnknownRoleZeroInitializedStorage+i*24);
    SignedAllocatorHeader *allocation = AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage.GetSignedAllocator();
    if (!allocation) return;
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage.Destroy();
}
}
