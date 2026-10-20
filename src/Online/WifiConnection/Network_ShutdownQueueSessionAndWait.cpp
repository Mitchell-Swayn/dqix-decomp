#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f4c0; symbol: data_ov031_0224f4c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224f4e0; symbol: data_ov031_0224f4e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern unsigned AossAllocateBuffer_UnknownRoleZeroInitializedStorage[];extern char NetworkSendQueueSessionEvent_UnknownRoleZeroInitializedStorage[];int Network_BeginQueueSessionShutdown();ARM int MessageQueue_ReceiveWithOptionalBlocking(void*,unsigned*,unsigned);int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);}
THUMB
// Original: arm9/ov031 @ 0x0221E894; symbol: WaitForSharedCallbackShutdown; size: 0x98.
// Waits for queue callback shutdown message20, tolerates messages4/5 and clears callback atomically.
extern "C" int Network_ShutdownQueueSessionAndWait(){int waiting=1,result=-1;if(!AossAllocateBuffer_UnknownRoleZeroInitializedStorage[3])return result;if(!Network_BeginQueueSessionShutdown())return -1;do{unsigned message;MessageQueue_ReceiveWithOptionalBlocking(NetworkSendQueueSessionEvent_UnknownRoleZeroInitializedStorage,&message,1);switch(message){case 4:case 5:break;case 20:waiting=0;result=0;((void(*)(unsigned))AossAllocateBuffer_UnknownRoleZeroInitializedStorage[3])(AossAllocateBuffer_UnknownRoleZeroInitializedStorage[2]);break;case 0:case 1:case 2:case 3:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:default:waiting=0;break;}}while(waiting);int irq=_Z20DisableIRQInterruptsv();AossAllocateBuffer_UnknownRoleZeroInitializedStorage[0]=0;AossAllocateBuffer_UnknownRoleZeroInitializedStorage[3]=0;_Z20SetIRQInterruptStatei(irq);return result;}
