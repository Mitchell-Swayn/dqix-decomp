#include <globaldefs.h>
ARM
extern "C" void OS_InitMessageQueue(int*,int,int);
extern "C" void Network_RecycleSocketCommand(void*);
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkCleanupSocketStack_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x224e204; symbol: data_ov031_0224e204.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int NetworkRecycleSocketCommand_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224e200; symbol: data_ov031_0224e200.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkAllocateOverlayQueueRecords_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02205030; symbol: func_ov031_02205030; size: 0x94.
extern "C" int Network_AllocateOverlayQueueRecords(int count) {
unsigned indexBytes=(count*4+3)&~3;
unsigned recordBytes=(count*0x2c+3)&~3;
char* block=(*(char*(**)(unsigned))(NetworkCleanupSocketStack_UnknownRoleInitializedBytes+0x18))(recordBytes+indexBytes);
if(!block) return -1;
OS_InitMessageQueue(NetworkRecycleSocketCommand_UnknownRoleZeroInitializedStorage,(int)block,count);
char* record=block+indexBytes;
if(count>0) do {
Network_RecycleSocketCommand(record);
--count;
record+=0x2c;
} while(count>0);
NetworkAllocateOverlayQueueRecords_UnknownRoleZeroInitializedStorage=block;
return 0;
}
