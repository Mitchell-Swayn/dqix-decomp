#include <globaldefs.h>
ARM
struct Node { unsigned a,b; unsigned* records; unsigned char count; };
struct Pool { char pad[0x224];void* allocator; };
// Original data: arm9/ov031 @ 0x2290d28; symbol: data_ov031_02290d28.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_UnlinkListNode(void*);
extern "C" void PushPointerIntoInterruptProtectedRing(void*,void*);
// Original: arm9/ov031 @ 0x0223BA20; symbol: func_ov031_0223ba20; size: 0x80.
extern "C" void Network_UnlinkNodeAndReleaseRecords(Node* node) {
int group=0;
unsigned* records=node->records;
int i=0;
if((int)node->count>0) do {
*records=(*records&0xc1fffcff)|0x200;
records+=2;
++i;
} while(i<node->count);
WfcUtility_UnlinkListNode(node);
if((unsigned)node>=(unsigned)(WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage+0x228)) group=1;
Pool* pool=(Pool*)WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage;
PushPointerIntoInterruptProtectedRing(pool[group].allocator,node);
}
