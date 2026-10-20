#include <globaldefs.h>
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
// Original data: arm9/ov003 @ 0x217f280; symbol: data_ov003_0217f280.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0f0a0c0800500000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" unsigned AlltradesAllocateVocationPreviewArena_UnknownRoleInitializedBytes[];
// Original: arm9/ov003 @ 0x021536E0; symbol: func_ov003_021536e0; size: 0x8C.
extern "C" ARM void Alltrades_AllocateVocationPreviewArena(unsigned char** output,void* allocator) { *output=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,20); unsigned sizes[1]; unsigned* sizeTable=sizes; sizes[0]=AlltradesAllocateVocationPreviewArena_UnknownRoleInitializedBytes[1]; for(unsigned char i=0;i<1;++i) { _ZN13SafeAllocator21ResetAllocatorPointerEv(*output+i*20); unsigned size=sizeTable[i]; void* memory=_ZN13SafeAllocator8AllocateEj(allocator,size); _ZN13SafeAllocator11CreateTypeAEPvj(*output+i*20,memory,size); } }
