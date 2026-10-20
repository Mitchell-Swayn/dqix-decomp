#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
extern "C" {
// Original data: arm9/main @ 0x210f3d8; symbol: data_0210f3d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern SignedAllocatorList SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020BC0F8; symbol: func_020bc0f8; size: 0x60.
unsigned int CountAllocatorNodesWithKindTwoAndTwoMatchingHalfwords(int a,int b){unsigned int count=0;SignedAllocatorHeader *p=SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage.ElementAfter(0);if(p)do{unsigned short *q=(unsigned short *)p;if(q[26]==2&&q[28]==a&&q[29]==b)count++;p=SoundPlayerInsertSequenceByPriority_UnknownRoleZeroInitializedStorage.ElementAfter(p);}while(p);return count;}
}
