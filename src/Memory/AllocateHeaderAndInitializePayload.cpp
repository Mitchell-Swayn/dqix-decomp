#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <Memory/SignedAllocator.h>
extern "C" char* ResourceAllocator_AllocateTrackedAlignedBlock(unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned ResourceAllocator_CreateAlignedHeapRegion(char*,unsigned);
extern "C" void Memory_FinalizeAndUnlinkAllocatorHeader();
// Original data: arm9/main @ 0x210f824; symbol: data_0210f824.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020BBF84; symbol: func_020bbf84; size: 0x94.
extern "C" int AllocateHeaderAndInitializePayload(int index,unsigned allocator,unsigned size) {
    char* allocation=ResourceAllocator_AllocateTrackedAlignedBlock(allocator,size+20,(unsigned)Memory_FinalizeAndUnlinkAllocatorHeader,0,0);
    if (!allocation) return 0;
    *(unsigned*)(allocation+12)=0;
    *(int*)(allocation+16)=index;
    *(unsigned*)(allocation+8)=0;
    unsigned value=ResourceAllocator_CreateAlignedHeapRegion(allocation+20,size);
    if (!value) return 0;
    char* list=AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage+index*36;
    *(unsigned*)(allocation+8)=value;
    ((SignedAllocatorList*)(list+12))->InsertAtEnd((SignedAllocatorHeader*)allocation);
    return 1;
}
