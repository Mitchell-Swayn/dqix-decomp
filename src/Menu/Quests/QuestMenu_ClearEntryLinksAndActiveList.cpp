#include <globaldefs.h>
ARM
struct Entry { int a,b,value; };
struct State { Entry* arrays[2]; int count; unsigned char pad[0x3c]; short lengths[2];short total; };
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" State* FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x021660F4; symbol: func_ov004_021660f4; size: 0xA4.
extern "C" void QuestMenu_ClearEntryLinksAndActiveList() {
short i=0;
State* state=FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
Entry* arrays[2]={state->arrays[0],state->arrays[1]};
short lengths[2]={state->lengths[0],state->lengths[1]};
for(;i<2;++i){
Entry* entry=arrays[i];
short count=lengths[i];
for(short j=0;j<count;++j){entry->value=0;++entry;}
}
state->count=0;state->total=0;
}
