#include <globaldefs.h>
ARM
struct StatusSlot {int value;int pad;};struct ObjectSlot{void* value;int pad;};
struct Ring {unsigned head,tail;};
extern "C" {extern Ring data_ov031_022919bc;extern StatusSlot data_ov031_022919c4[];extern ObjectSlot data_ov031_022919c8[];void Overlay_WaitForStatusToLeaveMinusTwentySix(void*,int);void Util_InvokeObjectCallbacks(void*);}
// Original: arm9/ov031 @ 0x0224175C; symbol: func_ov031_0224175c; size: 0xA0.
extern "C" void QueueOwnedObjectInEightSlotRing(int status,void** object){
unsigned next=(data_ov031_022919bc.head+1)&7;
if(next==data_ov031_022919bc.tail){
Overlay_WaitForStatusToLeaveMinusTwentySix(0,data_ov031_022919c4[data_ov031_022919bc.tail].value);
Util_InvokeObjectCallbacks(data_ov031_022919c8[data_ov031_022919bc.tail].value);
data_ov031_022919bc.tail=(data_ov031_022919bc.tail+1)&7;
}
if(!*object)return;
unsigned head=data_ov031_022919bc.head;
data_ov031_022919c4[head].value=status;
data_ov031_022919c8[head].value=*object;
*object=0;data_ov031_022919bc.head=next;
}
