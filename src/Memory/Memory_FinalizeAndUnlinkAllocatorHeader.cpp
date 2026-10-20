#include <globaldefs.h>
// Original data: arm9/main @ 0x210f824; symbol: data_0210f824.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Header{int a,b;void* allocation;Header* parent;unsigned index;};extern "C" void FinalizeOwnerAndRemoveFromAllocatorTree(void*);extern "C" void _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(void*,Header*);extern "C" char AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage[];
#pragma optimization_level 4
// Original: arm9/main @ 0x020BC820; symbol: func_020bc820; size: 0x50.
extern "C" ARM void Memory_FinalizeAndUnlinkAllocatorHeader(Header* p){if(!p->allocation)return;FinalizeOwnerAndRemoveFromAllocatorTree(p->allocation);if(p->parent){p->parent->allocation=0;return;}_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(AllocateHeaderAndInitializePayload_UnknownRoleZeroInitializedStorage+p->index*36+12,p);}
