#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
// Original data: arm9/main @ 0x210f3d8; symbol: data_0210f3d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern SignedAllocatorList SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage;
extern "C" void InsertAllocatorEntryByByteRank(SignedAllocatorList*,SignedAllocatorHeader*); extern "C" void SoundPlayer_InsertSequenceByPriority(SignedAllocatorHeader*);
// Original: arm9/main @ 0x020BC870; symbol: func_020bc870; size: 0x60.
extern "C" void ChangeEntryRankAndReinsertInOwnerList(SignedAllocatorHeader* p,unsigned char rank) { SignedAllocatorList* parent=*(SignedAllocatorList**)((char*)p+4); if(parent){parent->Remove(p); *(SignedAllocatorList**)((char*)p+4)=0;} SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage.Remove(p); *((unsigned char*)p+61)=rank; if(parent)InsertAllocatorEntryByByteRank(parent,p); SoundPlayer_InsertSequenceByPriority(p); }
