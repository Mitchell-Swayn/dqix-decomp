#include <globaldefs.h>
ARM
#include <System/ProcessorContext.h>
struct Queue;
extern "C" int OS_SendMessage(void* queue, void* message, int flags);
extern "C" int PrependBlockingQueueItemUnderIRQProtection(Queue* self,unsigned value,unsigned flags);
extern "C" int Queue_PeekValueWithOptionalBlockingAndIRQGuard(Queue* q,unsigned* out,unsigned flags);
// Original data: arm9/ov031 @ 0x224c954; symbol: data_ov031_0224c954.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffff00000000000030000000030000000000000000000000000000000000000000000000000000000000.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" short SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2291f24; symbol: data_ov031_02291f24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2291f3c; symbol: data_ov031_02291f3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" BlockedContextList SystemDispatchOverlayQueueEvent_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2291f60; symbol: data_ov031_02291f60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x02245E5C; symbol: func_ov031_02245e5c; size: 0x14C.
extern "C" void System_DispatchOverlayQueueEvent(short* event) {
 if (SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes[1] != event[0] || SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes[0] != event[1]) {
 SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes[1] = event[0]; SystemDispatchOverlayQueueEvent_UnknownRoleInitializedBytes[0] = event[1];
 }
 switch(event[0]) {
 case 1: WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[4] = 0;
 case 2: case 3: case 4: case 5: case 9:
 WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[2] = event[1]; UnblockContexts(&SystemDispatchOverlayQueueEvent_UnknownRoleZeroInitializedStorage); break;
 case 6:
 if (WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[6]) { WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[2]=event[1]; UnblockContexts(&SystemDispatchOverlayQueueEvent_UnknownRoleZeroInitializedStorage); }
 else if (event[1]==0) OS_SendMessage(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2,(void*)2,0);
 else PrependBlockingQueueItemUnderIRQProtection((Queue*)WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2,3,0);
 break;
 case 7:
 if(event[1]==0) { unsigned value; if(!Queue_PeekValueWithOptionalBlockingAndIRQGuard((Queue*)WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2,&value,0)) OS_SendMessage(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2,(void*)1,0); }
 else PrependBlockingQueueItemUnderIRQProtection((Queue*)WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage_Variant2,3,0);
 break;
 case 8: WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[4]++; break;
 }
}
