#include <globaldefs.h>
ARM
#include <System/ProcessorContext.h>
struct Queue;
extern "C" int OS_SendMessage(void* queue, void* message, int flags);
extern "C" int PrependBlockingQueueItemUnderIRQProtection(Queue* self,unsigned value,unsigned flags);
extern "C" int Queue_PeekValueWithOptionalBlockingAndIRQGuard(Queue* q,unsigned* out,unsigned flags);
extern "C" short data_ov031_0224c954[];
extern "C" int data_ov031_02291f24[];
extern "C" BlockedContextList data_ov031_02291f3c;
extern "C" unsigned char data_ov031_02291f60[];
// Original: arm9/ov031 @ 0x02245E5C; symbol: func_ov031_02245e5c; size: 0x14C.
extern "C" void System_DispatchOverlayQueueEvent(short* event) {
 if (data_ov031_0224c954[1] != event[0] || data_ov031_0224c954[0] != event[1]) {
 data_ov031_0224c954[1] = event[0]; data_ov031_0224c954[0] = event[1];
 }
 switch(event[0]) {
 case 1: data_ov031_02291f24[4] = 0;
 case 2: case 3: case 4: case 5: case 9:
 data_ov031_02291f24[2] = event[1]; UnblockContexts(&data_ov031_02291f3c); break;
 case 6:
 if (data_ov031_02291f24[6]) { data_ov031_02291f24[2]=event[1]; UnblockContexts(&data_ov031_02291f3c); }
 else if (event[1]==0) OS_SendMessage(data_ov031_02291f60,(void*)2,0);
 else PrependBlockingQueueItemUnderIRQProtection((Queue*)data_ov031_02291f60,3,0);
 break;
 case 7:
 if(event[1]==0) { unsigned value; if(!Queue_PeekValueWithOptionalBlockingAndIRQGuard((Queue*)data_ov031_02291f60,&value,0)) OS_SendMessage(data_ov031_02291f60,(void*)1,0); }
 else PrependBlockingQueueItemUnderIRQProtection((Queue*)data_ov031_02291f60,3,0);
 break;
 case 8: data_ov031_02291f24[4]++; break;
 }
}
