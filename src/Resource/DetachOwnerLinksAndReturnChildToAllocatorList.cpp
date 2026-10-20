#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x210f3cc; symbol: data_0210f3cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x210f3d8; symbol: data_0210f3d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(void*,void*);extern "C" void _ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(void*,void*);extern "C" unsigned char SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage[];extern "C" unsigned char InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020BC79C; symbol: func_020bc79c; size: 0x84.
extern "C" void DetachOwnerLinksAndReturnChildToAllocatorList(unsigned char* p){void** link=*(void***)p;if(link){*link=0;*(void**)p=0;}unsigned char* list=*(unsigned char**)(p+4);_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(list,p);*(void**)(p+4)=0;void* child=*(void**)(p+8);if(child){_ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(list+12,child);(*(void***)(p+8))[3]=0;*(void**)(p+8)=0;}_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage,p);_ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage,p);p[44]=0;}
