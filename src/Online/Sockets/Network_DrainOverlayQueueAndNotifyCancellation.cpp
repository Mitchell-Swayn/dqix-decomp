#include <globaldefs.h>
ARM
struct Queue;
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void*);
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" void _Z20AddContextSwitchLockv();
extern "C" void _Z23RemoveContextSwitchLockv();
extern "C" void _Z26SwitchContextUninterruptedv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(Queue*,unsigned*,unsigned);
extern "C" int OS_SendMessage(void*,void*,int);
extern "C" void Network_RecycleSocketCommand(void*);
// Original: arm9/ov031 @ 0x02206B68; symbol: func_ov031_02206b68; size: 0xA0.
extern "C" void Network_DrainOverlayQueueAndNotifyCancellation(char* self) {
if(!self) return;
_Z22AwaitContextCompletionP16ProcessorContext(self+0x20);
int irq=_Z20DisableIRQInterruptsv();
_Z20AddContextSwitchLockv();
unsigned message;
if(MessageQueue_ReceiveWithOptionalBlocking((Queue*)self,&message,0)) do {
if(message) {
void* queue=*(void**)(message+8);
if(queue) OS_SendMessage(queue,(void*)-11,0);
Network_RecycleSocketCommand((void*)message);
}
} while(MessageQueue_ReceiveWithOptionalBlocking((Queue*)self,&message,0));
_Z23RemoveContextSwitchLockv();
_Z26SwitchContextUninterruptedv();
_Z20SetIRQInterruptStatei(irq);
}
