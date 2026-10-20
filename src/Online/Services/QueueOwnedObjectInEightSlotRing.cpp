#include <globaldefs.h>
ARM
struct StatusSlot {int value;int pad;};struct ObjectSlot{void* value;int pad;};
struct Ring {unsigned head,tail;};
// Original data: arm9/ov031 @ 0x22919bc; symbol: data_ov031_022919bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22919c4; symbol: data_ov031_022919c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22919c8; symbol: data_ov031_022919c8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 60 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern Ring HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3;extern StatusSlot QueueOwnedObjectInEightSlotRing_UnknownRoleZeroInitializedStorage[];extern ObjectSlot QueueOwnedObjectInEightSlotRing_UnknownRoleZeroInitializedStorage_Variant2[];void Http_CloseSocketAndWait(void*,int);void Util_InvokeObjectCallbacks(void*);}
// Original: arm9/ov031 @ 0x0224175C; symbol: func_ov031_0224175c; size: 0xA0.
extern "C" void QueueOwnedObjectInEightSlotRing(int status,void** object){
unsigned next=(HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3.head+1)&7;
if(next==HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3.tail){
Http_CloseSocketAndWait(0,QueueOwnedObjectInEightSlotRing_UnknownRoleZeroInitializedStorage[HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3.tail].value);
Util_InvokeObjectCallbacks(QueueOwnedObjectInEightSlotRing_UnknownRoleZeroInitializedStorage_Variant2[HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3.tail].value);
HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3.tail=(HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3.tail+1)&7;
}
if(!*object)return;
unsigned head=HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3.head;
QueueOwnedObjectInEightSlotRing_UnknownRoleZeroInitializedStorage[head].value=status;
QueueOwnedObjectInEightSlotRing_UnknownRoleZeroInitializedStorage_Variant2[head].value=*object;
*object=0;HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage_Variant3.head=next;
}
