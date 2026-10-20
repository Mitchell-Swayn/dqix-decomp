#include <globaldefs.h>
ARM
#include <Memory/SignedAllocator.h>
// Original data: arm9/main @ 0x210f3d8; symbol: data_0210f3d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" SignedAllocatorList SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BC0A4; symbol: func_020bc0a4; size: 0x54.
extern "C" int CountAllocatorEntriesWithKindOneAndMatchingId(unsigned id){SignedAllocatorList* list;int count=0;SignedAllocatorHeader* entry=SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage.ElementAfter(0);if(entry){list=&SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage;do{char* p=(char*)entry;if(*(unsigned short*)(p+0x34)==1 && *(unsigned short*)(p+0x38)==id)++count;entry=list->ElementAfter(entry);}while(entry);}return count;}
