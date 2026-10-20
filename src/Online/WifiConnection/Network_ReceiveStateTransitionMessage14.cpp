#include <globaldefs.h>
#include <System/ProcessorContext.h>
THUMB
#pragma opt_propagation off
struct Queue {BlockedContextList readers,writers;unsigned* data;int capacity,index,count;};
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(Queue*,unsigned*,unsigned);
extern "C" int Network_DisconnectQueueSession();
// Original data: arm9/ov031 @ 0x224f4e0; symbol: data_ov031_0224f4e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Queue NetworkSendQueueSessionEvent_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0221E92C; symbol: func_ov031_0221e92c; size: 0x38.
// Receives a queue message after advancing the protected state; returns zero for
// message 14 and -1 otherwise. Both observed loop branches terminate immediately.
extern "C" int Network_ReceiveStateTransitionMessage14() {
 int result=-1;
 if(Network_DisconnectQueueSession()){
  unsigned message;
  int again;
  do {
   MessageQueue_ReceiveWithOptionalBlocking(&NetworkSendQueueSessionEvent_UnknownRoleZeroInitializedStorage,&message,1);
   if(message==14){again=0;result=again;}else again=0;
  }while(again);
 }
 return result;
}
