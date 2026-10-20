#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
// Original data: arm9/main @ 0x210f3d8; symbol: data_0210f3d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" SignedAllocatorList SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BC6A8; symbol: func_020bc6a8; size: 0x54.
extern "C" ARM void SoundPlayer_InsertSequenceByPriority(SignedAllocatorHeader* what){SignedAllocatorHeader* p=SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage.ElementAfter(0);if(p){SignedAllocatorList* list=&SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage;do{if(((unsigned char*)what)[0x3d]<((unsigned char*)p)[0x3d])break;p=list->ElementAfter(p);}while(p);}SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage.InsertBefore(p,what);}
