#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x210f3e4; symbol: data_0210f3e4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1088 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Entry{unsigned char pad[0x2c];unsigned char active;unsigned char tail[0x17];};extern "C" {extern Entry InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage_Variant2[];void ResourceEntry_SetTimedStatusOrRelease(Entry*,int);
// Original: arm9/main @ 0x020BC028; symbol: func_020bc028; size: 0x40.
void ResourceManager_UpdateSixteenActiveEntries(int value){int i;Entry* p=InitializeTwoAllocatorListsAndSixteenSlots_UnknownRoleZeroInitializedStorage_Variant2;i=0;do{if(p->active)ResourceEntry_SetTimedStatusOrRelease(p,value);i++;p++;}while(i<16);}}
