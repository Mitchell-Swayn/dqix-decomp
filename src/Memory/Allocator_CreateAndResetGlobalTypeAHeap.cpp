#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2153680; symbol: data_02153680.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage[];extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void _ZN13SafeAllocator5ResetEv(void*);
// Original: arm9/main @ 0x020E50EC; symbol: func_020e50ec; size: 0x28.
extern "C" void Allocator_CreateAndResetGlobalTypeAHeap(void* p,unsigned size){_ZN13SafeAllocator11CreateTypeAEPvj(AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage,p,size);_ZN13SafeAllocator5ResetEv(AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage);}
