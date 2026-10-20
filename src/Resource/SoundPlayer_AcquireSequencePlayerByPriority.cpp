#include <globaldefs.h>
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
struct Header{char pad[0x3d];unsigned char rank;};extern "C" Header* _ZN19SignedAllocatorList12ElementAfterEP21SignedAllocatorHeader(void*,Header*);extern "C" void _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(void*,Header*);extern "C" void ResourceEntry_StopHandleAndRelease(Header*);extern "C" void SoundPlayer_InsertSequenceByPriority(Header*);extern "C" char InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage[],SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage[];
#pragma optimization_level 4
// Original: arm9/main @ 0x020BC734; symbol: func_020bc734; size: 0x68.
extern "C" ARM Header* SoundPlayer_AcquireSequencePlayerByPriority(int rank){Header* p=_ZN19SignedAllocatorList12ElementAfterEP21SignedAllocatorHeader(InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage,0);if(!p){p=_ZN19SignedAllocatorList12ElementAfterEP21SignedAllocatorHeader(SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage,0);if(rank<p->rank)return 0;ResourceEntry_StopHandleAndRelease(p);}_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage,p);p->rank=rank;SoundPlayer_InsertSequenceByPriority(p);return p;}
